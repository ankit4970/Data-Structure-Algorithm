//
// Created by ankit on 9/20/2017.
//


#include "bits.h"

#define ISPOWEROFTWO(n) (n && !(n&(n-1)))               // returns true if given number is power of 2 else false
#define MY_SIZEOF(type) (char*)(&type+1)-(char*)(&type)

// Bit-fields
typedef struct size
{
    int a:1;   // same 4 bytes
    int b:31;
} mystruct;

/* **************************************************************************************************
 * lowest bit set
 ************************************************************************************************/
int lowestBitSet(int x)
{
    return (x & ~(x-1));
}


/* **************************************************************************************************
 * lowest bit not set
 ************************************************************************************************/
int lowestBitNotSet(int x)
{
    return (~x & (x+1));
}

/* **************************************************************************************************
 * signOfNumber
 ************************************************************************************************/
void BitsClass::signOfNumber(int v)
{
    int sign = v >> (sizeof(int) * 8 - 1);
    cout << sign << endl;
}

/* **************************************************************************************************
 * No of bits set : Brian Kernighan’s Algorithm:
 * ex. 31 = 11111 -> return 5
 *      8 = 1000 -> return 1
 ************************************************************************************************/
int BitsClass::noOfSetBits(int n)
{
    int count =0;
    while (n)
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
int BitsClass::FlippedCount(int a, int b)
{
    return noOfSetBits(a^b);
}

/* **************************************************************************************************
* Swap even and odd bits
   ex. input: 25 = 11001 -> output 100110
   	   input: 0x10101010 -> output 0x01010101
*************************************************************************************************/
uint32_t BitsClass::swapEvenOdd(uint32_t num)
{
    uint32_t even = num & 0xAAAAAAAA;
    uint32_t odd = num & 0x55555555;

    uint32_t swapBits = (even >> 1 | odd << 1);

    return swapBits;
}

/* **************************************************************************************************
* add
 * Add two integers without + - operator
*************************************************************************************************/
int BitsClass::add(int a, int b)
{
    int sum = 0;
    while (b != 0)
    {
        sum = a^b;
        b = (a&b)<<1;
        a = sum;
    }
    return sum;
}

/* **************************************************************************************************
 * reverseBits
 ************************************************************************************************/
uint32_t BitsClass::reverseBits(uint32_t num)
{
    uint32_t revNum = num;              // revNum will be reversed bits of num
    uint32_t s = sizeof(num)*8 - 1;   // extra shift needed at end

    for (num >>= 1 ; num ; num >>= 1)
    {
        revNum <<= 1;
        revNum |= num & 0x1;
        s--;
    }
    revNum <<= s;                    // shift when v's highest bits are zero
    return revNum;
}

/* **************************************************************************************************
* primeNumbers
*************************************************************************************************/
void BitsClass::primeNumbers(int n)
{
    bool arr[n+1] ={};
    memset(arr, false, sizeof(arr));

    for (int i=2 ; i*i <=n ; ++i)
    {
        if (arr[i] == false)
        {
            for (int j=i*2 ; j <= n ; j+=i)
            {
                arr[j] = true;
            }
        }
    }

    // Print all prime numbers
    for (int i = 2; i <= n ; ++i)
    {
        if (arr[i] == false)
        {
            cout << i << " " ;
        }
    }
    cout << endl;
}

/* **************************************************************************************************
 * bitsMain
 ************************************************************************************************/
void BitsClass::bitsMain()
{
    std::cout << "Hello from bitsMain" << std::endl;
    primeNumbers(30);
    cout << ISPOWEROFTWO(0) << endl;
    cout << ISPOWEROFTWO(32) << endl;

    cout << "size of " << sizeof(mystruct) << endl;
}
