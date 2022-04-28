#pragma once
#include <vector>
#include <filesystem>
#include <istream>
#include <fstream>
#include <sstream>

#include "AdjListGraph.h"
#include "DisjointSet.h"
#include "LinkedList.h"
#include "Heap.h"

using namespace std;

using std::ifstream;
using std::ios;
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ofstream;

class AdjListGraph;
struct graphEdge;

class ExeSolution
{
public:

	int runProgram();	

	ExeSolution(string inpuFileName)
	{
		fGraphInput.open(inpuFileName);
		fResult.open("Out");
		
	}
	bool run_tests(AdjListGraph graph);
	~ExeSolution()
	{
		fGraphInput.close();
		fResult.close();
		delete graph;
	}

	int numVertixInput = 0;
	int numEdgesInput = 0;
	vector<graphEdge> edgesArrInput;
	graphEdge removedEdgeInput;

private:

	ofstream fResult;
	ifstream fGraphInput;


	AdjListGraph* graph;
	void readInputFromFunc(int& numVectors, int& numEdges, vector<graphEdge>& graphEdges, graphEdge& removedEdge);
	void CreatKruskelEdgesArray(AdjListGraph graph, vector<graphEdge>& Edges);
	void readData();
	vector<graphEdge> Kruskel(AdjListGraph graph);
	vector<int> Prim(AdjListGraph graph);
	int partition(vector<graphEdge>& edgesArr, int start, int end);
	void quickSort(vector<graphEdge>& edgesArr, int start, int end);
	#define NO_PARENT -1
};
