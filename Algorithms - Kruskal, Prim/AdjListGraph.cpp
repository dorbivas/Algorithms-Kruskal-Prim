#include "AdjListGraph.h"
#include "ProgramException.h"

using namespace std;
//if tree is connected, all neighbors should be visited eventually, since we know it has no cycles,
//we can ensure if all nodes were visited they finish black eventually.

AdjListGraph::~AdjListGraph()
{
	delete[] adjGraphArr;
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

void AdjListGraph::Visit(int vertexId) {

	colorArr[vertexId] = GRAY;
	Node* currNode = adjGraphArr[vertexId].head;
	while (currNode != nullptr) {

		if (currNode->brother->includedFlag != true) //if not brothers
		{
			currNode->brother->includedFlag = true;
			currNode->includedFlag = true;
			if (colorArr[currNode->nodeId] == WHITE) {
				Visit(currNode->nodeId);
			}
		}
		currNode = currNode->next;
	}
	colorArr[vertexId] = BLACK;
}

AdjListGraph::AdjListGraph(const int numberOfVector)
{
	vertixAmount = numberOfVector;
	colorArr = new eColor[vertixAmount];
	MakeEmptyGraph();
}

Node* AdjListGraph::getAdjListNode(const int index, LinkedList adjArrGraph)
{
	return adjArrGraph.find(index);
}

LinkedList& AdjListGraph::GetAdjList(int index) const
{
	return adjGraphArr[index];
}

void AdjListGraph::MakeEmptyGraph()
{
	adjGraphArr = new LinkedList[vertixAmount]();
	FLAG_INIT = true;
}

void AdjListGraph::AddEdge(int start_ver, int end_ver, int weight)
{
	if (IsAdjacent(start_ver, end_ver) == true)
	{
		throw ProgramException();
	}
	else
	{
		adjGraphArr[start_ver].InsertTail(end_ver, weight);
		adjGraphArr[end_ver].InsertTail(start_ver, weight);
		adjGraphArr[end_ver].tail->brother = adjGraphArr[start_ver].tail;
		adjGraphArr[start_ver].tail->brother = adjGraphArr[end_ver].tail;
		++edgesAmount;
	}
}

LinkedList& AdjListGraph::operator[](const int start_ver) const
{
	return adjGraphArr[start_ver];
}

bool AdjListGraph::RemoveEdge(const int startVer, const int endVer)
{
	bool status = true;
	if (this->adjGraphArr != nullptr)
	{
		if (edgeExists(startVer, endVer) == true)
		{
			status |= adjGraphArr[startVer].removeNode(endVer);
			if (status) {
				status |= adjGraphArr[endVer].removeNode(startVer);
				if (status)
					--edgesAmount;
				else
					throw "system fail";
			}
			else
				throw "system fail";
		}
		else {
			status = false;
			throw ProgramException();
		}
	}
	else
		status = false;

	return status;
}


void AdjListGraph::setFlagInit(const int flagInit)
{
	FLAG_INIT = flagInit;
}

bool AdjListGraph::IsAdjacent(const int startVer, const int endVer) const
{
	return edgeExists(endVer, startVer);
}

bool AdjListGraph::edgeExists(const int startVer, const int endVer) const
{
	bool status = false;
	Node* curr = adjGraphArr[startVer].head;

	while (curr != nullptr)
	{
		if (endVer == curr->nodeId)
		{
			status = true;
			break;
		}
		curr = curr->next;
	}

	return status;
}

//next and brother aren't set here because they might not exist yet
Node* AdjListGraph::createAdjNode(const int value, const int weight)
{
	auto newNode = new Node();
	newNode->nodeId = value;
	newNode->weight = weight;
	return newNode;
}

ostream& operator<<(ostream& os, AdjListGraph& graph)
{
	os << "Graph adjacency list " << endl << "(start_vertex, end_vertex, weight):" << endl;
	for (int i = 0; i < graph.vertixAmount; i++)
	{
		if (graph.adjGraphArr[i].head != nullptr)
			os << "VertixId: " << i + 1 << ":" << graph[i] << endl;
		else
			os << i + 1 << " list is empty. " << endl;
	}
	return os;
}

void AdjListGraph::PrintColorArray() const
{
	for (int i = 0; i < vertixAmount; ++i)
	{
		cout << "Index: " << i << " Color: " << colorArr[i] << endl;
	}
}
