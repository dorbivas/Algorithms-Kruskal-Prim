#pragma once
#include <iostream>
using namespace std;
// stores adjacency list items
struct AdjNode {
    int val, cost;
    AdjNode* next;
};
// structure to store edges
struct graphEdge {
    int start_ver, end_ver, weight;
};
class DiaGraph {
    // insert new nodes into adjacency list from given graph
public:
    AdjNode** head;
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
            AdjNode* newNode = setAdjListNode(end_ver, weight, head[start_ver]);

            // point head pointer to new node
            head[start_ver] = newNode;
        }

    }
    // Destructor
    ~DiaGraph() {
        for (int i = 0; i < N; i++)
            delete[] head[i];
        delete[] head;
    }


    void MakeEmptyGraph(int n)
    {
        head = new AdjNode * [n]();
        // initialize head pointer for all vertices
        for (int i = 0; i < n; ++i)
            head[i] = nullptr;
        FLAG_INIT = true;
        // construct directed graph by adding edges to it
        // point head pointer to new node
    }


    //todo: handle exception
    void AddEdge(int start_ver, int end_ver, int weight)
    {
        if (IsAdjacent(start_ver, end_ver) == true)
        {
            //throw new exception("edge already exists"); 
        }
        else {

            AdjNode* newNode = setAdjListNode(end_ver, weight, head[start_ver]);
            head[start_ver] = newNode;
        }
    }

    //todo: currently returns node, should return list after created
    AdjNode* GetAdjList(int start_ver)
    {

        return head[start_ver];
    }


    //todo: 
    bool RemoveEdge(int ver1, int ver2)
    {
        //search in both directions
        //remove from linked list
    }

    bool IsAdjacent(int start_ver, int end_ver)
    {
        bool status = false;
        bool ans1 = edgeExists(end_ver, start_ver);
        bool ans2 = edgeExists(start_ver, end_ver);
        status = ans1 || ans2;

        return status;
        //is end_ver a neighbor in start_Ver adj list
    }


private:
    bool edgeExists(int end_ver, int start_ver)
    {
        bool status = false;
        AdjNode* curr = head[start_ver];

        while (curr != nullptr)
        {
            if (end_ver == curr->val)
            {
                status = true;
                break;
            }
            curr = curr->next;
        }

        return status;
    }

    AdjNode* getAdjListNode(int origin, AdjNode* head)
    {

    }

    //needs to clear at destructor
    AdjNode* setAdjListNode(int value, int weight, AdjNode* head) {
        AdjNode* newNode = new AdjNode;
        newNode->val = value;
        newNode->cost = weight;

        newNode->next = head;   // point new node to current head
        return newNode;
    }

    int N;  // number of nodes in the graph
    int FLAG_INIT = false; //a flag that MakeEmptyGraph wasn't created properly, later to be used with exceptions
};
// print all adjacent vertices of given vertex
inline void display_AdjList(AdjNode* ptr, int i)
{
    while (ptr != nullptr) {
        cout << "(" << i << ", " << ptr->val
            << ", " << ptr->cost << ") ";
        ptr = ptr->next;
    }
    cout << endl;
}
