//
// Created by ankit on 1/19/2018.
//

#ifndef INTERVIEW_LINKEDLIST_H
#define INTERVIEW_LINKEDLIST_H

#include <iostream>
#include <stack>
#include <climits>
#include <cstddef>

using namespace std;

// A LinkedList Node
struct ListNode
{
    int val;
    ListNode * next;
    ListNode(int value) : val(value), next(nullptr){}
};

class LinkedList {

    void appendToList(ListNode **head, int data);
    void deleteFromList(ListNode **head, int dataToDelete);
    void printList(ListNode *head );

    bool findCycle(ListNode *head);
    void reverseList(ListNode** head);
    void rotateCounterClock(ListNode **head_ref, int k);

    void insertSorted(ListNode **head, ListNode *temp);
    ListNode* detectAndReturnCycleNode(ListNode *head);
    ListNode* deleteDuplicatesSorted(ListNode* head);
    ListNode* deleteDuplicates(ListNode* head);
    ListNode* deleteFromListGreater(ListNode **head, int dataToDelete);
    ListNode* mergeTwoSorted(ListNode *h1, ListNode *h2);
    ListNode* findMiddle(ListNode *head);
    ListNode* findMiddleNew(ListNode *head);
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
    void segEvenOdd(ListNode* head);

    ListNode* addTwoNumbers2(ListNode* l1, ListNode* l2);
public:
    void linkedListMain();  // Entry point
};

#endif //INTERVIEW_LINKEDLIST_H
