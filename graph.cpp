//
// Created by ankit on 10/14/17.
//

#include <list>
#include <vector>
#include <queue>
#include <stack>
#include "common.h"

// This class represents a directed graph using
// adjacency list representation
class Graph
{
    int V;    // No. of vertices
    // Pointer to an array containing adjacency lists
    std::list<int> *adj;
    void DFSUtil(int v, std::vector<bool> visited);
    bool DFSUtilCycle(int s, std::vector<bool> &visited, std::vector<bool> &stackVisited);
    void topologicalSortUtil(int v, bool visited[], std::stack<int> &Stack);
public:
    Graph(int Vertex)
    {
        V = Vertex;
        adj = new std::list<int>[V];
    }  // Constructor

    // function to add an edge to graph
    void addEdge(int v, int w);
    // prints BFS traversal from a given source s
    void BFS(int s);
    void DFS(int s);
    void topologicalSort();
    friend void printGraph(Graph *graph);
    bool DFSCycle(int s);
};

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
}

void Graph::BFS(int s)
{
    std::vector<bool> visited(V,false);

    visited[s] = true;

    std::list<int> queue;
    queue.push_back(s);

    while(!queue.empty())
    {
        s = queue.front();
        std::cout << s << ",";
        queue.pop_front();

        for (auto it = adj[s].begin() ; it != adj[s].end() ; it++ )
        {
            if(visited[*it] == false)
            {
                visited[*it] = true;
                queue.push_back(*it);
            }
        }
    }
}

bool Graph::DFSUtilCycle(int s, std::vector<bool>& visited, std::vector<bool>& stackVisited)
{
    if(visited[s] == false)
    {
        visited[s] = true;
        stackVisited[s] = true;

        for (auto it = adj[s].begin(); it != adj[s].end(); it++)
        {
            if (!visited[*it] && DFSUtilCycle(*it, visited, stackVisited))
            {
                return true;
            }
            else if(stackVisited[*it])
            {
                return true;
            }
        }
    }

    return stackVisited[s] = false;
}
// This algorithm can be used to solve dependency problems.
// Course dependency, package install dependency
// For ex.
//          For installing a particular service:
//          A depends on B
//          B depends on C
//          D depends on C
//          D depends on E
// This type problem can be solved using DFS and finding cycle
bool Graph::DFSCycle(int s)
{
    std::vector<bool> visited(V,false);
    std::vector<bool> stackVisited(V,false);

    for(int i = 0 ; i< V ; i++)
    {
        if(DFSUtilCycle(i, visited, stackVisited))
        {
            return true;
        }
    }

    return false;
}

void Graph::DFSUtil(int s, std::vector<bool> visited)
{

    visited[s] = true;
    std::cout << s << ",";

    for (auto it = adj[s].begin() ; it != adj[s].end() ; it++ )
    {
        if(visited[*it] == false)
        {
            DFSUtil(*it, visited);
        }
    }
}

void Graph::DFS(int s)
{
    std::vector<bool> visited(V,false);
    DFSUtil(s, visited);
}

void printGraph(Graph *graph) {
    for(int i = 0 ; i< graph->V ; i++)
    {
        std::cout << i << "->";
        for (auto it = graph->adj[i].begin(); it != graph->adj[i].end(); it++) {
            std::cout << *it << ",";
        }

        std::cout << std::endl;
    }
}

// A recursive function used by topologicalSort
void Graph::topologicalSortUtil(int v, bool visited[], std::stack<int> &Stack)
{
    // Mark the current node as visited.
    visited[v] = true;

    // Recur for all the vertices adjacent to this vertex
    std::list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            topologicalSortUtil(*i, visited, Stack);

    // Push current vertex to stack which stores result
    Stack.push(v);
}

// The function to do Topological Sort. It uses recursive
// topologicalSortUtil()
void Graph::topologicalSort()
{
    std::stack<int> Stack;

    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    // Call the recursive helper function to store Topological
    // Sort starting from all vertices one by one
    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            topologicalSortUtil(i, visited, Stack);

    // Print contents of stack
    while (Stack.empty() == false)
    {
        std::cout << Stack.top() << " ";
        Stack.pop();
    }
}

void graphMain()
{
    std::cout << "Hello from graphMain" << std::endl;

    Graph *g1 = new Graph(6);

    g1->addEdge(5, 2);
    g1->addEdge(5, 0);
    g1->addEdge(4, 0);
    g1->addEdge(4, 1);
    g1->addEdge(2, 3);
    g1->addEdge(3, 1);

    //g1->BFS(2);
    //std::cout << std::endl;
    //g1->DFS(2);
    printGraph(g1);
    //g1->topologicalSort();
}