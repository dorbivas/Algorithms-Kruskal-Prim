#pragma once
#include <iostream>
#include "LinkedList.h"
#include <vector>

using namespace std;

struct graphEdge //TODO syntax CcC
{
    int startVer, endVer, weight;

    graphEdge() {}

    graphEdge(int _startVer, int _endVer, int _weight)
    {
        startVer = _startVer;
        endVer = _endVer;
        weight = _weight;
        
    }
};

class DiaGraph { // DiaGraph <LinkedList[]>
    
    // insert new nodes into adjacency list from given graph
public:

    LinkedList* adjArrGraph;
    int edgesAmount ;
    int vertixAmount = 6;   //TODO

    // structure to store edges

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
            int startVer = edges[i].startVer;
            int endVer = edges[i].endVer;
            int weight = edges[i].weight;
            
            // point adjArrGraph pointer to new node
            adjArrGraph[startVer].insertHead(endVer , weight);
            adjArrGraph[endVer].insertHead(startVer, weight);
        }

    }
    // Destructor
    ~DiaGraph() {
        //for (int i = 0; i < 6 ; i++)
            //todo: delete list
        //delete[] adjArrGraph;
    }

    AdjNode* getAdjListNode(int index, LinkedList adjArrGraph)
    {
        return adjArrGraph.find(index);
    }

    LinkedList getAdjList(int index)
    {
        return adjArrGraph[index];
    }

    void MakeEmptyGraph(int n)
    {
        adjArrGraph = new LinkedList[n]();
        // initialize adjArrGraph pointer for all vertices
       
        FLAG_INIT = true;
        // construct directed graph by adding edges to it
        // point adjArrGraph pointer to new node
    }

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


    void printGraph(DiaGraph graph)
    {
        cout << "Graph adjacency list " << endl << "(startVertex, endVertex, weight):" << endl;
        for (int i = 0; i < 6 ; i++)
        {
            // if (diagraph.head[i] != nullptr) {
            // display adjacent vertices of vertex i

            if (graph[i].head != nullptr && graph[i].size > 0)
                display_AdjList(graph[i], i);
            else
                cout << i << " list is empty. " << endl;
        }

    }

    //todo: handle exception
    void AddEdge(int startVer, int endVer, int weight) 
    {
        if (IsAdjacent(startVer, endVer) == true)
        {
            //throw new exception("edge already exists"); 
        }
        else {
            adjArrGraph[startVer].insertTail(endVer, weight);
            adjArrGraph[endVer].insertTail(startVer , weight);
            ++edgesAmount;

            adjArrGraph[startVer].tail->brother = adjArrGraph[endVer].tail;
            adjArrGraph[endVer].tail->brother = adjArrGraph[startVer].tail;

  
        }
       
    }

    //todo: currently returns node, should return list after created
    LinkedList& operator [](int startVer) {
        return adjArrGraph[startVer];
    }

    LinkedList operator [](int startVer) const {
        return adjArrGraph[startVer];
    }

  /*  LinkedList GetAdjList(int startVer)
    {
        return adjArrGraph[startVer];
    }*/


    //todo: 
    bool RemoveEdge(int ver1, int ver2)
    {
        bool status = true;
        if (edgeExists(ver1, ver2) == true)
        {
            //TODO Remove unnececry prints
            status |= adjArrGraph[ver1].remove(ver2);
            status |= adjArrGraph[ver2].remove(ver1);
            if (status)
                cout << " Deleting the edge: " << "(" << ver1 << ", " << ver2 << ") " << endl;
            else
                cout << " the edge: " << "(" << ver1 << ", " << ver2 << ") " << "does not exist" << endl;

        }
        else
        {
            status = false;
            //todo: throw exception
        }
        //remove from linked list
        return status;
    }

    bool IsAdjacent(int startVer, int endVer)
    {
        return edgeExists(endVer, startVer);
        //is endVer a neighbor in startVer adj list
    }


private:
    bool edgeExists(int endVer, int startVer)
    {
        bool status = false;
        AdjNode* curr = adjArrGraph[startVer].head;

        while (curr != nullptr)
        {
            if (endVer == curr->index)
            {
                status = true;
                break;
            }
            curr = curr->next;
        }

        return status;
    }

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
