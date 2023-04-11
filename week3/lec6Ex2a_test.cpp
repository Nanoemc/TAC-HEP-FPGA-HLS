#include "lec6Ex2a.h"
#include <stdlib.h>

int main () {
  FILE         *oFile;

  ap_uint<8> input[NN] = {4, 7, 18, 16, 14, 16, 7, 13, 10, 2, 3, 8, 11, 20, 4, 7, 1, 7, 13, 17, 12, 9, 8, 10, 3, 11, 3, 4, 8, 16};
  ap_uint<8> output[KK];

  ap_uint<2> a = 2;
  ap_uint<2> b = 2;
  ap_uint<2> c = 2;


  printf("--------------\n");
  for(int irnd=0; irnd<NN; irnd++){
    printf("%i, input: %u\n", irnd, input[irnd]);
  }
  for(int p=0; p<KK; p++){
    output[p] = 0;
  }
  printf("--------------\n");

  oFile=fopen("lec6Ex2a_out.dat","w");

  // Execute the function with latest input
  lec6Ex2a(input, a, b, c, output);

  for(int i=0; i<MM; i++){
    for(int j=0; j<NN; j++){
      int k = j+i*NN;
      fprintf(oFile,"%i %u %u\n",k,input[j],output[k]);
    }  
  }
  fclose(oFile);

printf ("Comparing against output data \n");
if (system("diff -w lec6Ex2a_out.dat lec6Ex2a_out_ref.dat")) {

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
