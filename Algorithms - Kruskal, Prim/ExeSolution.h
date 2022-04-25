#pragma once
#include <vector>

#include "AdjListGraph.h"
#include "DisjointSet.h"
#include "LinkedList.h"
#include "Heap.h"

class AdjListGraph;
struct graphEdge;

class ExeSolution
{
public:
	int runProgram();
	ExeSolution() = default;;
	bool run_tests(AdjListGraph graph);
	~ExeSolution()
	{
		delete graph;
	}

private:
	
	AdjListGraph* graph = nullptr;
	void readInputFromFunc(int& numVectors, int& numEdges, vector<graphEdge>& graphEdges, graphEdge& removedEdge);
	void createEdgesArray(AdjListGraph graph, vector<graphEdge>& Edges);
	AdjListGraph* readData();
	vector<graphEdge> Kruskel(AdjListGraph graph);
	vector<int> Prim(AdjListGraph graph);
	int partition(vector<graphEdge>& edgesArr, int start, int end);
	void quickSort(vector<graphEdge>& edgesArr, int start, int end);

};
