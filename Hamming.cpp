#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "Hamming.h"

// create a random code a
void RandCode(int* a) {
    for (int i = 0; i < K; ++i)
        a[i] = rand() & 1;
}

// encode src into des, des = src * G
void Encode(const int* src, int* des) {
    memset(des, 0, N*sizeof(int));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < K; ++j) {
            des[i] ^= src[j] & G[j][i];
        }
    }
}

// simulate transmission, y = x + E(Eb_No)w;
void Trans(int* x, int* y, double* w, double Eb_No) {
    for (int i = 0; i < N; ++i)
        y[i] = (0.5/pow(10, Eb_No/10) * w[i] + x[i] >= 0.5) ? 1 : 0;
}

// decode src to des by syndrome decoder
void Decode(const int* src, int* des) {
    int r = 0;
    for (int i = 0; i < N-K; ++i) {
        for (int j = 0; j < N; ++j) {
            r ^= (src[j] & HT[j][i]) << (2-i);
        }
    }
    memcpy(des, src, N*sizeof(int));
    switch (r) {
        case 1: des[2] ^= 1; break;
        case 2: des[1] ^= 1; break;
        case 3: des[4] ^= 1; break;
        case 4: des[0] ^= 1; break;
        case 5: des[6] ^= 1; break;
        case 6: des[3] ^= 1; break;
        case 7: des[5] ^= 1; break;
    }
}

// count error bit
int getErrBit(const int* src, const int* des) {
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        if (src[i] != des[i])
            ans++;
    }
    return ans;
}

// check code
// 0 for src == des and 1 for src != des
int Check(const int*src, const int* des) {
    for (int i = 0; i < N; ++i) {
        if (src[i] != des[i])
            return 1;
    }
    return 0;
}


