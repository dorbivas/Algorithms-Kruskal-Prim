#pragma once
#include <iostream>
#include "LinkedList.h"
using namespace std;
// stores adjacency list items

// structure to store edges
struct graphEdge {
    int start_ver, end_ver, weight;
};
class DiaGraph { // DiaGraph <LinkedList[]>
    
    // insert new nodes into adjacency list from given graph
public:

    LinkedList* adjArrGraph;

    //adjacency list as array of pointers
    // Constructor

    DiaGraph()
    {

    }


    DiaGraph(graphEdge edges[], int vertix_number, int edge_number) {
        // allocate new node
        MakeEmptyGraph(vertix_number);
        // construct directed graph by adding edges to it
        for (unsigned i = 0; i < edge_number; i++) {
            int start_ver = edges[i].start_ver;
            int end_ver = edges[i].end_ver;
            int weight = edges[i].weight;
            // insert in the beginning
            

            // point adjArrGraph pointer to new node
            adjArrGraph[start_ver].insertHead(end_ver , weight);
            adjArrGraph[end_ver].insertHead(start_ver, weight);
        }

    }
    // Destructor
    ~DiaGraph() {
        for (int i = 0; i < N; i++)
            //todo: delete list
        delete[] adjArrGraph;
    }


    void MakeEmptyGraph(int n)
    {
        adjArrGraph = new LinkedList[n]();
        // initialize adjArrGraph pointer for all vertices
       
        FLAG_INIT = true;
        // construct directed graph by adding edges to it
        // point adjArrGraph pointer to new node
    }


    //todo: handle exception
    void AddEdge(int start_ver, int end_ver, int weight)
    {
        if (IsAdjacent(start_ver, end_ver) == true)
        {
            //throw new exception("edge already exists"); 
        }
        else {
            

            adjArrGraph[start_ver].insertHead(end_ver, weight);
            adjArrGraph[end_ver].insertHead(start_ver , weight);
        }
    }

    //todo: currently returns node, should return list after created
    LinkedList GetAdjList(int start_ver)
    {

        return adjArrGraph[start_ver];
    }


    //todo: 
    bool RemoveEdge(int ver1, int ver2)
    {
        bool status = true;
        if (edgeExists(ver1, ver2) == true) {
            status |= adjArrGraph[ver1].remove(ver2);
            status |= adjArrGraph[ver2].remove(ver1);
        }
        else
        {
            status = false;
            //todo: throw exception
        }
        //remove from linked list
        return status;
    }

    bool IsAdjacent(int start_ver, int end_ver)
    {
        return edgeExists(end_ver, start_ver);
        //is end_ver a neighbor in start_Ver adj list
    }


private:
    bool edgeExists(int end_ver, int start_ver)
    {
        bool status = false;
        AdjNode* curr = adjArrGraph[start_ver].head;

        while (curr != nullptr)
        {
            if (end_ver == curr->index)
            {
                status = true;
                break;
            }
            curr = curr->next;
        }

        return status;
    }

    // AdjNode* getAdjListNode(int index, LinkedList adjArrGraph)
    // {
    //     return adjArrGraph.find(index);
    // }

    //needs to clear at destructor
    AdjNode* CreatAdjNode(int value, int weight) {
        AdjNode* newNode = new AdjNode();
        newNode->index = value;
        newNode->weight = weight;
        newNode->next = nullptr;   // point new node to current adjArrGraph
        return newNode;
    }

    int N;  // number of nodes in the graph
    int FLAG_INIT = false; //a flag that MakeEmptyGraph wasn't created properly, later to be used with exceptions
};
// print all adjacent vertices of given vertex
inline void display_AdjList(LinkedList list, int vertex)
{
    AdjNode* ptr = list.head;
    while (ptr != nullptr) {
        cout << "(" << vertex << ", " << ptr->index
            << ", " << ptr->weight << ") ";
        ptr = ptr->next;
    }
    cout << endl;
}
