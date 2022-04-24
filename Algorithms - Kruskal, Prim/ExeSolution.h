#pragma once
#include <vector>

#include "AdjListGraph.h"
#include "DisjointSet.h"
#include "LinkedList.h"


class AdjListGraph;
struct graphEdge;

class ExeSolution
{
public:
	int runProgram();
	ExeSolution() {};
	bool run_tests(AdjListGraph graph);
	~ExeSolution()
	{
		delete graph;
	}

private:
	
	AdjListGraph* graph = nullptr;
	void readInputFromFunc(int& numVectors, int& numEdges, vector<graphEdge> graphEdges, graphEdge& removedEdge);
	void createEdgesArray(AdjListGraph graph, int* weightEdges, vector<graphEdge>& Edges);
	AdjListGraph* readData();
	vector<graphEdge> Kruskel(AdjListGraph graph);
	vector<int> Prim(AdjListGraph graph);
	int partition(int arr[], int start, int end);
	void quickSort(int arr[], int start, int end);

};
