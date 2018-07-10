//
// Created by ankit on 1/22/2018.
//

#ifndef INTERVIEW_BITS_H
#define INTERVIEW_BITS_H

#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdint>

using namespace std;

class BitsClass{
    int noOfSetBits(int n);
    void signOfNumber(int v);
    int FlippedCount(int a, int b);
    uint32_t swapEvenOdd(uint32_t num);
    int add(int a, int b);
    uint32_t reverseBits(uint32_t num);
    void primeNumbers(int n);
public:
    void bitsMain();
};
#endif //INTERVIEW_BITS_H
