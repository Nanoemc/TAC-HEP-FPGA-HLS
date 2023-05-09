#include "lec9Ex2.h"
 
int main () {
  din_t A[N];
	dout_t accum;
	
	int i, retval=0;
	FILE        *fp;

	for(i=0; i<N;++i) {
	  A[i]=i+200;
	}
	// Save the results to a file
	fp=fopen("lec9Ex2_out.dat","w");

	// Call the function
	for(i=0; i<N;++i) {
    accum = lec9Ex2(A,i);  
		fprintf(fp, "%lld \n", (long long)accum);
	}
	fclose(fp);

	// Compare the results file with the golden results
	retval = system("diff --brief -w lec9Ex2_out.dat lec9Ex2_out_ref.dat");
	if (retval != 0) {
		printf("Test failed  !!!\n"); 
		retval=1;
	} else {
		printf("Test passed !\n");
  }

	// Return 0 if the test passed
  return retval;
}

