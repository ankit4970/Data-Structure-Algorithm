
#include "common.h"
#include <functional>
#include <queue>
#include <algorithm>


// Macro to implement user defined sizeof function
#define my_sizeof(type) (char *)(&type+1)-(char*)(&type)

template<typename T> void print_queue(T& q) {
    while(!q.empty())
    {
        std::cout << q.top() << " ";
        q.pop();
    }
    std::cout << '\n';
}

#if 0
int main() {
    std::priority_queue<int> q;

    for(int n : {1,8,5,6,3,4,0,9,7,2})
        q.push(n);

    print_queue(q);

    std::priority_queue<int, std::vector<int>, std::less<int> > q2;

    for(int n : {1,8,5,6,3,4,0,9,7,2})
        q2.push(n);

    print_queue(q2);


    auto cmp = [](int left, int right) { return (left ^ 1) < (right ^ 1); };

    std::priority_queue<int, std::vector<int>, decltype(cmp)> q3(cmp);

    for(int n : {1,8,5,6,3,4,0,9,7,2})
        q3.push(n);

    print_queue(q3);

    std::array<int, 10> s = {5, 7, 4, 2, 8, 6, 1, 9, 0, 3};
    std::sort(s.begin(), s.end(), [](int a, int b) {
        std::cout << a <<","<< b << std::endl;
        return b < a;
    });

    for (auto a : s) {
        std::cout << a << " ";
    }
}

void abssort(float* x, unsigned n) {
    std::sort(x, x + n,
        // Lambda expression begins
         [](float a, float b) {
             return (std::abs(a) < std::abs(b));
         } // end of lambda expression
    );
}

#endif

int main()
{
    std::cout << "Hello, the World!" << std::endl;

    //linkedListMain();
    algoMain();
    //matrixMain();
    //stringMain();
    //sortingMain();
    //graphMain();
    //arrayMain();
    return 0;
}
