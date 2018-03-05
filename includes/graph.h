//
// Created by ankit on 1/19/2018.
//

#ifndef INTERVIEW_GRAPH_H
#define INTERVIEW_GRAPH_H

#include <iostream>
#include <stack>
#include <vector>
#include <list>
#include <unordered_map>

using namespace std;
struct GraphNode
{
    int value;
    vector<GraphNode*> neighbors;
    GraphNode(int x) : value(x) {};
};

// This class represents a directed graph using adjacency list representation
class GraphClass
{
    void DFSUtil(int v, vector<bool> visited);
    void DFS(GraphNode* root);

    bool DFSUtilCycle(int s, vector<bool> &visited, vector<bool> &stackVisited);
    bool DFSCycle(GraphNode* root);

    void topologicalSortUtil(int v, bool visited[], stack<int> &Stack);
    void topologicalSort(GraphNode* root);

    void BFS(GraphNode* root);

    GraphNode* cloneGraphBFS(GraphNode *node);

    GraphNode* cloneGraphDFSUtil(GraphNode *node, unordered_map<GraphNode*,GraphNode*>& graphMap);
    GraphNode* cloneGraphDFS(GraphNode *node);

    friend void printGraph(GraphClass* root);

    GraphNode* graphRoot;
public:
    void graphMain();
};
#endif //INTERVIEW_GRAPH_H
