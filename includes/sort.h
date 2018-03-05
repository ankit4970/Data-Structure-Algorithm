//
// Created by ankit on 1/22/2018.
//

#ifndef INTERVIEW_SORT_H
#define INTERVIEW_SORT_H

#include <iostream>

class SortingClass {
    void selectionSort(int arr[],int len);
    bool insertionSort(int array[], int len);
    bool bubbleSort(int array[], int len);
    void quickSort(int array[], int low, int high);
    int partition(int array[], int low, int high);
    bool mergeSort(int array[], int start, int end);
    bool merge(int arr[], int start, int mid, int end);
    bool heapSort(int array[], int len);
    void heapify(int arr[], int n, int i);

    public:
        int sortingMain();
};


#endif //INTERVIEW_SORT_H
