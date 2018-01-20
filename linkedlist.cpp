//
// Created by ankit on 9/4/2017.
//
#include <time.h>
#include <sys/time.h>
#include "common.h"

/****************************************************************************
 * printList
 ***************************************************************************/
void LinkedList::printList(ListNode *head )
{
    while(head != NULL)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

/* ******************************************************************************
 * reverseList -  reverse a given linkedlist
 ******************************************************************************/
void LinkedList::reverseList(ListNode** head)
{
    ListNode *pre = nullptr;
    ListNode *cur = *head;
    ListNode *temp = nullptr;

    while (cur != nullptr)
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
void LinkedList::deleteFromList(ListNode **head, int dataToDelete)
{
    ListNode *cur = *head;
    ListNode *pre = nullptr;

    if(*head == nullptr)
    {
        cout << "Empty list" << endl;
        return;
    }

    while(cur != nullptr)
    {
        if(cur->val == dataToDelete)
        {
            if(cur == *head)
            {
                *head = cur->next;
                delete(cur);
                return;
            }

            pre->next = cur->next;
            delete(cur);
            return;
        }

        pre = cur;
        cur = cur->next;
    }

    cout << "ListNode not found" << endl;
}

/* ******************************************************************************
 * appendToList -  append given number to the given list
 ******************************************************************************/
void LinkedList::appendToList(ListNode **head, int data)
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
ListNode* LinkedList::addTwoNumbers(ListNode* l1, ListNode* l2)
{
    ListNode preHead(0), *p = &preHead;
    int carry = 0;
    while (l1 || l2 || carry)
    {
        int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
        carry = sum / 10;
        p->next = new ListNode(sum % 10);
        p = p->next;
        l1 = l1 ? l1->next : l1;
        l2 = l2 ? l2->next : l2;
    }
    return preHead.next;
}

/* ******************************************************************************
 * findMiddle -  find middle of the linkedlist
 ******************************************************************************/
ListNode* LinkedList::findMiddle(ListNode *head)
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
 * findMiddleNew -  add two numbers given as digits in linkedlist
 ******************************************************************************/
ListNode* LinkedList::findMiddleNew(ListNode *head)
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
 * findLoop -  find loop in the linkedList
 ******************************************************************************/
bool LinkedList::findCycle(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;

    while(fast && fast->next)
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
 * detectAndReturnCycleNode
 *     Detects cycle in linkedlist and returns the cycle node
 *******************************************************************************/
ListNode* LinkedList::detectAndReturnCycleNode(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;
    bool isCycle = false;
    if(head == NULL)
    {
        return NULL;
    }
    while(fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;

        if(fast == slow)
        {
            isCycle = true;
        }
    }

    if(isCycle)
    {
        ListNode *temp = head;
        while(temp)
        {
            slow = fast;
            while(slow->next != fast && slow->next != temp)
            {
                slow = slow->next;
            }
            if(slow->next == temp)
            {
                //slow->next = NULL;          // If asked to remove cycle, then uncomment this line
                return temp;
            }
            temp = temp->next;
        }
    }

    return NULL;
}

/* ******************************************************************************
 * mergeTwoSorted -  mergeSorted
 *******************************************************************************/
ListNode* LinkedList::mergeTwoSorted(ListNode *h1, ListNode *h2)
{
    if (!h1)
        return h2;
    if (!h2)
        return h1;

    if (h1->val < h2->val)
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
void LinkedList::insertSorted(ListNode **head, ListNode *temp)
{
    ListNode * current = *head;
    if (*head == nullptr || (*head)->val > temp->val)
    {
        temp->next = *head;
        *head = temp;
    }
    else
    {
        while (current->next && current->next->val < temp->val)
        {
            current = current->next;
        }

        temp->next = current->next;
        current->next = temp;
    }
}



/* ******************************************************************************
 * deleteDuplicates -  delete duplicates
 ******************************************************************************/
ListNode* LinkedList::deleteDuplicates(ListNode* head)
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
ListNode* LinkedList::deleteDuplicatesSorted(ListNode* head)
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
 * rotateCounterClock
 *      Rotates a given list by k elements counter clockwise
 * ex.
 *      input  : list - 10->20->30->40->50->60 and k is 4
 *      output : 50->60->10->20->30->40
 ******************************************************************************/
void LinkedList::rotateCounterClock(ListNode **head_ref, int k)
{
    ListNode* kth = *head_ref;
    ListNode* last = *head_ref;
    int count = 1;

    if ( *head_ref == NULL)
    {
        return;
    }

    while (last->next != NULL)
    {
        if(count == k)
        {
            kth = last;
        }
        last = last->next;
        count++;                // Will be length

    }

    if (count == k )
    {
        return;
    }
    else
    {
        last->next = *head_ref;
        *head_ref = kth->next;
        kth->next = NULL;
    }
}
/* ******************************************************************************
 * segEvenOdd
 *      Segregates even and odd elements in a linkedlist
 * ex.
 *      input  : 1->2->4->3->6->5->7
 *      output : 2->4->6->3->1->5->7
 * Note: Order may get changed
 ******************************************************************************/
void LinkedList::segEvenOdd(ListNode* head)
{
    struct timeval  tv1, tv2;
    gettimeofday(&tv1, NULL);

    ListNode* even = head;
    ListNode* cur = head;

    while (cur)
    {
        if (!(cur->val%2) && cur != even)   // if even and not same
        {
            while(cur != even)
            {
                int temp = cur->val;
                cur->val = even->val;
                even->val = temp;
                even = even->next;
            }
        }
        else if(!(cur->val%2) && cur == even) // even and same
        {
            even = even->next;
        }
        cur = cur->next;
    }

    gettimeofday(&tv2, NULL);
    printf ("Total time = %f seconds\n",
            (double) (tv2.tv_usec - tv1.tv_usec) / 1000000 +
            (double) (tv2.tv_sec - tv1.tv_sec));
}

ListNode* LinkedList::addTwoNumbers2(ListNode* l1, ListNode* l2)
{
    stack <ListNode*> s1,s2;
    ListNode* ret;
    ListNode* res;
    int sum=0;
    int carry=0;
    while(l1!=NULL || l2!=NULL)
    {
        if(l1)
        {
            s1.push(l1);
            l1=l1->next;
        }

        if(l2)
        {
            s2.push(l2);
            l2=l2->next;
        }
    }
    while(!s1.empty() || !s2.empty())
    {
        if(s1.size()>0 && s2.size() >0)
        {
            sum = s1.top()->val + s2.top()->val + carry;
            cout<<" stack "<<s1.top()->val<<" "<<s2.top()->val<<endl;
            s1.pop();
            s2.pop();
            carry = sum / 10;
            cout<<" here "<<sum<<endl;
            if (sum>9)
                sum = sum%10;
            ListNode *temp = new ListNode(sum);
            if(res == NULL)
            {
                res =temp;
                ret = res;
            }
            else
            {
                res->next = temp;
                res = res->next;
            }
            //if(s1.size()==1) break;
        }
        if(s1.size()>0 && s2.size() ==0)
        {
            sum = s1.top()->val + carry;
            cout<<" stack "<<s1.top()->val<<endl;
            s1.pop();
            carry = sum / 10;
            cout<<" here2 "<<sum<<endl;
            if (sum>9)
                sum = sum%10;
            ListNode *temp = new ListNode(sum);
            res->next = temp;
            res = res->next;
        }
        if(!s2.empty())
        {
            sum = s2.top()->val + carry;
            s2.pop();
            carry = sum / 10;
            cout<<" here3 "<<sum<<endl;
            if (sum>9) sum =
                           sum%10;
            ListNode *temp = new ListNode(sum);
            res->next = temp;
            res = res->next;
        }
    }
    return ret;
}


/* ******************************************************************************
 * linkedListMain
 ******************************************************************************/
void LinkedList::linkedListMain()
{
    std::cout << "Hello from linkedListMain" << std::endl;
#if 0
    ListNode *head = nullptr;

    appendToList(&head, 1);
    appendToList(&head, 2);
    appendToList(&head, 4);
    appendToList(&head, 3);
    appendToList(&head, 6);
    appendToList(&head, 5);
    appendToList(&head, 7);

    printList(head);

//    deleteDuplicatesSorted(head);
//    printList(head);
//    appendToList(&head, 7);
//    printList(head);
//    deleteDuplicates(head);
//    printList(head);

    segEvenOdd(head);
    cout << "After segregation" << endl;
    printList(head);

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

    ListNode* l1 = nullptr;
    appendToList(&l1, 7);
    appendToList(&l1, 2);
    appendToList(&l1, 4);
    appendToList(&l1, 3);

    ListNode* l2 = nullptr;
    appendToList(&l2, 5);
    appendToList(&l2, 6);
    appendToList(&l2, 4);

    addTwoNumbers2(l1,l2);


}
