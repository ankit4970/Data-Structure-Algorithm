/* **************************************************************************************
* memory.cpp
*   Created by ankit on 12/2/2017
****************************************************************************************/
#include "../includes/common.h"

#define my_sizeof(type)     (char*)(&type+1)-(char*)(&type)     // Similar to sizeof
#define offset_of(TYPE, x)  ((size_t)&(((TYPE *)0)->x))         // Offset of variable in structure

typedef struct {
    long long a;
    long long b;
    char c;
    char d;
    long long e;
}testType;

// structure A
typedef struct structa_tag
{
    int        c:5;
    int        s:8;
    char        z:1;
} structa_t;

// structure B
typedef struct structb_tag
{
    short int   s;
    char        c;
    int         i;
} structb_t;

// structure C
typedef struct structc_tag
{
    char        c;
    double      d;
    int         s;
} structc_t;

// structure D
typedef struct structd_tag
{
    double      d;
    int         s;
    char        c;
} structd_t;


void endianness()
{
    unsigned int i = 1;
    char *c = (char*)&i;
    if (*c)
        printf("Little endian\n");
    else
        printf("Big endian\n");
    return;
}

void my_memcpy(void* source, void* dest, size_t size)
{
    char* p1 = (char*)source;
    char* p2 = (char*)dest;

    while (size--)
    {
        *p2++ = *p1++;
    }
}

void my_memcpy_fast(void* source, void* dest, size_t size)
{
    uint64_t* u64src = (uint64_t*)source;
    uint64_t* u64dest = (uint64_t*)dest;

    while (size >= sizeof(uint64_t))
    {
        *u64dest++ = *u64src++;
        size -= sizeof(uint64_t);
        //cout << (char*)dest << endl;
    }

    char* p2 = (char*)(u64dest);
    char* p1 = (char*)(u64src);

    // copy remaining bytes
    while (size--)
    {
        *p2++ = *p1++;
    }

}
void* alignedMalloc(size_t size, size_t alignment)
{
    void *p1 = malloc(size + alignment + sizeof(void*));    // alignment=16,size=20, total=20+16+4=40 bytes allocated
    if (p1)
    {
        size_t offset = (size_t)p1 + alignment + sizeof(void*); // offset = 1+16+4 = 21

        void *p2 = (void*) (offset - (offset % alignment));       // p2 = 21 -(21%16) = 16

        *((size_t*)p2 - 1) = (size_t) p1;

        return p2;
    }
    return NULL;
}

void alignedFree(void* p)
{
    free((void*)(*((size_t*)p-1)));
}

void swap(int *p, int *q)
{
    if (p != q)
    {
        *p = *p ^ *q;
        *q = *p ^ *q;
        *p = *p ^ *q;
    }
}

void memoryMain()
{
    cout << "Machine is : ";
    endianness();

    testType a;

    printf("Size is : %d\n", my_sizeof(a));
    printf("Offset is : %d\n", offset_of(testType, d));


    printf("sizeof(structa_t) = %d\n", sizeof(structa_t));
    printf("sizeof(structb_t) = %d\n", sizeof(structb_t));
    printf("sizeof(structc_t) = %d\n", sizeof(structc_t));
    printf("sizeof(structd_t) = %d\n", sizeof(structd_t));

    char arr[12] = "AnkitGandhi";
    char brr[12] = {};
    cout << "Before copy " << brr << endl;
    my_memcpy_fast((void*)arr,(void*)brr,11);

    cout << "After copy " << brr << endl;



}