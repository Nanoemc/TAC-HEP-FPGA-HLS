#ifndef LEC10EX2_H_
#define LEC10EX2_H_

#include <stdio.h>
#include <math.h>
//#include <cmath>
//#include "hls_math.h"

#define N 60

void lec10Ex2 (
  unsigned int in[N],
  short a,
  short b,
  unsigned int c,
  unsigned int out[N]
  );

unsigned int squared(unsigned int );


unsigned int func(short a, short b);
#endif
