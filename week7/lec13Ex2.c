#include "lec13Ex2.h"

void lec13Ex2 (
  unsigned int in_arr[N],
  short a,
  short b,
  unsigned int c,
  unsigned int out_arr[N]
  ) {

   unsigned int x, y;
   unsigned int tmp1, tmp2, tmp3;

for_Loop: for (unsigned int i=0 ; i < N; i++) {
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




