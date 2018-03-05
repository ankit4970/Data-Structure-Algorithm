//
// Created by ankit on 1/22/2018.
//
#include "common.h"

void swap(int array[], int swap1, int swap2)
{
    int temp = array[swap2];
    array[swap2] = array[swap1];
    array[swap1] = temp;
}

void printList(int arr[], int size)
{
    for(int k = 0; k < size ; k++)
    {
        cout << arr[k] << ",";
    }
    cout << endl;
}


void swap(int& swap1, int& swap2)
{
    int temp = 0;
    temp = swap2;
    swap2 = swap1;
    swap1 = temp;
}