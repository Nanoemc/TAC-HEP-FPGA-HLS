#include "lec6Ex2.h"
#include <stdlib.h>

int main () {
  FILE         *oFile;

  unsigned int input[NN];
  unsigned int output[KK];

  char a = 2;
  char b = 2;
  unsigned int c = 2;


  printf("--------------\n");
  for(int irnd=0; irnd<NN; irnd++){
    input[irnd] = rand() % 20 + 1;
    printf("%i, input: %u\n", irnd, input[irnd]);
  }
  for(int p=0; p<KK; p++){
    output[p] = 0;
  }
  printf("--------------\n");

  oFile=fopen("lec6Ex2_out.dat","w");

  // Execute the function with latest input
  lec6Ex2(input, a, b, c, output);

  for(int i=0; i<MM; i++){
    for(int j=0; j<NN; j++){
      int k = j+i*NN;
      fprintf(oFile,"%i %u %u\n",k,input[j],output[k]);
    }  
  }
  fclose(oFile);

printf ("Comparing against output data \n");
if (system("diff -w lec6Ex2_out.dat lec6Ex2_out_ref.dat")) {

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
