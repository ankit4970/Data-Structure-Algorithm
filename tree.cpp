/* **************************************************************************************
 * tree.cpp
 *
 *  Created by ankit on 9/19/2017.
 *      Author: ankit
 ***************************************************************************************/

#include "common.h"
#include <queue>

void preOrder(TreeNode *root)
{
    if(root)
    {
        cout << root->val << endl;
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(TreeNode *root)
{
    if(root)
    {
        inOrder(root->left);
        cout << root->val << endl;
        inOrder(root->right);
    }
}

void postOrder(TreeNode *root)
{
    if(root)
    {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->val << endl;
    }
}

void LevelOrder(TreeNode * root)
{
    TreeNode* temp = nullptr;
    queue<TreeNode *> tempQueue;
    tempQueue.push(root);

    while(!tempQueue.empty())
    {
        temp = tempQueue.front();
        tempQueue.pop();
        cout << temp->val << ' ';

        if(temp->left)
        {
            tempQueue.push(temp->left);
        }
        if(temp->right)
        {
            tempQueue.push(temp->right);
        }
    }
}


/* **************************************************************************************
 * Returns true if the given tree is a BST and its values are >= min and <= max.
 ***************************************************************************************/
int isBSTUtil(TreeNode* node, int min, int max)
{
    /* an empty tree is BST */
    if (node == NULL)
    {
        return 1;
    }

    /* false if this node violates the min/max constraint */
    if (node->val < min || node->val > max)
    {
        return 0;
    }

    /* otherwise check the subtrees recursively, tightening the min or max constraint */
    return
        isBSTUtil(node->left, min, node->val-1) &&     // Allow only distinct values
        isBSTUtil(node->right, node->val+1, max);      // Allow only distinct values
}

/* Returns true if the given tree is a binary search tree (efficient version). */
int isBST(TreeNode* node)
{
    return(isBSTUtil(node, INT_MIN, INT_MAX));
}

int helper(string& data) {
    int pos = data.find(',');
    int val = stoi(data.substr(0,pos));
    data = data.substr(pos+1);
    return val;
}
// Encodes a tree to a single string.
string serialize(TreeNode* root) {
    if (root == nullptr) return "#";
    return to_string(root->val)+","+serialize(root->left)+","+serialize(root->right);
}
TreeNode* mydeserialize(string& data)
{
    if (data[0]=='#')
    {
        if(data.size() > 1)
            data = data.substr(2);
        return nullptr;
    }
    else
    {
        TreeNode* node = new TreeNode(helper(data));
        node->left = mydeserialize(data);
        node->right = mydeserialize(data);
        return node;
    }
}
// Decodes your encoded data to tree.
TreeNode* deserialize(string data) {
    return mydeserialize(data);
}

/*
void seriaLize(TreeNode* root, string& s)
{

}

// Encodes a tree to a single string.
string serialize(TreeNode* root)
{

}

inline TreeNode* deseriaLize(const string& buffer, int& pos, int minValue, int maxValue)
{

}

// Decodes your encoded data to tree.
TreeNode* deserialize(string data)
{

}
 */