//
// Created by ankit on 1/22/2018.
//

#ifndef INTERVIEW_MYSTACK_H
#define INTERVIEW_MYSTACK_H

#include <iostream>
#include <stack>

using namespace std;

#define MAX 1000

class myStack
{
    public:

        bool push(int data);
        int pop();
        bool isEmpty();
        myStack()
        {
            top = -1;
        }
    private:
        int array[MAX];
        int size;
        int top ;
};

#endif //INTERVIEW_MYSTACK_H
