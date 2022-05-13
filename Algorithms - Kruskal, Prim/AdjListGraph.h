#pragma once
#include <iostream>
#include "LinkedList.h"

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

	AdjListGraph(int numberOfVector);
	~AdjListGraph();

	
	void MakeEmptyGraph();
	bool IsAdjacent(int startVer, int endVer) const;
	void AddEdge(int start_ver, int end_ver, int weight);
	bool RemoveEdge(int startVer, int endVer);
	
	bool IsConnectedVisit();
	void PrintColorArray() const;
	LinkedList& GetAdjList(int index) const;
	
	Node* getAdjListNode(int index, LinkedList adjArrGraph);
	LinkedList& operator [](int start_ver) const;
	friend ostream& operator<<(ostream& os, AdjListGraph& graph);

private:
	enum eColor { WHITE, GRAY, BLACK };
	LinkedList* adjGraphArr;
	eColor* colorArr;
	int FLAG_INIT = false; 

	void Visit(int vertexId);
	bool edgeExists(int startVer, int endVer) const;
	static Node* createAdjNode(int value, int weight);
	void setFlagInit(int flagInit);
	friend ostream& operator<<(ostream& os, const AdjListGraph& graph);
};

