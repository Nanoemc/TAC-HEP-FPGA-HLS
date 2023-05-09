

uint16_t getPeakBinOf5(uint16_t et[5], uint16_t etSum) {
  uint16_t iEtSum =
    (et[0] >> 1)                +  // 0.5xet[0]
    (et[1] >> 1) + et[1]        +  // 1.5xet[1]
    (et[2] >> 1) + (et[2] << 1) +  // 2.5xet[2]
    (et[3] << 2) - (et[3] >> 1) +  // 3.5xet[3]
    (et[4] << 2) + (et[4] >> 1) ;  // 4.5xet[4]
  uint16_t iAve = 0xBEEF;
  if(     iEtSum <= etSum) iAve = 0;
  else if(iEtSum <= (etSum << 1)) iAve = 1;
  else if(iEtSum <= (etSum + (etSum << 1))) iAve = 2;
  else if(iEtSum <= (etSum << 2)) iAve = 3;
  else iAve = 4;
  return iAve;
}


bool getClustersInTower(uint16_t crystals[NCrystalsPerEtaPhi][NCrystalsPerEtaPhi],
    uint16_t *peakEta,
    uint16_t *peakPhi,
    uint16_t *towerET,
    uint16_t *clusterET) {


  uint16_t phiStripSum[NCrystalsPerEtaPhi];

  for(int phi = 0; phi < NCrystalsPerEtaPhi; phi++) {

    phiStripSum[phi] = 0;
    for(int eta = 0; eta < NCrystalsPerEtaPhi; eta++) {

      phiStripSum[phi] += crystals[eta][phi];
    }
  }
  uint16_t etaStripSum[NCrystalsPerEtaPhi];

  for(int eta = 0; eta < NCrystalsPerEtaPhi; eta++) {

    etaStripSum[eta] = 0;
    for(int phi = 0; phi < NCrystalsPerEtaPhi; phi++) {

      etaStripSum[eta] += crystals[eta][phi];
    }
  }
  // Large cluster ET is the ET of the full tower
  *towerET = 0;
  for(int phi = 0; phi < NCrystalsPerEtaPhi; phi++) {

    *towerET += phiStripSum[phi];
  }
  *peakEta = getPeakBinOf5(etaStripSum, *towerET);
  *peakPhi = getPeakBinOf5(phiStripSum, *towerET);
  // Small cluster ET is just the 3x3 around the peak
  *clusterET = 0;
  for(int dEta = -1; dEta <= 1; dEta++) {

    for(int dPhi = -1; dPhi <= 1; dPhi++) {

      int phi = *peakPhi + dPhi;
      int eta = *peakEta + dEta;
      uint16_t thisCrystalET = 0;
      if(phi >= 0 && phi < NCrystalsPerEtaPhi) {
	if(eta >= 0 && eta < NCrystalsPerEtaPhi) {
	  thisCrystalET = crystals[eta][phi];
	}
      }
      *clusterET += thisCrystalET;
    }
  }
  return true;
}

bool mergeClusters(uint16_t ieta1, uint16_t iphi1, uint16_t itet1, uint16_t icet1,
    uint16_t ieta2, uint16_t iphi2, uint16_t itet2, uint16_t icet2,
    uint16_t *eta1, uint16_t *phi1, uint16_t *tet1, uint16_t *cet1,
    uint16_t *eta2, uint16_t *phi2, uint16_t *tet2, uint16_t *cet2) {
  // Check that the clusters are neighbors in eta or phi
  if((ieta1 == ieta2) || (iphi1 == iphi2)) {
    if(icet1 > icet2) {
      // Merge 2 in to 1, and set 2 to remnant energy centered in tower
      *eta1 = ieta1;
      *phi1 = iphi1;
      *cet1 = icet1 + icet2;
      *tet1 = itet1 + icet2;
      *eta2 = 2;
      *phi2 = 2;
      *cet2 = 0;
      *tet2 = itet2 - icet2;
    }
    else {
      // Merge 1 in to 2, and set 1 to remnant energy centered in tower
      *eta2 = ieta2;
      *phi2 = iphi2;
      *cet2 = icet2 + icet1;
      *tet2 = itet2 + icet1;
      *eta1 = 2;
      *phi1 = 2;
      *cet1 = 0;
      *tet1 = itet1 - icet1;
    }
  }
  else {
    *eta1 = ieta1;
    *phi1 = iphi1;
    *cet1 = icet1;
    *tet1 = itet1;
    *eta2 = ieta2;
    *phi2 = iphi2;
    *cet2 = icet2;
    *tet2 = itet2;
  }
  return true;
}

void stitchNeighbors(bool stitch, Tower Ai, Tower Bi, Tower &Ao, Tower &Bo) {
  // Check that the clusters are neigbhors in eta or phi                                                                                             
  bool etaStitch = (stitch == 0 && Ai.peak_eta() == 4 && Bi.peak_eta() == 0 && Ai.peak_phi() == Bi.peak_phi());                                      
  bool phiStitch = (stitch == 1 && Ai.peak_phi() == 4 && Bi.peak_phi() == 0 && Ai.peak_eta() == Bi.peak_eta());                                      

  if(etaStitch || phiStitch){                                                                                                                        
    ap_uint<12> cEtSum = Ai.cluster_et() + Bi.cluster_et();                                                                                         
    ap_uint<10> pegged_cEtSum = (cEtSum > 0x3FF) ? (ap_uint<10>)0x3FF : (ap_uint<10>) cEtSum;                                                       

    if(Ai.cluster_et() > Bi.cluster_et()){                                                                                                          
      // Merge 2 in to 1, and set 2 to remnant energy centered in tower                                                                            
      ap_uint<12> tEtSum = Ai.tower_et() + Bi.cluster_et();                                                                                        
      ap_uint<10> pegged_tEtSum = (tEtSum > 0x3FF) ? (ap_uint<10>)0x3FF : (ap_uint<10>) tEtSum;                                                    
      ap_uint<10> tEt_leftOver = Bi.tower_et() - Bi.cluster_et();                                                                                  

      Ao = Tower(pegged_cEtSum, pegged_tEtSum, Ai.peak_phi(), Ai.peak_eta(), Ai.peak_time(), Ai.hOe());                                            
      Bo = Tower(            0,  tEt_leftOver, Bi.peak_phi(), Bi.peak_eta(), Bi.peak_time(), Bi.hOe());                                            
    }
    else{
      // Merge 1 in to 2, and set 1 to remnant energy centered in tower                                                                            
      ap_uint<12> tEtSum = Bi.tower_et() + Ai.cluster_et();                                                                                        
      ap_uint<10> pegged_tEtSum = (tEtSum > 0x3FF) ? (ap_uint<10>)0x3FF : (ap_uint<10>) tEtSum;                                                    
      ap_uint<10> tEt_leftOver = Ai.tower_et() - Ai.cluster_et();                                                                                  
      Ao = Tower(            0,  tEt_leftOver, Ai.peak_phi(), Ai.peak_eta(), Ai.peak_time(), Ai.hOe());                                            
      Bo = Tower(pegged_cEtSum, pegged_tEtSum, Bi.peak_phi(), Bi.peak_eta(), Bi.peak_time(), Bi.hOe());                                            
    }                                                                                                                                               
  }
  else{
    Ao = Ai;
    Bo = Bi;
  }                                                                                                                                                  
}

