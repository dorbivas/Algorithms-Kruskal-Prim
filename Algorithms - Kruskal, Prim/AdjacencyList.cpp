// AdjacencyList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "AdjacencyList.h" //original

#define N 6 // Number of vertices in the graph

using namespace std;

void printGraph(DiaGraph graph)
{
    cout << "Graph adjacency list " << endl << "(start_vertex, end_vertex, weight):" << endl;
    for (int i = 0; i < N; i++)
    {
        // if (diagraph.head[i] != nullptr) {
        // display adjacent vertices of vertex i
        display_AdjList(graph.GetAdjList(i), i);
            
        // }
    }
}

//tests main
int main()
{
    //Graph graph =(new AdjacencyList(N)); How to do?
    // AdjacencyList* graph = new AdjacencyList(N);

    try {
        //read input into edges
        graphEdge edges[] = {
            // (x, y, w) -> edge from x to y with weight w
            {0,1,2},{0,2,4},{1,4,3},{2,3,2},{3,1,4},{4,3,3}
        };

        // calculate number of edges
        int n = sizeof(edges) / sizeof(graphEdge);
        // DiaGraph diagraph(nullptr, 0, N);

        // construct graph
        // DiaGraph diagraph(edges, n, N);

        DiaGraph graph;
        graph.MakeEmptyGraph(N);
        graph.AddEdge(1, 2, 3);
        graph.AddEdge(1, 4, 6);
        graph.AddEdge(2, 3, 1);
        //  graph.AddEdge(1, 2, 3);
          // cout << graph.IsAdjacent(1, 3); //excptected false
        cout << "(1, 2): " << graph.IsAdjacent(1, 2) << endl; //expected true
        cout << "(1, 3): " << graph.IsAdjacent(1, 3) << endl; //expected false

        LinkedList list = graph.GetAdjList(1); //expected to return 2 edges linked list
        cout << list.head->index << list.head->weight << endl; //print list actually

        printGraph(graph);

       graph.RemoveEdge(1, 2);
        // graph.RemoveEdge(1, 3);
      //  graph.RemoveEdge(1, 4);
      
        // print adjacency list representation of graph
        printGraph(graph);

    }
    catch (exception& e)
    {
        cout << e.what() << std::endl;
    }
    return 0;
    std::cout << "Hello World!\n";

}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
