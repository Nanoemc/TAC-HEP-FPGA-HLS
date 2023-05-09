#include "lec13Ex1.h"

void lec13Ex1 (
  unsigned int in_arr[N],
  short a,
  short b,
  unsigned int c,
  unsigned int out_arr[N]
  ) {

#pragma HLS ARRAY_PARTITION variable=in_arr complete dim=0
#pragma HLS ARRAY_PARTITION variable=out_arr complete dim=0

   unsigned int x, y;
   unsigned int tmp1, tmp2, tmp3;

for_Loop: for (unsigned int i=0 ; i < N; i++) {
#pragma HLS UNROLL
	x = in_arr[i];
	tmp1 = func(1, 2);
	tmp2 = func(2, 3);
	tmp3 = func(1, 4);

	y = a*x + b + squared(c) + tmp1 + tmp2 + tmp3;

	out_arr[i] = y;
      }
}

unsigned int squared(unsigned int a)
{
#pragma HLS INLINE
  unsigned int res = 0;
  res = a*a;
  return res;
}

unsigned int func(short a, short b){

  unsigned int res;
  res= a*a;
  res= res*b*a;
  res= res + 3;

  return res;
}




