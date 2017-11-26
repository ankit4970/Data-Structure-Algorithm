//
// Created by ankit on 9/20/2017.
//
#include "common.h"

void signOfNumber(int v)
{
    int sign = v >> (sizeof(int) * 8 - 1);
}

/*
 *************************************************************************************************
 * No of bits set : Brian Kernighan’s Algorithm:
 *
 * ex. 31 = 11111 -> return 5
 *      8 = 1000 -> return 1
 ************************************************************************************************
 */
int noOfSetBits(int n)
{
    int count =0;
    while(n)
    {
        n = (n & (n-1));
        count++;
    }

    return count;
}

/*
 * ************************************************************************************************
 * Count number of bits to be flipped to convert A to B

   ex. input: A = 10 = 00001010
   	   input: B = 20 = 00010100
   	   -> output = 4
 ***********************************************************************************************
 **/
int FlippedCount(int a, int b)
{
    return noOfSetBits(a^b);
}

/*
 * ************************************************************************************************
 * Swap even and odd bits
   ex. input: 25 = 11001 -> output 100110
   	   input: 0x10101010 -> output 0x01010101
 ************************************************************************************************/

uint32_t swapEvenOdd(uint32_t num)
{
    uint32_t even = num & 0xAAAAAAAA;
    uint32_t odd = num &  0x55555555;

    uint32_t swapBits = (even >> 1 | odd << 1);

    return swapBits;
}

void reverseBits() {
    unsigned int v;     // input bits to be reversed
    unsigned int r = v; // r will be reversed bits of v; first get LSB of v
    int s = sizeof(v) * 8 - 1; // extra shift needed at end

    for (v >>= 1; v; v >>= 1) {
        r <<= 1;
        r |= v & 1;
        s--;
    }
    r <<= s; // shift when v's highest bits are zero
}

int bitsMain()
{
    std::cout << "Hello from bitsMain" << std::endl;
}