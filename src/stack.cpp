//
// Created by ankit on 10/7/2017.
//

#include "mystack.h"


bool myStack::isEmpty()
{
    return top < 0;
}

int myStack::pop() {
    if(top < 0)
    {
        std::cout << "Empty stack";
        return 0;
    }
    return array[top--];
}

bool myStack::push(int data) {
    if(top >= MAX)
    {
        std::cout << "Stack overflow";
        return false;
    }
    array[++top] = data;
    return true;
}

class MinStack
{
    private:
        stack<int> s1;
        stack<int> s2;
    public:
        void push(int x)
        {
            s1.push(x);
            if (s2.empty() || x <= getMin())
                s2.push(x);
        }

        void pop()
        {
            if (s1.top() == getMin())
                s2.pop();
            s1.pop();
        }

        int top()
        {
            return s1.top();
        }

        int getMin()
        {
            return s2.top();
        }
};

/**
 * Definition for singly-linked list.
 *
 */


class Solution
{
public:
    struct ListNode
    {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };

};