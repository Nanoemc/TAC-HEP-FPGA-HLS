#include "lec6Ex2a.h"

void lec6Ex2a (
  ap_uint<8> in[NN],
  ap_uint<2> a,
  ap_uint<2> b,
  ap_uint<2> c,
  ap_uint<8> out[KK]
  ) {

#pragma HLS ARRAY_PARTITION variable=in complete dim=0
#pragma HLS ARRAY_PARTITION variable=out complete dim=0

   ap_uint<8> x, y;
   ap_uint<8> tmp;

Loop_j:for(ap_uint<2> j=0; j < MM; j++){
#pragma LOOP UNROLL
	 tmp = b*in[j];

Loop_i:for (ap_uint<5> i=0 ; i < NN; i++) {
#pragma LOOP UNROLL
	ap_uint<7> k = i+j*NN;
	x = in[i];
	y = a*x + tmp + squared(c);
	out[k] = y;
      }
   }
}

ap_uint<8> squared(ap_uint<8> a)
{
#pragma HLS INLINE
  ap_uint<8> res = 0;
  res = a*a;
  return res;
}
