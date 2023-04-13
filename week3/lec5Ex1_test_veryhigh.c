#include <stdio.h>
#include <math.h>
#include "lec5Ex1_veryhigh.h"

int main () {
  const int    samples=1800;
  FILE         *oFile;

  int inp, output;
  int coef[N] = {0,-10,-9,23,56,63,56,23,-9,-10,-10,-9,23,56,63,56,23,-9,-10,-10,-9,23,56,63,56,23,-9,-10,56,63,56,23,0,};

  int i, rmp;
  inp = 0;
  rmp = 1;
  
  oFile=fopen("lec5Ex1_out.dat","w");
  for (i=0;i<=samples;i++) {
  	if (rmp == 1) 
  		inp = inp + 1;
  	else 
  		inp = inp - 1;

	// Execute the function with latest input
    lec5Ex1(&output,coef,inp);
    
    if ((rmp == 1) && (inp >= 75))
    	rmp = 0;
    else if ((rmp == 0) && (inp <= -75))
    	rmp = 1;
    	
	// Save the results.
    fprintf(oFile,"%i %d %d\n",i,inp,output);
  }
  fclose(oFile);
  
  printf ("Comparing against output data \n");
  if (system("diff -w lec5Ex1_out.dat lec5Ex1_out_veryhigh_ref.dat")) {

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
