#ifndef HAMMING
#define HAMMING

const int N = 7;
const int K = 4;

const int G[K][N] = {
    {1, 1, 0, 1, 0, 0, 0},
    {0, 1, 1, 0, 1, 0, 0},
    {1, 1, 1, 0, 0, 1, 0},
    {1, 0, 1, 0, 0, 0, 1}
};

const int H[N-K][N] = {
    {1, 0, 0, 1, 0, 1, 1},
    {0, 1, 0, 1, 1, 1, 0},
    {0, 0, 1, 0, 1, 1, 1}
};

const int HT[N][N-K] = {
    {1, 0, 0},
    {0, 1, 0},
    {0, 0, 1},
    {1, 1, 0},
    {0, 1, 1},
    {1, 1, 1},
    {1, 0, 1}
};

void RandCode(int* a);

void Encode(const int* src, int* des);

void Trans(int* x, int* y, double* w, double Eb_No);

void Decode(const int* src, int* des);

int getErrBit(const int* src, const int* des);

int Check(const int*src, const int* des);

#endif
