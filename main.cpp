#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "RandNum.h"
#include "Hamming.h"

const int test_case = 1000000;

int main() {
    int code[K], x[N], y[N], reproduce[N];
    double w[N];
    int errbit;
    int errCode;

    CWHRandNum RandNum;
    RandNum.SetSeed(0);

    printf("Test case: %d\n", test_case);

    for (int i = 1; i < 10; ++i) {
        errbit = errCode = 0;
        for (int j = 0; j < test_case; ++j) {
            RandCode(code);  // create a random code
            Encode(code, x); // encode code into x   
            RandNum.Normal(w, N); // create Gaussian noise
            Trans(x, y, w, (double)i); // simulate transmission, y = x + w;
            Decode(y, reproduce);   // decode y to reproduce
            errbit += getErrBit(x, y);  // count error bit
            errCode += Check(x, reproduce); // count error code
        }
        printf("Eb/No(dB): %d\n", i);
        printf("BER: %.8f\n", 1.0*errbit/test_case/N);
        printf("SER: %.8f\n\n", 1.0*errCode/test_case);
    }
    system("pause");

    return 0;
}

