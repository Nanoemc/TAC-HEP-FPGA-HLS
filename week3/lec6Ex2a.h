#ifndef LEC6EX2_H_
#define LEC6EX2_H_

#include <stdio.h>
#include <math.h>
#include "ap_int.h"

#define NN  30
#define MM  3
#define KK  90

void lec6Ex2a(
  ap_uint<8> in[NN],
  ap_uint<2> a,
  ap_uint<2> b,
  ap_uint<2> c,
  ap_uint<8> out[KK]
  );

ap_uint<8> squared(ap_uint<8> );

#endif
