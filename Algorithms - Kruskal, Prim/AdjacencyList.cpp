// AdjacencyList.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "AdjacencyList.h" //original

#define N 6 // Number of vertices in the graph

using namespace std;

//tests main
//int main()
//{
//	try {
//		//read input into edges
//		graphEdge edges[] = {
//			// (x, y, w) -> edge from x to y with weight w
//			{0,1,2},{0,2,4},{1,4,3},{2,3,2},{3,1,4},{4,3,3}
//		};
//
//		// calculate number of edges
//		int n = sizeof(edges) / sizeof(graphEdge);
//
//		DiaGraph graph;
//		graph.MakeEmptyGraph(N);
//		graph.AddEdge(1, 2, 3);
//		graph.AddEdge(1, 4, 6);
//		graph.AddEdge(2, 3, 1);
//
//		cout << "(1, 2): " << graph.IsAdjacent(1, 2) << endl; //expected true
//		cout << "(1, 3): " << graph.IsAdjacent(1, 3) << endl; //expected false
//
//		LinkedList list = graph.getAdjList(1); //expected to return 2 edges linked list
//		cout << endl << "this " << list.head->index << " " << list.head->weight << endl; //print list actually
//
//		graph.RemoveEdge(1, 2);
//		graph.RemoveEdge(2, 3);
//
//		printGraph(graph);
//
//	}
//	catch (exception& e)
//	{
//		cout << e.what() << std::endl;
//	}
//	return 0;
//	cout << "Hello World!\n";
//
//}
