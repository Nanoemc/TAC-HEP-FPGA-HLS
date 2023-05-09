#include "lec9Ex1.h"
#include <stdlib.h>


int main () {

  unsigned int input[N];
  unsigned int output[N];

  short a = 2;
  short b = 3;
  unsigned int c = 5;


  for(int irnd=0; irnd<N; irnd++){
    input[irnd] = rand() % 20;
    output[irnd] = 0;
    printf("%i, input: %u", irnd, input[irnd]);
  }


  // Execute the function with latest input
  lec9Ex1(input, a, b, c, output);

  for(int i=0; i<N; i++){
    printf("%i %u %u\n",i,input[i],output[i]);
  }
  return 0;
}
