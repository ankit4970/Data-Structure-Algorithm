//
// Created by ankit on 10/22/2017.
//
#include <iostream>

void foo(void *pVoid)
{
    std::cout << "Function with pointer called" << std::endl;
}

void foo(int pInt)
{
    std::cout << "Function with integer called" << std::endl;
}

void pointerMain()
{
    foo(NULL);
    foo(nullptr);
}