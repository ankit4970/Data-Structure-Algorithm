//
// Created by ankit on 9/19/2017.
//
struct node
{
    int data;
    node* left;
    node* right;
};

#include <iostream>
#include <queue>
#include <limits.h>

void preOrder(node *root)
{
    if(root)
    {
        std::cout << root->data << std::endl;
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(node *root)
{
    if(root)
    {
        inOrder(root->left);
        std::cout << root->data << std::endl;
        inOrder(root->right);
    }
}

void postOrder(node *root)
{
    if(root)
    {
        postOrder(root->left);
        postOrder(root->right);
        std::cout << root->data << std::endl;
    }
}
void LevelOrder(node * root)
{
    int i=0;
    node* temp = root;
    std::queue<node *> tempQueue;
    while(temp)
    {
        std::cout << temp->data << ' ';

        if(temp->left)
        {
            tempQueue.push(temp->left);
        }
        if(temp->right)
        {
            tempQueue.push(temp->right);
        }

        temp = tempQueue.front();
        tempQueue.pop();
    }
}


/* Returns true if the given tree is a BST and its
   values are >= min and <= max. */
int isBSTUtil(struct node* node, int min, int max)
{
    /* an empty tree is BST */
    if (node == NULL)
        return 1;

    /* false if this node violates the min/max constraint */
    if (node->data < min || node->data > max)
        return 0;

    /* otherwise check the subtrees recursively,
     tightening the min or max constraint */
    return
        isBSTUtil(node->left, min, node->data-1) &&  // Allow only distinct values
        isBSTUtil(node->right, node->data+1, max);  // Allow only distinct values
}

/* Returns true if the given tree is a binary search tree
 (efficient version). */
int isBST(struct node* node)
{
    return(isBSTUtil(node, INT_MIN, INT_MAX));
}
