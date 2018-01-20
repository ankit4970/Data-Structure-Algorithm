//
// Created by ankit on 1/3/2018.
//
#include <cstring>
#include "common.h"

int dynamicProgram::lps(char* str)
{
    int length = strlen(str);
    int L[length][length];

    for(int i = 0 ; i < length ; i++)
    {
        L[i][i] = 1;
    }

}