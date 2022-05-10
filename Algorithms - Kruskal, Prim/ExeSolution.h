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
		fResult.open("Out.txt");
		
	}
	bool run_tests(AdjListGraph graph);
	~ExeSolution()
	{
		fGraphInput.close();
		fResult.close();
		delete graph;
	}

private:
	const string s_NoMstMsg = "NO MST";
	const string s_Kruskal = "Kruskal ";
	const string s_Prim = "Prim ";
	const string s_Kruskal2 = "Kruskal2 ";
	const string s_invalidInput = "invalid input";

	ofstream fResult;
	ifstream fGraphInput;
	graphEdge removedEdge;
	AdjListGraph* graph = nullptr;
	

	void CreatKruskelEdgesArray(vector<graphEdge>& Edges);
	void readData();
	pair<vector<graphEdge>, string> Kruskel(AdjListGraph& graph);
	pair<vector<int>, string> Prim(AdjListGraph& graph);
	int partition(vector<graphEdge>& edgesArr, int start, int end);
	void quickSort(vector<graphEdge>& edgesArr, int start, int end);
	#define NO_PARENT -1
};



