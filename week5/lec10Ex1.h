  
  #ifndef _LEC10EX1_H_
  #define _LEC10EX1_H_
  
  #include <stdio.h>
  #include "ap_cint.h"
  
  #define N 9
  //#define __NO_SYNTH__
  
  // Old data types
  #ifdef __NO_SYNTH__
  typedef char         dinA_t;
  typedef short        dinB_t;
  typedef int          dinC_t;
  typedef long long    dinD_t;
  typedef int          dout1_t;
  typedef unsigned int dout2_t;
  typedef long         dout3_t;
  typedef long long    dout4_t;
  
  #else
  typedef int6  dinA_t;
  typedef int12 dinB_t;
  typedef int22 dinC_t;
  typedef int33 dinD_t;
  
  typedef int18  dout1_t;
  typedef uint13 dout2_t;
  typedef int22  dout3_t;
  typedef int6   dout4_t;
  #endif
  
  void apint_arith(
      dinA_t inA,
      dinB_t inB,
      dinC_t inC,
      dinD_t inD,
      dout1_t *out1,
      dout2_t *out2,
      dout3_t *out3,
      dout4_t *out4
      );
  
  #endif
  
