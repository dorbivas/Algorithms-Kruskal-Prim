#pragma once
#include <iostream>
#include "LinkedList.h"
#include <vector>
using namespace std;

// structure to store edges
struct graphEdge {
	int starVer, endVer, weight;
	graphEdge() {}

	graphEdge(int _startVer, int _endVer, int _weight) : starVer(_startVer), endVer(_endVer), weight(_weight)
	{}
};

class AdjListGraph {
public:
	int vertixAmount;
	int edgesAmount;

	LinkedList& GetAdjList(int index);
	AdjListGraph(int n);
	void MakeEmptyGraph(int n);
	bool IsAdjacent(int start_ver, int end_ver);
	void AddEdge(int start_ver, int end_ver, int weight);
	bool RemoveEdge(int ver1, int ver2);
	void setFlagInit(int flag_init);
	bool IsConnectedVisit();
	void PrintColorArray();

	~AdjListGraph();
	//todo: currently returns node, should return list after created
	/*LinkedList operator [](int starVer) const;*/
	Node* getAdjListNode(int index, LinkedList adjArrGraph);
	LinkedList& operator [](int start_ver);
	friend ostream& operator<<(ostream& os, AdjListGraph& graph);

private:
	enum eColor { WHITE, GRAY, BLACK };
	LinkedList* adjGraphArr;
	eColor* colorArr;
	int FLAG_INIT = false; //a flag that MakeEmptyGraph wasn't created properly, later to be used with exceptions

	void Visit(int vertexId);
	bool edgeExists(int end_ver, int start_ver) const;
	//needs to clear at destructor
	static Node* createAdjNode(int value, int weight);
	friend ostream& operator<<(ostream& os, const AdjListGraph& graph);
};
