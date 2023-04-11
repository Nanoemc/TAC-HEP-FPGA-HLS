#include "lec6Ex2.h"

void lec6Ex2 (
  unsigned int in[NN],
  char a,
  char b,
  unsigned int c,
  unsigned int out[KK]
  ) {

   unsigned int x, y;
   unsigned int tmp;

Loop_j:for(unsigned int j=0; j < MM; j++){
	 tmp = b*in[j];
Loop_i:for (unsigned int i=0 ; i < NN; i++) {
	unsigned int k = i+j*NN;
	x = in[i];
	y = a*x + tmp + squared(c);
	out[k] = y;
      }
   }
}

unsigned int squared(unsigned int a)
{
  unsigned int res = 0;
  res = a*a;
  return res;
}
