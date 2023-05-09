#include "lec9Ex3.h"

int main() {
  din_t A[N];
  dout_t B[N];

  int i, retval = 0;
  FILE *fp;

  for (i = 0; i < N; ++i) {
    A[i] = i;
  }
  // Save the results to a file
  fp = fopen("lec9Ex3_out.dat", "w");

  // Call the function
  lec9Ex3(A, B);
  for (i = 0; i < N; ++i) {
    fprintf(fp, "%d \n", B[i]);
  }
  fclose(fp);

  // Compare the results file with the golden results
  retval = system("diff --brief -w lec9Ex3_out.dat lec9Ex3_out_ref.dat");
  if (retval != 0) {
    printf("Test failed  !!!\n");
    retval = 1;
  } else {
    printf("Test passed !\n");
  }

  // Return 0 if the test passed
  return retval;
}

