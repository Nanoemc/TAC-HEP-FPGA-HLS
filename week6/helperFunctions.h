#ifndef helperFunctions_hh
#define helperFunctions_hh

#include <stdint.h>

const uint16_t NCaloLayer1Cards = 18;

const uint16_t NCaloLayer1Eta = 17;
const uint16_t NCaloLayer1Phi = 4;
 
const uint16_t NCrystalsPerEtaPhi = 5;
 
const uint16_t NCrystalsInPhi = (NCaloLayer1Cards * NCaloLayer1Phi * NCrystalsPerEtaPhi);
const uint16_t NCrystalsInEta = (NCaloLayer1Eta * NCrystalsPerEtaPhi);


uint16_t getPeakBinOf5(uint16_t et[NCrystalsPerEtaPhi], uint16_t etSum);

bool getClustersInTower(uint16_t crystals[NCrystalsPerEtaPhi][NCrystalsPerEtaPhi],
    uint16_t *peakEta,
    uint16_t *peakPhi,
    uint16_t *largeClusterET,
    uint16_t *smallClusterET);

bool mergeClusters(uint16_t ieta1, uint16_t iphi1, uint16_t itet1, uint16_t icet1,
    uint16_t ieta2, uint16_t iphi2, uint16_t itet2, uint16_t icet2,
    uint16_t *eta1, uint16_t *phi1, uint16_t *tet1, uint16_t *cet1,
    uint16_t *eta2, uint16_t *phi2, uint16_t *tet2, uint16_t *cet2);

void stitchNeighbors(bool stitch, Tower Ai, Tower Bi, Tower &Ao, Tower &B);

#endif
