#include "lec6Ex1.h"

void lec6Ex1 (
  unsigned int in[N],
  char a,
  char b,
  unsigned int c,
  unsigned int out[N]
  ) {

   unsigned int x, y;

for_Loop: for (unsigned int i=0 ; i < N; i++) {
	x = in[i];
	y = a*x + b + squared(c);
	out[i] = y;
      }
}

unsigned int squared(unsigned int a)
{
  unsigned int res = 0;
  res = a*a;
  return res;
}

//- void get_sqrt(float x, float *ret)
//- {
//-    *ret = sqrtf(x);
//- }
