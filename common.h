//
// Created by ankit on 10/7/2017.
//

#ifndef INTERVIEW_COMMON_H
#define INTERVIEW_COMMON_H

#include <iostream>
#include <climits>
#include <vector>
#include <list>
#include <stack>

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
//
//void linkedListMain();
//void algoMain();
//void matrixMain();
void stringMain();
//int sortingMain();
//void graphMain();
//void arrayMain();
//void bitsMain();
//void memoryMain();
//void pointerMain();
//void fucnPointerMain();
// Class definitions

class Matrix
{
    void printMatrix(vector<vector<int>> &matrix) ;
    void matrixMultiplication() ;
    void matrixRotate90() ;
    void multiply(int m1, int m2, int **mat1, int n1, int n2, int **mat2);
public:
    void matrixMain();      // Entry point
};

class LinkedList
{
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
    ListNode* mergeTwoSorted(ListNode *h1, ListNode *h2);
    ListNode* findMiddle(ListNode *head);
    ListNode* findMiddleNew(ListNode *head);
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
    void segEvenOdd(ListNode* head);

    ListNode* addTwoNumbers2(ListNode* l1, ListNode* l2);
public:
    void linkedListMain();  // Entry point
};

// This class represents a directed graph using adjacency list representation
class Graph
{
    int V;                                      // No. of vertices
    list<int> *adj;
    void DFSUtil(int v, vector<bool> visited);
    bool DFSUtilCycle(int s, vector<bool> &visited, vector<bool> &stackVisited);
    void topologicalSortUtil(int v, bool visited[], stack<int> &Stack);
public:
    Graph(int Vertex)
    {
        V = Vertex;
        adj = new list<int>[V];
    }

    void addEdge(int v, int w);
    void BFS(int s);
    void DFS(int s);
    void topologicalSort();
    friend void printGraph(Graph *graph);
    bool DFSCycle(int s);
};


class dynamicProgram
{
    int lps(char* string);
};

class TreeClass
{
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

public:
    void treeMain();
};

class BackTracking{

    void coinChange(int amount, vector<int>& coins);
    void coinChangeCombinations(int amount, vector<int>& coins);
    vector<vector<int>> subsets(vector<int>& nums);
    void subsetsUtil(vector<int>& nums, vector<vector<int>>& combs, int index, vector<int>& combinations);
public:
    void backTrackMain();
};
#endif //INTERVIEW_COMMON_H
