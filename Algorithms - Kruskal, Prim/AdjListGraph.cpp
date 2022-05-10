// AdjacencyList.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include "AdjListGraph.h"
#include "Utils.h"

using namespace std;
//if tree is connected, all neighbores should be visited eventually, since we know it has no cycles,
//we can ensure if all nodes were visited they finish black eventualy.

//TODO: currently not working, doesn't recognize condition
AdjListGraph::~AdjListGraph()
{
	if (adjGraphArr != nullptr) {
		/*	for (int i = 0; i < vertixAmount; i++)
			{
				if (adjGraphArr[i].size != 0) {
					delete &adjGraphArr[i];
				}
			}*/
		delete[] adjGraphArr;
	}
}

bool AdjListGraph::IsConnectedVisit() {

	for (int i = 0; i < vertixAmount; ++i)
	{
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

Node* AdjListGraph::getAdjListNode(int index, LinkedList adjArrGraph)
{
	return adjArrGraph.find(index);
}

LinkedList& AdjListGraph::GetAdjList(int index)
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
	else
	{
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

//LinkedList AdjListGraph::operator[](int starVer) const
//{
//	return adjGraphArr[starVer];
//}

bool AdjListGraph::RemoveEdge(int ver1, int ver2)
{
	bool status = true;
	if (this->adjGraphArr != nullptr)
	{
		if (edgeExists(ver1, ver2) == true)
		{
			//TODO Remove unnececry prints
			status |= adjGraphArr[ver1].removeNode(ver2);
			if (status) {
				status |= adjGraphArr[ver2].removeNode(ver1);
				if (status)
				{
					//	cout << " Deleting the edge: " << "(" << ver1 << ", " << ver2 << ") " << endl;
					--edgesAmount;
				}
				else
					throw "system";//print
			}
			else
				throw "system";//print
		}
		else {
			status = false;
			cout << "edge not found";
		}
	}
	else
		status = false;

	return status;
}


void AdjListGraph::setFlagInit(int flagInit)
{
	FLAG_INIT = flagInit;
}

bool AdjListGraph::IsAdjacent(int starVer, int endVar)
{
	return edgeExists(endVar, starVer);
	//is endVer a neighbor in start_Ver adj list
}

bool AdjListGraph::edgeExists(int endVar, int starVer) const
{
	bool status = false;
	Node* curr = adjGraphArr[starVer].head;

	while (curr != nullptr)
	{
		if (endVar == curr->index)
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

ostream& operator<<(ostream& os, AdjListGraph& graph)
{
	os << "Graph adjacency list " << endl << "(start_vertex, end_vertex, weight):" << endl;
	for (int i = 0; i < graph.vertixAmount; i++)
	{
		if (graph.adjGraphArr[i].head != nullptr)
			os << "VertixId: " << i + 1 << ":" << graph[i] << endl; //why the f does this call the dtor
		else
			os << i + 1 << " list is empty. " << endl;
	}
	return os;
}
