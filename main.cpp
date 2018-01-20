
#include "common.h"
#include <functional>
#include <queue>
#include <algorithm>


// Macro to implement user defined sizeof function
#define my_sizeof(type) (char *)(&type+1)-(char*)(&type)

void abssort(float* x, unsigned n)
{
    sort(x, x + n,
        // Lambda expression begins
         [](float a, float b) {
             return (abs(a) < abs(b));
         } // end of lambda expression
    );
}

typedef char* CHARPTR;
#define PTRCHAR char*
void callReference(int **arr)
{
    cout << arr[3][1] << endl;
}

int main()
{
    cout << "Hello, the World!" << endl;

    /*  Linkedlist test */
#if 0
    LinkedList linklist;
    linklist.linkedListMain();

    /*  Linkedlist test */
    algoMain();

    /*  Linkedlist test */
    matrixMain();

    /*  Linkedlist test */
    stringMain();

    /*  Linkedlist test */
    sortingMain();

    /*  Linkedlist test */
    graphMain();

    /*  Linkedlist test */
    arrayMain();

    /*  Linkedlist test */
    bitsMain();

    /*  Linkedlist test */
    memoryMain();

    /*  Linkedlist test */
    Matrix matrix;
    matrix.matrixMain();

    /*  Linkedlist test */
    fucnPointerMain();

    /*  Linkedlist test */
    //pointerMain();


    TreeClass tree;
    tree.treeMain();


    BackTracking backTracking;
    backTracking.backTrackMain();
#endif
    stringMain();
    return 0;
}
