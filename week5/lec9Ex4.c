#include "lec9Ex4.h"

void lec9Ex4(din_t A[N], dout_t B[N]) {

    int i,j;
    dint_t acc;

    LOOP_I:for(i=0; i < 20; i++){
        acc = 0;
        LOOP_J: for(j=0; j < 20; j++){
#pragma HLS loop_flatten
            acc += A[j] * j;
        }
        if (i%2 == 0)
            B[i] = acc / 20;
        else
            B[i] = 0;
    }

}


