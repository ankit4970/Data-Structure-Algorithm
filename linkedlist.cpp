//
// Created by ankit on 9/4/2017.
//
#include "common.h"

/****************************************************************************
 * printList
 ***************************************************************************/
void printList(ListNode *head )
{
    while(head != NULL) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

/* ******************************************************************************
 * reverseList -  reverse a given linkedlist
 ******************************************************************************/
void reverseList(ListNode** head)
{
    ListNode *pre = nullptr;
    ListNode *cur = *head;
    ListNode *temp = nullptr;

    while(cur != nullptr)
    {
        temp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = temp;
    }
    *head = pre;
}

/* ******************************************************************************
 * deleteFromList -  delete a given number from linkedlist
 ******************************************************************************/
void deleteFromList(ListNode **head, int dataToDelete)
{
    ListNode *temp = *head;
    ListNode *pre = nullptr;

    if(*head == nullptr)
    {
        cout << "Empty list" << std::endl;
        return;
    }

    while(temp != nullptr)
    {
        if(temp->val == dataToDelete)
        {
            if(temp == *head)
            {
                *head = temp->next;
                delete(temp);
                return;
            }

            pre->next = temp->next;
            delete(temp);
            return;
        }

        pre = temp;
        temp = temp->next;
    }

    cout << "ListNode not found" << endl;
}

/* ******************************************************************************
 * appendToList -  append given number to the given list
 ******************************************************************************/
void appendToList(ListNode **head, int data)
{
    ListNode *newNode = new ListNode(data);

    ListNode *temp = *head;

    if(*head == nullptr)
    {
        *head = newNode;
        return;
    }

    while(temp->next != nullptr)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

/* ******************************************************************************
 * addTwoNumbers -  add two numbers given as digits in linkedlist
 ******************************************************************************/
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
    ListNode preHead(0), *p = &preHead;
    int extra = 0;
    while (l1 || l2 || extra)
    {
        int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + extra;
        extra = sum / 10;
        p->next = new ListNode(sum % 10);
        p = p->next;
        l1 = l1 ? l1->next : l1;
        l2 = l2 ? l2->next : l2;
    }
    return preHead.next;
}

#if 0
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
    ListNode* head = NULL;
    ListNode* temp = NULL;
    ListNode* cur = NULL;

    int reminder = 0;
    while(l1 || l2 || reminder)
    {
        int tempValue = (l1 ? l1->val : 0 )+ (l2 ? l2->val : 0 )+ reminder;

        reminder = tempValue/10;
        tempValue = tempValue%10;

        temp = new ListNode(tempValue);

        if(head == NULL)
        {
            head = temp;
        }
        else
        {
            cur->next = temp;
        }
        cur = temp;

        l1 = l1 ? l1->next : NULL;
        l2 = l2 ? l2->next : NULL;
    }

    return head;
}
#endif

/* ******************************************************************************
 * findMiddle -  find middle of the linkedlist
 ******************************************************************************/
ListNode *findMiddle(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;

    if (head != nullptr)
    {
        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    return head;
}

/* ******************************************************************************
 * addTwoNumbers -  add two numbers given as digits in linkedlist
 ******************************************************************************/
ListNode *findMiddleNew(ListNode *head)
{
    ListNode *slow = head;
    ListNode *mid = head;
    int count = 0;

    if (head != nullptr)
    {
        while (head)
        {
            head = head->next;

            if(count & 1)
            {
                mid = mid->next;
            }
            count++;
        }
    }
    return mid;
}

/* ******************************************************************************
 * mergeTwoSorted -  mergeSorted
 ******************************************************************************/
ListNode *mergeTwoSorted(ListNode *h1, ListNode *h2)
{
    if(!h1)
        return h2;
    if(!h2)
        return h1;

    if(h1->val < h2->val)
    {
        h1->next = mergeTwoSorted(h1->next, h2);
        return h1;
    }
    else
    {
        h2->next = mergeTwoSorted(h1, h2->next);
        return h2;
    }
}

/* ******************************************************************************
 * insertSorted -  insert Sorted
 ******************************************************************************/
void insertSorted(ListNode **head, ListNode *temp)
{
    ListNode * current = *head;
    if(*head == nullptr || (*head)->val > temp->val)
    {
        temp->next = *head;
        *head = temp;
    }
    else
    {
        while(current->next && current->next->val < temp->val)
        {
            current = current->next;
        }

        temp->next = current->next;
        current->next = temp;
    }
}

/* ******************************************************************************
 * findLoop -  find loop in the linkedList
 ******************************************************************************/
bool findLoop(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;

    while(slow && fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;

        if(fast == slow)
        {
            return true;
        }
    }

    return false;
}

/* ******************************************************************************
 * deleteDuplicates -  delete duplicates
 ******************************************************************************/
ListNode* deleteDuplicates(ListNode* head)
{
    ListNode* newHead = head;
    ListNode* cur = head;
    ListNode* temp = NULL;
    ListNode* pre = NULL;
    long long preValue = LLONG_MIN;

    while (cur)
    {
        if ((cur->next && (cur->val == cur->next->val)) || cur->val == preValue)
        {

            if ((cur->next && cur->val == cur->next->val))
            {
                temp = cur->next->next;
                preValue = cur->val;
                if (cur == newHead)
                {
                    newHead = temp;
                }
                delete cur;
                delete cur->next;
            }
            else
            {
                temp = cur->next;
                if (cur == newHead)
                {
                    newHead = temp;
                }
                delete cur;
            }

            cur = temp;
            if (pre)
                pre->next = cur;
        }
        else
        {
            pre = cur;
            cur = cur->next;
        }

    }
    return newHead;
}

/* ******************************************************************************
 * deleteDuplicatesSorted -  delete duplicates
 ******************************************************************************/
ListNode* deleteDuplicatesSorted(ListNode* head)
{
    ListNode* cur = head;
    ListNode* pre = NULL;
    ListNode* temp = NULL;
    while(cur && cur->next)
    {
        if(cur->val != cur->next->val)
        {
            pre = cur;
            cur = cur->next;
        }
        else
        {
            if(cur == head)
            {
                head = cur->next;
                delete cur;
                cur = head;
            }
            else
            {
                temp = cur->next;
                delete cur;
                if(pre)
                    pre->next = temp;
                cur = temp;
            }
        }
    }

    return head;
}
/* ******************************************************************************
 * linkedListMain
 ******************************************************************************/
void linkedListMain()
{
    std::cout << "Hello from linkedListMain" << std::endl;

    ListNode *head = nullptr;
    ListNode *head1 = nullptr;

    appendToList(&head, 4);
    appendToList(&head, 5);
    appendToList(&head, 6);
    appendToList(&head, 6);
    appendToList(&head, 7);

    printList(head);

    deleteDuplicatesSorted(head);
    printList(head);
    appendToList(&head, 7);
    printList(head);
    deleteDuplicates(head);
    printList(head);
#if 0
    std::cout << "List after deletion" << std::endl;
    deleteFromList(&head, 6);
    printList(head);

    std::cout << "List after sorted add" << std::endl;

    ListNode *temp = new ListNode(1);
    insertSorted(&head,temp);

    printList(head);
    std::cout << std::endl;
    std::cout << "Middle is :" <<findMiddle(head)->data << std::endl;
    std::cout << "Middle is :" <<findMiddleNew(head)->data << std::endl;

    ListNode* tmp = reverseLinkedList(head);

    printList(tmp);
#endif
    //ListNode* sum = addTwoNumbers(head, head1);
    //printList(sum);

}
