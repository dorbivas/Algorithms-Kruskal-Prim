#pragma once
#include <iostream>
#include "LinkedList.h"

using namespace std;

// structure to store edges
struct graphEdge {
    int start_ver, end_ver, weight;
    graphEdge() {}

    graphEdge(int _startVer, int _endVer, int _weight)
    {
        start_ver = _startVer;
        end_ver = _endVer;
        weight = _weight;

    }
};

class AdjListGraph { // AdjListGraph <LinkedList[]>
    
    // insert new nodes into adjacency list from given graph
public:
    int vertixAmount = 6;   //TODO


   
    //adjacency list as array of pointers
    // Constructor

 
    //requested
    AdjListGraph(int n);
    void MakeEmptyGraph(int n);
    bool IsAdjacent(int start_ver, int end_ver);
    LinkedList GetAdjList(int index);
    //todo: handle exception
    void AddEdge(int start_ver, int end_ver, int weight);
    //todo: 
    bool RemoveEdge(int ver1, int ver2);

    //getters and setters
public:
    LinkedList* adj_graph_arr() const
    {
        return adjGraphArr;
    }

    void set_adj_graph_arr(LinkedList* adj_graph_arr)
    {
        adjGraphArr = adj_graph_arr;
    }

    int edges_amount() const
    {
        return edgesAmount;
    }

    void set_edges_amount(int edges_amount)
    {
        edgesAmount = edges_amount;
    }

    int n() const
    {
        return N;
    }

    void set_n(int n)
    {
        N = n;
    }

    int flag_init() const
    {
        return FLAG_INIT;
    }

    void set_flag_init(int flag_init)
    {
        FLAG_INIT = flag_init;
    }

private:
    LinkedList* adjGraphArr; //can replace with vector later
    int edgesAmount;

    
   
    bool edgeExists(int end_ver, int start_ver);
    //needs to clear at destructor
    Node* CreatAdjNode(int value, int weight);
    int N;  // number of nodes in the graph
    int FLAG_INIT = false; //a flag that MakeEmptyGraph wasn't created properly, later to be used with exceptions
    friend ostream& operator<<(ostream& os, const AdjListGraph& graph);
public:
    // Destructor
    ~AdjListGraph();
   
    Node* getAdjListNode(int index, LinkedList adjArrGraph);
    //todo: currently returns node, should return list after created
    LinkedList& operator [](int start_ver);
    LinkedList operator [](int start_ver) const;

    friend ostream& operator<<(ostream& os, const AdjListGraph& graph);
  
    
};




// print all adjacent vertices of given vertex
// inline void display_AdjList(LinkedList list, int vertex);
//
// void printGraph(AdjListGraph graph)
// {
//     cout << "Graph adjacency list " << endl << "(start_vertex, end_vertex, weight):" << endl;
//     for (int i = 0; i < N; i++)
//     {
//         if (graph[i].head != nullptr && graph[i].size > 0)
//             display_AdjList(graph[i], i);
//         else
//             cout << i << " list is empty. " << endl;
//     }
//
// }