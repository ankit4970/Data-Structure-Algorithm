
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


int main()
{
    cout << "Hello, the World!" << endl;

    //linkedListMain();
    //algoMain();
    matrixMain();
    //stringMain();
    //sortingMain();
    //graphMain();
    //arrayMain();
    //bitsMain();
    //memoryMain();
    return 0;
}
