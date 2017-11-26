//
// Created by ankit on 10/12/2017.
//

/*
 * sorting.cpp
 *
 *  Created on: Jan 30, 2017
 *      Author: ankit
 */


#include "common.h"

//int arr[10] = {12,34,37,1,67,32,13,17,33,123};
#define ARRAY_LENGTH 11

void swap(int array[],int swap1,int swap2)
{
    int temp = 0;
    temp = array[swap2];
    array[swap2] = array[swap1];
    array[swap1] = temp;
}

void printList(int arr[])
{
    for(int k = 0; k < ARRAY_LENGTH ; k++)
    {
        std::cout << arr[k] << ",";
    }
    std::cout << std::endl;
}


void swap(int& swap1, int& swap2)
{
    int temp = 0;
    temp = swap2;
    swap2 = swap1;
    swap1 = temp;
}

// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
void heapify(int arr[], int n, int i)
{
    int largest = i;  // Initialize largest as root
    int l = 2*i + 1;  // left = 2*i + 1
    int r = 2*i + 2;  // right = 2*i + 2

    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

/**************************************************************************************************
* heapSort - Sorts an array using Heap sort Technique
***************************************************************************************************
*----------------------------------------------------
* Time Complexity 	|	Best Case 		: O(nlogn)	|
* 					---------------------------------
* 					| 	Average Case 	: O(nlogn)	|
* 					---------------------------------
* 					| 	Worst Case	  	: O(nlogn)	|
*----------------------------------------------------
* Space Complexity 	| 	Worst Case  	: O(1)		|
* ---------------------------------------------------
**************************************************************************************************/
bool heapSort(int array[], int len)
{
    // Build heap (rearrange array)
    for (int i = len / 2 - 1; i >= 0; i--)
        heapify(array, len, i);

    // One by one extract an element from heap
    for (int i=len-1; i>=0; i--)
    {
        // Move current root to end
        swap(array[0], array[i]);

        // call max heapify on the reduced heap
        heapify(array, i, 0);
    }
}


bool merge(int arr[],int start, int mid, int end)
{
    int n1 = mid-start+1;
    int n2 = end-mid;
    int i =0,j=0,k=0;

    int L[n1],R[n2];

    for(i = 0; i < n1 ; i++)
    {
        L[i] = arr[start+i];
    }

    for(j=0 ; j < n2 ; j++)
    {
        R[j] = arr[mid+1+j];
    }

    i=0;
    j=0;
    k=start;

    while(i<n1 && j<n2)
    {
        if(L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while(i<n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while(j<n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
    return true;
}

/**************************************************************************************************
* mergeSort - Sorts an array using Merge sort Technique
***************************************************************************************************
*----------------------------------------------------
* Time Complexity 	|	Best Case 		: O(nlogn)	|
* 					---------------------------------
* 					| 	Average Case 	: O(nlogn)	|
* 					---------------------------------
* 					| 	Worst Case	  	: O(nlogn)	|
*----------------------------------------------------
* Space Complexity 	| 	Worst Case  	: O(1)		|
* ---------------------------------------------------
**************************************************************************************************/
bool mergeSort(int array[], int start, int end)
{
    int midPoint =0;

    if(start <  end)
    {
        midPoint = start+((end-start)/2);
        mergeSort(array, start, midPoint);
        mergeSort(array, midPoint+1,end);
        merge(array,start,midPoint,end);
    }

    return true;
}

/**************************************************************************************************
* quickSort - Sorts an array using Quick sort Technique
***************************************************************************************************
*----------------------------------------------------
* Time Complexity 	|	Best Case 		: O(nlogn)	|
* 					---------------------------------
* 					| 	Average Case 	: O(nlogn)	|
* 					---------------------------------
* 					| 	Worst Case	  	: O(n²)		|
*----------------------------------------------------
* Space Complexity 	| 	Worst Case  	: O(1)		|
* ---------------------------------------------------
**************************************************************************************************/
int partition(int array[], int low, int high)
{
    int pivot = array[high];
    int lowIndex = low;

    for (int j = low ; j < high ; j ++)
    {
        if (array[j] <= pivot)
        {
            swap(array,j,lowIndex);
            lowIndex++;
        }
    }

    swap(array, lowIndex, high);	// Putting pivot to proper location

    printList(array);
    return lowIndex;
}

void quickSort(int array[], int low, int high)
{
    int pivot = 0;

    if(low < high)
    {
        pivot = partition(array,low,high);
        quickSort(array,low,pivot-1);
        quickSort(array,pivot+1,high);
    }
}

int partitionNew(int array[], int low, int high)
{
    int pivot = array[high];
    std::cout << "pivot is : " << pivot << std::endl;
    int lowIndex = low;

    for (int j = low ; j < high ; j++)
    {
        if (array[j] < pivot)
        {
            swap(array, j, lowIndex);
            lowIndex++;
        }
    }

    swap(array, lowIndex, high);	// Putting pivot to proper location
    //std::cout << "New pivot : " << lowIndex << std::endl;
    //printList(array);
    //getchar();
    return (lowIndex);
}

int mThLargest(int arr[], int low, int high, int m)
{
    int newPivot = 0;

    if(low < high)
    {
        newPivot = partitionNew(arr, low, high);
        if(newPivot ==  m)
        {
            return arr[m];
        }
        if(newPivot < m)
        {
            mThLargest(arr, newPivot+1, high, m-newPivot+low-1);
        }
        else
        {
            mThLargest(arr, low, newPivot-1, m);
        }
    }

    return arr[m];
}

/**************************************************************************************************
* bubbleSort - Sorts an array using Bubble sort Technique
***************************************************************************************************
*------------------------------------------------
* Time Complexity 	|	Best Case 		: O(n)	|
* 					-----------------------------
* 					| 	Average Case 	: O(n²)	|
* 					-----------------------------
* 					| 	Worst Case	  	: O(n²)	|
*------------------------------------------------
* Space Complexity 	| 	Worst Case  	: O(1)	|
* -----------------------------------------------
**************************************************************************************************/

bool bubbleSort(int array[], int len)
{
    int  i=0,j=0;
    int temp =0;
    bool swapped =false;

    for( i =0 ; i < len-1 ; i++)
    {
        swapped = false;
        for( j = 0 ; j < len-i-1 ; j++)
        {
            if(array[j] > array[j+1])
            {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
                swapped = true;
            }
        }
        if(!swapped)
        {
            break;
        }

        std::cout << "Bubble sort : Array after " <<i <<" pass" << "->";
        printList(array);
    }

    return true;
}

/**************************************************************************************************
* insertionSort - Sorts an array using Insertion sort Technique
* *************************************************************************************************
*------------------------------------------------
* Time Complexity 	|	Best Case 		: O(n)	|
* 					-----------------------------
* 					| 	Average Case 	: O(n²)	|
* 					-----------------------------
* 					| 	Worst Case	  	: O(n²)	|
*------------------------------------------------
* Space Complexity 	| 	Worst Case  	: O(1)	|
* -----------------------------------------------
**************************************************************************************************/
bool insertionSort(int array[], int len)
{
    int key = 0;
    int index = 0;

    for(int i=1 ; i<len ; i++)
    {
        index = i;
        key = array[i];

        for(int j = i-1 ; j >= 0 ; j--)
        {
            if(key < array[j])
            {
                array[index] = array[j];
                index = j;
            }
        }
        array[index] = key;
        std::cout << "Insertion sort : Array after " << i <<" pass" << " -> ";
        printList(array);
    }

    return true;
}

/**************************************************************************************************
* selectionSort - Sorts an array using Selection sort Technique
* *************************************************************************************************
*------------------------------------------------
* Time Complexity 	|	Best Case 		: O(n²)	|
* 					-----------------------------
* 					| 	Average Case 	: O(n²)	|
* 					-----------------------------
* 					| 	Worst Case	  	: O(n²)	|
*------------------------------------------------
* Space Complexity 	| 	Worst Case  	: O(1)	|
* -----------------------------------------------
**************************************************************************************************/
void selectionSort(int arr[],int len)
{
    int i=0,j=0,index=0,temp=0;
    bool foundlower = false;

    for(i=0 ; i<len ; i++)
    {
        index=i;
        for(j=i+1 ; j<len ; j++)
        {
            if(arr[index] > arr[j])
            {
                foundlower = true;
                index = j;
            }
        }
        if(foundlower)
        {
            temp = arr[index];
            arr[index] = arr[i];
            arr[i] = temp;
            foundlower = false;
        }
        else
        {
            return;
        }

        std::cout << "Selection sort : Array after " << i <<" pass" << " -> ";
        printList(arr);
    }
}


/**************************************************************************************************
* Main - Main Entry
* ************************************************************************************************/
int sortingMain() {
    std::cout << "Hello from sortingMain" << std::endl;
    //int array[] = {2,4,5,8,7,9,1,3,6};
    int arr[ARRAY_LENGTH] = {5, 4, 3, 2, 1, 11, 10, 9, 8, 7, 6};
    int length = sizeof(arr) / sizeof(arr[0]);
    std::cout << "Array before sorting is " << "-->";
    printList(arr);
    std::cout << std::endl;

    //selectionSort(arr,ARRAY_LENGTH);
    insertionSort(arr,ARRAY_LENGTH);
    //bubbleSort(arr,ARRAY_LENGTH);
    //quickSort(arr,0,10);
    //mergeSort(arr,0,10);
    //heapSort(arr, length);
    //std::cout << std::endl;
    //quickSort(arr,0,10);
    //std::cout << mThLargest(arr, 0, 10, 11-10) << std::endl;
    //std::cout << "Array after sorting is " << "-->";
    //printList(arr);
    return 0;

}