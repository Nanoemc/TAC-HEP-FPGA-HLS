
#include "lec9Ex1.h"

void lec9Ex1 (
  unsigned int in[N],
  short a,
  short b,
  unsigned int c,
  unsigned int out[N]
  ) {

   unsigned int x, y;
   unsigned int tmp1, tmp2, tmp3;

for_Loop: for (unsigned int i=0 ; i < N; i++) {

	x = in[i];
	tmp1 = func(1, 2);
	tmp2 = func(2, 3);
	tmp3 = func(1, 4);

	y = a*x + b + squared(c) + tmp1 + tmp2 + tmp3;

	out[i] = y;
      }

#ifndef __SYNTHESIS__
//Following code will be ignored for synthesis
	  FILE *f1; 
	  f1=fopen("out_temp","w");
	  for(unsigned int j=0 ; j < N; j++){
	      fprintf(f1,"%u\n",out[j]);
	  }
	  fclose(f1);
#endif
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




