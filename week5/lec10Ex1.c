  
  #include "lec10Ex1.h"
  
  void lec10Ex1(
      dinA_t  inA, 
      dinB_t  inB, 
      dinC_t  inC, 
      dinD_t  inD,
      dout1_t *out1, 
      dout2_t *out2, 
      dout3_t *out3, 
      dout4_t *out4
      ) {
  
    dinA_t inE = 5;
    dinB_t inF = 10;
    dinC_t inG = 23;
    dinD_t inH = 13;
    dout1_t out5 = inE * inF;
    dout2_t out6 = inG + inH;
    dout2_t out7 = inG / inH;
  
  
    // Basic arithmetic operations
    *out1 = inA * inB;
    *out2 = inB + inA;
    *out3 = inC / inA;
    *out4 = inD % inA;
  
  } 
  

