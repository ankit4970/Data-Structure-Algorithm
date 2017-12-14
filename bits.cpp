//
// Created by ankit on 9/20/2017.
//

#include "common.h"
#include <cstring>

#define ISPOWEROFTWO(n) (n && !(n&(n-1)))   // returns true if given number is power of 2 else false

/* **************************************************************************************************
 * signOfNumber
 ************************************************************************************************/
void signOfNumber(int v)
{
    int sign = v >> (sizeof(int) * 8 - 1);
}

/* **************************************************************************************************
 * No of bits set : Brian Kernighan’s Algorithm:
 * ex. 31 = 11111 -> return 5
 *      8 = 1000 -> return 1
 ************************************************************************************************/
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

/* **************************************************************************************************
 * Count number of bits to be flipped to convert A to B
   ex. input: A = 10 = 00001010
   	   input: B = 20 = 00010100
   	   -> output = 4
*************************************************************************************************/
int FlippedCount(int a, int b)
{
    return noOfSetBits(a^b);
}

/* **************************************************************************************************
* Swap even and odd bits
   ex. input: 25 = 11001 -> output 100110
   	   input: 0x10101010 -> output 0x01010101
*************************************************************************************************/
uint32_t swapEvenOdd(uint32_t num)
{
    uint32_t even = num & 0xAAAAAAAA;
    uint32_t odd = num & 0x55555555;

    uint32_t swapBits = (even >> 1 | odd << 1);

    return swapBits;
}

/* **************************************************************************************************
 * reverseBits
 ************************************************************************************************/
void reverseBits()
{
    unsigned int v = 7;     // input bits to be reversed
    unsigned int r = v; // r will be reversed bits of v; first get LSB of v
    int s = sizeof(v) * 8 - 1; // extra shift needed at end

    for (v >>= 1; v; v >>= 1) {
        r <<= 1;
        r |= v & 1;
        s--;
    }
    r <<= s; // shift when v's highest bits are zero
}

/* **************************************************************************************************
* primeNumbers
*************************************************************************************************/
void primeNumbers(int n)
{
    bool arr[n/2] ={};
    memset(arr, false, sizeof(arr));

    for(int i=3 ; i*i < n  ; i=i+2 )
    {
        if(arr[i/2] == false)
        {
            for (int j=i*i; j<n; j+=i*2)
            {
                arr[j/2] = true;
            }
        }
    }
    cout << 2 << " ";

    for (int i=3; i<n ; i+=2)
    {
        if (arr[i / 2] == false)
        {
            cout << i << " " ;
        }
    }
    cout << endl;
}

/* **************************************************************************************************
 * bitsMain
 ************************************************************************************************/
void bitsMain()
{
    std::cout << "Hello from bitsMain" << std::endl;
    primeNumbers(30);
    cout << ISPOWEROFTWO(0) << endl;
    cout << ISPOWEROFTWO(32) << endl;
}