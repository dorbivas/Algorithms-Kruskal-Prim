// AdjacencyList.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include "AdjListGraph.h"

#include "Utils.h"

#define N 6 // Number of vertices in the graph

using namespace std;
//if tree is connected, all neighbores should be visited eventually, since we know it has no cycles,
//we can ensure if all nodes were visited they finish black eventualy.
bool AdjListGraph::IsConnectedVisit() {

	for (int i = 0; i < vertixAmount; ++i) {
		//colorArr
		colorArr[i] = WHITE;

		//graph arr neighbor list
		Node* currNode = adjGraphArr[i].head;
		while (currNode != nullptr)
		{
			currNode->includedFlag = false;
			currNode->includedFlag = false;
			currNode = currNode->next;
		}
	}
	

	Visit(0);
	
	
	bool status = true;

	for (int i = 0; i < vertixAmount; ++i) {
		if (colorArr[i] == WHITE)
		{
			status = false;
			break;
		}

	}
	return status;
}

void AdjListGraph::PrintColorArray()
{
	for (int i = 0; i < vertixAmount; ++i)
	{
		cout << "Index: " << i << " Color: " << colorArr[i] << endl;
	}
}

void AdjListGraph::Visit(int vertexId) {

	//cout << "Current index visited:" << vertexId << endl << endl; //prints
	//cout << "color status is: " << colorArr[vertexId] << endl << endl; //prints
	//if duplicate ignore
	//cout << "start: " << endl << endl;
	colorArr[vertexId] = GRAY;
	//PrintColorArray();



	Node* currNode = adjGraphArr[vertexId].head;
	//prints
	while (currNode != nullptr) {

		if (currNode->brother->includedFlag != true) //if not brothers
		{
			currNode->brother->includedFlag = true;
			currNode->includedFlag = true;
			if (colorArr[currNode->index] == WHITE) {
				//		cout << "going to neighbor:  " << currNode->index << endl;
				Visit(currNode->index);
				
			}
		}
		currNode = currNode->next;
	}
	colorArr[vertexId] = BLACK;
	//cout << "end: " << endl;
	//PrintColorArray();
}

AdjListGraph::AdjListGraph(int numberOfVector)
{
	colorArr = new eColor[vertixAmount];
	MakeEmptyGraph(numberOfVector);
}

//TODO:
AdjListGraph::~AdjListGraph()
{
	// Node* currentEdge = head;
	// Node* saverEdge = nullptr;

	// for (int i = 0; i < N; i++)
		//todo: delete list
		// adjGraphArr[i].delete();
	// delete[] adjGraphArr;



	// while (currentEdge != nullptr)
	// {
	// 	saverEdge = currentEdge->next;
	// 	delete[] currentEdge;
	// 	currentEdge = saverEdge;
	// }
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
		throw errorMessage("edge already exists");
	}


	else {
		adjGraphArr[start_ver].insertTail(end_ver, weight);
		adjGraphArr[end_ver].insertTail(start_ver, weight);
		adjGraphArr[end_ver].tail->brother = adjGraphArr[start_ver].tail;
		adjGraphArr[start_ver].tail->brother = adjGraphArr[end_ver].tail;
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
	if (this->adjGraphArr != nullptr)
	{
		if (edgeExists(ver1, ver2) == true)
		{
			//TODO Remove unnececry prints
			status |= adjGraphArr[ver1].RemoveFromList(ver2);
			if (status) {
				status |= adjGraphArr[ver2].RemoveFromList(ver1);
				if (status)
				{
				//	cout << " Deleting the edge: " << "(" << ver1 << ", " << ver2 << ") " << endl;

					--edgesAmount;
				}
				else
				{
					throw "system";//print
				}
			}
			else
				throw "system";//print

		}
		else
		{
			status = false;
			//throw "edge not found"; examples show on thrown but ignored
		}
	}
	else {
		status = false;
	}
	return status;
}


void AdjListGraph::setFlagInit(int flag_init)
{
	FLAG_INIT = flag_init;
}

bool AdjListGraph::IsAdjacent(int start_ver, int end_ver)
{
	return edgeExists(end_ver, start_ver);
	//is end_ver a neighbor in start_Ver adj list
}

bool AdjListGraph::edgeExists(int end_ver, int start_ver) const
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

Node* AdjListGraph::createAdjNode(int value, int weight)
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
	for (int i = 0; i < graph.vertixAmount; i++)
	{
		if (graph[i].head != nullptr)
			os << "VertixId: " << i << ":" << graph[i] << endl;
		else
			os << i << " list is empty. " << endl;
	}
	return os;
}
