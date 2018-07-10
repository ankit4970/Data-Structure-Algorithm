//
// Created by ankit on 1/19/2018.
//

#ifndef INTERVIEW_TREE_H
#define INTERVIEW_TREE_H

#include "iostream"

using namespace std;

// A Binary Tree Node
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class TreeClass {

    void levelOrder(TreeNode *root);
    void postOrder(TreeNode *root);
    void inOrder(TreeNode *root);
    void preOrder(TreeNode *root);

    TreeNode* deserialize(string data);
    TreeNode* deserializeBT(string data);
    TreeNode* deserializeBTHelper(string &data);

    string serializeBT(TreeNode *root);
    TreeNode* deSerializeBST(string data);
    TreeNode* deSerializeBSTHelper(string& str, int& pos, int min, int max);
    int helperBT(string &data);
    int helperBST(string &data,int pos);
    void serializeBSTHelper(TreeNode *root, string& str);
    string serializeBST(TreeNode *root);

    int isBST(TreeNode *node);
    bool isBSTUtil(TreeNode *node, int min, int max);

    TreeNode* kthSmallestNodeBSTUtil(TreeNode* root, int& k);
    TreeNode* kthSmallestNodeBST(TreeNode* root, int k);

    TreeNode* inOrderSuccessorBST(TreeNode* root, TreeNode* node);

    TreeNode* minElementBST(TreeNode* node);

public:
    void treeMain();
};
#endif //INTERVIEW_TREE_H
