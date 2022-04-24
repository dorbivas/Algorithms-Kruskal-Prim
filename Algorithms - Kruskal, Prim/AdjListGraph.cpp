// AdjacencyList.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "AdjListGraph.h"


#define N 6 // Number of vertices in the graph

using namespace std;
//
// void printGraph(AdjListGraph graph)
// {
// 	cout << "Graph adjacency list " << endl << "(start_vertex, end_vertex, weight):" << endl;
// 	for (int i = 0; i < N; i++)
// 	{
// 		if (graph[i].head != nullptr && graph[i].size > 0)
// 			display_AdjList(graph[i], i);
// 		else
// 			cout << i << " list is empty. " << endl;
// 	}
//
// }


AdjListGraph::AdjListGraph(int numberOfVector)
{
	MakeEmptyGraph(numberOfVector);
}

AdjListGraph::~AdjListGraph()
{
	for (int i = 0; i < N; i++)
		//todo: delete list
		delete[] adjGraphArr;
}

Node* AdjListGraph::getAdjListNode(int index, LinkedList adjArrGraph)
{
	return adjArrGraph.find(index);
}

LinkedList AdjListGraph::GetAdjList(int index)
{
	return adjGraphArr[index];
}
//Instructions state(forom): MakeEmptyGraph isn't static 

void AdjListGraph::MakeEmptyGraph(int n)
{
	adjGraphArr = new LinkedList[n]();
	// initialize adjGraphArr pointer for all vertices
	FLAG_INIT = true;
	// construct directed graph by adding edges to it
	// point adjGraphArr pointer to new node
	
}

void AdjListGraph::AddEdge(int start_ver, int end_ver, int weight)
{
	if (IsAdjacent(start_ver, end_ver) == true)
	{
		//throw new exception("edge already exists"); 
	}
	else {
		adjGraphArr[start_ver].insertHead(end_ver, weight);
	//	adjGraphArr[end_ver].insertHead(start_ver , weight);
		++edgesAmount;
	}
       
}

LinkedList& AdjListGraph::operator[](int start_ver)
{
	return adjGraphArr[start_ver];
}

LinkedList AdjListGraph::operator[](int start_ver) const
{
	return adjGraphArr[start_ver];
}

bool AdjListGraph::RemoveEdge(int ver1, int ver2)
{
	bool status = true;
	if (edgeExists(ver1, ver2) == true)
	{
		//TODO Remove unnececry prints
		status |= adjGraphArr[ver1].remove(ver2);
		status |= adjGraphArr[ver2].remove(ver1);
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

bool AdjListGraph::IsAdjacent(int start_ver, int end_ver)
{
	return edgeExists(end_ver, start_ver);
	//is end_ver a neighbor in start_Ver adj list
}

bool AdjListGraph::edgeExists(int end_ver, int start_ver)
{
	bool status = false;
	Node* curr = adjGraphArr[start_ver].head;

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

Node* AdjListGraph::CreatAdjNode(int value, int weight)
{
	Node* newNode = new Node();
	newNode->index = value;
	newNode->weight = weight;
	newNode->next = nullptr;   // point new node to current adjGraphArr
	return newNode;
}

ostream& operator<<(ostream& os, const AdjListGraph& graph)
{
	os << "Graph adjacency list " << endl << "(start_vertex, end_vertex, weight):" << endl;
	for (int i = 0; i < N; i++)
	{
		if (graph[i].head != nullptr && graph[i].size > 0)
			os << graph[i];
		else
			os << i << " list is empty. " << endl;
	}
	return os;
}

// void display_AdjList(LinkedList list, int vertex, ostream& os)
// {
// 	Node* ptr = list.head;
// 	while (ptr != nullptr) {
// 		os << "(" << vertex << ", " << ptr->index
// 			<< ", " << ptr->weight << ") ";
// 		ptr = ptr->next;
// 	}
// 	os << endl;
// }
//

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
//		AdjListGraph graph;
//		graph.MakeEmptyGraph(N);
//		graph.AddEdge(1, 2, 3);
//		graph.AddEdge(1, 4, 6);
//		graph.AddEdge(2, 3, 1);
//
//		cout << "(1, 2): " << graph.IsAdjacent(1, 2) << endl; //expected true
//		cout << "(1, 3): " << graph.IsAdjacent(1, 3) << endl; //expected false
//
//		LinkedList list = graph.GetAdjList(1); //expected to return 2 edges linked list
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
