//
// Created by ankit on 12/2/2017.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define my_sizeof(type) (char*)(&type+1)-(char*)(&type)
#define OFFSETOF(TYPE, x) ((size_t)&(((TYPE *)0)->x))

typedef  struct __attribute__((__packed__)) test{
    long long a;
    long long b;
    char c;
    char d;
    long long e;
}testType;

int endianness()
{
    unsigned int i = 1;

    char *c = (char*)&i;
    if (*c)
        printf("Little endian");
    else
        printf("Big endian");
    getchar();
    return 0;
}

void* alignedMalloc(size_t size, size_t alignment)
{
    void *p1 = malloc(size + alignment + sizeof(size_t));

    size_t addr = (size_t)p1 + alignment + sizeof(size_t);

    void *p2 = (void *)(addr - (addr%alignment));

    *((size_t*)p2-1) = (size_t)p1;

    return p2;
}

void alignedFree(void* p)
{
    free((void*)(*((size_t *)p-1)));
}



void swap(int *p, int *q)
{
    if(p != q)
    {
        *p = *p ^ *q;
        *q = *p ^ *q;
        *p = *p ^ *q;
    }
}

void memoryMain()
{
    testType a;
    printf("%d\n",sizeof(a));
    printf("%d\n",OFFSETOF(testType,d));
}