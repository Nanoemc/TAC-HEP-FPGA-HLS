#include "lec6Ex1.h"
#include <stdlib.h>

int main () {
  FILE         *oFile;

  unsigned int input[N];
  unsigned int output[N];

  char a = 2;
  char b = 3;
  unsigned int c = 5;


  for(int irnd=0; irnd<N; irnd++){
    input[irnd] = rand() % 20;
    output[irnd] = 0;
    printf("%i, input: %u", irnd, input[irnd]);
  }

  oFile=fopen("lec6Ex1_out.dat","w");

  // Execute the function with latest input
  lec6Ex1(input, a, b, c, output);

  for(int i=0; i<N; i++){
    fprintf(oFile,"%i %u %u\n",i,input[i],output[i]);
  }
  fclose(oFile);

  printf ("Comparing against output data \n");
  if (system("diff -w lec6Ex1_out.dat lec6Ex1_out_ref.dat")) {

    fprintf(stdout, "*******************************************\n");
    fprintf(stdout, "FAIL: Output DOES NOT match the reference output\n");
    fprintf(stdout, "*******************************************\n");
    return 1;
  } else {
    fprintf(stdout, "*******************************************\n");
    fprintf(stdout, "PASS: The output matches the reference output!\n");
    fprintf(stdout, "*******************************************\n");
    return 0;
  }
}
