//
// Created by ankit on 9/4/2017.
//
#include <iostream>

typedef struct Node
{
    int data;
    Node * next;
    Node(int value)
    {
        data = value;
        next= NULL;
    };
}Node;

void insertSorted(Node **pNode, Node *temp);

/****************************************************************************
 * @param head
 ***************************************************************************/
void printList(Node *head )
{
    while(head != NULL) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

void reverseList(Node** head)
{
    Node *pre = nullptr;
    Node *cur = *head;
    Node *temp = nullptr;

    while(cur != nullptr)
    {
        temp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = temp;
    }
    *head = pre;
}

void deleteFromList(Node **head, int dataToDelete)
{
    Node *temp = *head;
    Node *pre = nullptr;

    if(*head == nullptr)
    {
        std::cout << "Empty list" << std::endl;
        return;
    }

    while(temp != nullptr)
    {
        if(temp->data == dataToDelete)
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

    std::cout << "Node not found" << std::endl;
}

void appendToList(Node **head, int data)
{
    Node *newNode = new Node(data);

    Node *temp = *head;

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

Node* addTwoNumbers(Node* l1, Node* l2)
{
    Node* head = NULL;
    Node* temp = NULL;
    Node* cur = NULL;

    int reminder = 0;
    while(l1 || l2)
    {
        int tempValue = (l1 ? l1->data : 0 )+ (l2 ? l2->data : 0 )+ reminder;

        reminder = tempValue/10;
        tempValue = tempValue%10;

        temp = new Node(tempValue);

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

    if(reminder>0)
    {
        cur->next = new Node(reminder);
    }

    return head;
}


Node *reverseLinkedList(Node *head)
{
    Node* pre = NULL;
    Node* cur = head;
    Node* tmp = NULL;

    while(cur)
    {
        tmp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = tmp;
    }
    return pre;
}

// Find the middle node of a given linked list
Node *findMiddle(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    if (head != nullptr)
    {
        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

}

Node *findMiddleNew(Node *head)
{
    Node *slow = head;
    Node *mid = head;
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

// Merge two sorted linked list inplace
Node *mergeTwoSorted(Node *h1, Node *h2)
{
    if(!h1)
        return h2;
    if(!h2)
        return h1;

    if(h1->data < h2->data)
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

void insertSorted(Node **head, Node *temp)
{
    Node * current = *head;
    if(*head == nullptr || (*head)->data > temp->data)
    {
        temp->next = *head;
        *head = temp;
    }
    else
    {
        while(current->next != nullptr && current->next->data < temp->data)
        {
            current = current->next;
        }

        temp->next = current->next;
        current->next = temp;
    }
}

bool findLoop(Node *head)
{
    Node *slow = head;
    Node *fast = head;

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

void linkedListMain()
{
    std::cout << "Hello from linkedListMain" << std::endl;

    Node *head = nullptr;
    Node *head1 = nullptr;

    appendToList(&head, 4);
    appendToList(&head, 5);
    appendToList(&head, 6);
    appendToList(&head, 7);


    appendToList(&head1, 1);
    appendToList(&head1, 2);
    appendToList(&head1, 3);
    appendToList(&head1, 4);

    printList(head);
    printList(head1);
#if 0
    std::cout << "List after deletion" << std::endl;
    deleteFromList(&head, 6);
    printList(head);

    std::cout << "List after sorted add" << std::endl;

    Node *temp = new Node(1);
    insertSorted(&head,temp);

    printList(head);
    std::cout << std::endl;
    std::cout << "Middle is :" <<findMiddle(head)->data << std::endl;
    std::cout << "Middle is :" <<findMiddleNew(head)->data << std::endl;

    Node* tmp = reverseLinkedList(head);

    printList(tmp);
#endif
    Node* sum = addTwoNumbers(head, head1);
    printList(sum);

}
