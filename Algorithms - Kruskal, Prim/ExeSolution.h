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
	void createGraphFromInput(int& numVertixInput, int& numEdgesInput, vector<graphEdge>&edgesArrInput, graphEdge& removedEdgeInput);
	void readVertixNumberInput(string& line, int& numVertixInput);
	void readEdgesNumberInput(string& line, int& numEdgesInput);
	void readEdgesArrayInput(string& delimiter, string& line, size_t& posEdge, int& numEdgesInput,
	                         vector<graphEdge>& edgesArrInput, string& token);
	void readRemovedEdgeInput(string& delimiter, string& line, size_t& posEdge, string& token);

	void readInputFromFile(string& delimiter, string& line, size_t& posEdge, int& numVertixInput,
	                       int& numEdgesInput, vector<graphEdge>& edgesArrInput, graphEdge& removedEdgeInput, string& token);

	ExeSolution(string inpuFileName)
	{
		removedEdge.start_ver = 0; removedEdge.end_ver = 0, removedEdge.weight = 0;
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

private:

	ofstream fResult;
	ifstream fGraphInput;
	void readEdgeLine();
	graphEdge removedEdge;
	AdjListGraph* graph = nullptr;
	void readInputFromFunc(int& numVectors, int& numEdges, vector<graphEdge>& graphEdges, graphEdge& removedEdge);
	void CreatKruskelEdgesArray(AdjListGraph graph, vector<graphEdge>& Edges);
	void readData();
	pair<vector<graphEdge>, string> Kruskel(AdjListGraph graph);
	pair<vector<int>, string> Prim(AdjListGraph graph);
	int partition(vector<graphEdge>& edgesArr, int start, int end);
	void quickSort(vector<graphEdge>& edgesArr, int start, int end);
	#define NO_PARENT -1
};



