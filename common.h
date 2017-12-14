//
// Created by ankit on 10/7/2017.
//

#ifndef INTERVIEW_COMMON_H
#define INTERVIEW_COMMON_H

#include <iostream>
#include <climits>

using namespace std;

// A Binary Tree Node
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// A LinkedList Node
struct ListNode
{
    int val;
    ListNode * next;
    ListNode(int value) : val(value), next(nullptr){}
};


// Function declarations

void linkedListMain();
void algoMain();
void matrixMain();
void stringMain();
int sortingMain();
void graphMain();
void arrayMain();
void bitsMain();
void memoryMain();

#endif //INTERVIEW_COMMON_H
