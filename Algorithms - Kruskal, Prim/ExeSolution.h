#pragma once
#include <vector>
#include <istream>
#include <fstream>
#include "AdjListGraph.h"
#include "Heap.h"
#include "DisjointSet.h"

using namespace std;

class ExeSolution
{
public:
	int runProgram();
	ExeSolution(string inpuFileName);
	~ExeSolution();

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

	pair<vector<graphEdge>, string> Kruskel(AdjListGraph& graph);
	pair<vector<int>, string> Prim(AdjListGraph& graph);

	void readVertixNumberInput(string& line, int& numVertixInput);
	void readEdgesNumberInput(string& line, int& numEdgesInput);
	void readEdgesArrayInput(string& delimiter, string& line, size_t& posEdge, int& numEdgesInput,
		vector<graphEdge>& edgesArrInput, string& token);
	void readRemovedEdgeInput(string& delimiter, string& line, size_t& posEdge, string& token);
	void createGraphFromInput(const int& numVertixInput, const int& numEdgesInput, const vector<graphEdge>& edgesArrInput, const graphEdge& removedEdgeInput);
	void readInputFromFile(string& delimiter, string& line, size_t& posEdge, int& numVertixInput,
		int& numEdgesInput, vector<graphEdge>& edgesArrInput, graphEdge& removedEdgeInput, string& token);
	void CreatKruskelEdgesArray(vector<graphEdge>& Edges);
	void readData();
	int partition(vector<graphEdge>& edgesArr, int start, int end);
	void quickSort(vector<graphEdge>& edgesArr, int start, int end);
#define NO_PARENT -1
};



