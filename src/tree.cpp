/* **************************************************************************************
 * tree.cpp
 *
 *  Created by ankit on 9/19/2017.
 *      Author: ankit
 ***************************************************************************************/

#include "common.h"
#include "tree.h"
#include <queue>
#include <cstring>
#include <climits>

void TreeClass::preOrder(TreeNode *root)
{
    if (root)
    {
        cout << root->val << ' ';
        preOrder(root->left);
        preOrder(root->right);
    }
}

void TreeClass::inOrder(TreeNode *root)
{
    if (root)
    {
        inOrder(root->left);
        cout << root->val << ' ';
        inOrder(root->right);
    }
}

void TreeClass::postOrder(TreeNode *root)
{
    if (root)
    {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->val << ' ';
    }
}

void TreeClass::levelOrder(TreeNode *root)
{
    TreeNode* temp = nullptr;

    std::queue<TreeNode*> tempQueue;
    tempQueue.push(root);

    while (!tempQueue.empty())
    {
        temp = tempQueue.front();
        tempQueue.pop();
        cout << temp->val << ' ';

        if (temp->left)
        {
            tempQueue.push(temp->left);
        }
        if (temp->right)
        {
            tempQueue.push(temp->right);
        }
    }
}

/* **************************************************************************************
* Returns true if the given tree is a BST and its values are >= min and <= max.
***************************************************************************************/
bool TreeClass::isBSTUtil(TreeNode *node, int min, int max)
{
    /* an empty tree is BST */
    if (node == NULL) {
        return true;
    }

    /* false if this node violates the min/max constraint */
    if (node->val < min || node->val > max)
    {
        return false;
    }

    /* otherwise check the subtrees recursively, tightening the min or max constraint */
    return
        isBSTUtil(node->left, min, node->val - 1) &&     // Allow only distinct values
        isBSTUtil(node->right, node->val + 1, max);      // Allow only distinct values
}

/* Returns true if the given tree is a binary search tree (efficient version). */
int TreeClass::isBST(TreeNode *node)
{
    return isBSTUtil(node, INT_MIN, INT_MAX);
}

int TreeClass::helperBT(string &data)
{
    int pos = data.find(',');
    int val = stoi(data.substr(0, pos));
    data = data.substr(pos + 1);
    return val;
}

// Encodes a tree to a single string.
string TreeClass::serializeBT(TreeNode *root)
{
    if (root == nullptr)
        return "#";

    return to_string(root->val) + "," + serializeBT(root->left) + "," + serializeBT(root->right);
}

TreeNode* TreeClass::deserializeBTHelper(string& data)
{
    if (data[0] == '#')
    {
        if (data.size() > 1)
            data = data.substr(2);
        return nullptr;
    }
    else
    {
        TreeNode *node = new TreeNode(helperBT(data));
        node->left = deserializeBTHelper(data);
        node->right = deserializeBTHelper(data);
        return node;
    }
}

TreeNode* TreeClass::deserializeBT(string data)
{
    return deserializeBTHelper(data);
}

void TreeClass::serializeBSTHelper(TreeNode* root, string& str)
{
    if (root)
    {
        char buf[4];
        memcpy(buf, &(root->val), sizeof(int)); //burn the int into 4 chars
        for(int i = 0 ; i < 4; ++i)
            str.push_back(buf[i]);

        serializeBSTHelper(root->left, str);
        serializeBSTHelper(root->right, str);
    }
}

string TreeClass::serializeBST(TreeNode *root)
{
    string str;
    serializeBSTHelper(root, str);
    return str;
}

TreeNode* TreeClass::deSerializeBSTHelper(string& str, int& pos, int minValue, int maxValue)
{
    if(pos >= str.size())
    {
        return NULL;
    }

    int value;
    memcpy(&value, &str[pos], sizeof(int));
    if(value < minValue || value > maxValue)
    {
        return NULL;
    }

    TreeNode *node = new TreeNode(value);
    pos += sizeof(int);
    node->left = deSerializeBSTHelper(str, pos, minValue, value);
    node->right = deSerializeBSTHelper(str, pos,  value, maxValue);

    return node;
}

TreeNode* TreeClass::deSerializeBST(string data)
{
    int pos = 0;
    return deSerializeBSTHelper(data, pos, INT_MIN, INT_MAX);
}

TreeNode* minElement(TreeNode* node)
{
    while (node->left)
    {
        node = node->left;
    }

    return node;
}

TreeNode* inOrderSuccessorBST(TreeNode* root, TreeNode* node)
{
    TreeNode* successor = nullptr;

    if (node->right != NULL)
    {
        return minElement(node->right); // Leftmost node in right subtree
    }

    while (root)
    {
        if (root->val > node->val)
        {
            successor = root;
            root = root->left;
        }
        else if (root->val < node->val)
        {
            root = root->right;
        }
        else
            break;
    }

    return successor;
}

void TreeClass::treeMain()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    preOrder(root); cout << endl;
    inOrder(root); cout << endl;
    postOrder(root); cout << endl;
    levelOrder(root); cout << endl;

    string binaryTree;
    binaryTree = serializeBT(root);
    cout << "Serialized string BT : " << binaryTree << endl;
    TreeNode* newNode = deserializeBT(binaryTree);

    TreeNode *rootBST = new TreeNode(8);
    rootBST->left = new TreeNode(3);
    rootBST->right = new TreeNode(10);
    rootBST->left->left = new TreeNode(1);
    rootBST->left->right = new TreeNode(6);
    rootBST->right->right = new TreeNode(14);
    rootBST->left->right->left = new TreeNode(4);
    rootBST->left->right->right = new TreeNode(7);
    rootBST->right->right->left = new TreeNode(13);

    inOrder(rootBST); cout << endl;
    string binarySearchtree;
    binarySearchtree = serializeBST(rootBST);

    TreeNode* newRootBST = deSerializeBST(binarySearchtree);
    inOrder(newRootBST); cout << endl;

    TreeNode* successor = inOrderSuccessorBST(rootBST, rootBST->right->right->left);
    cout << "In order successor of " <<  rootBST->right->right->left->val << "is " << successor->val;
}
