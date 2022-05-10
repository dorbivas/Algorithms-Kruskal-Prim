#pragma once

#include "ExeSolution.h"
#include "Utils.h"

//TODO:
// prim
//check the main that uses files (from CMD)
//dtors 
//final tests


ExeSolution::ExeSolution(string inpuFileName)
{
	removedEdge.start_ver = 0; removedEdge.end_ver = 0, removedEdge.weight = 0;
	fGraphInput.open(inpuFileName);
	fResult.open("Out.txt");
}

ExeSolution::~ExeSolution()
{
	fGraphInput.close();
	fResult.close();
	delete graph;
}

int ExeSolution::runProgram()
{
	try
	{
		readData(); //reads data into graph dto
		cout << *graph;
		vector<string> result;

		if (!graph->IsConnectedVisit())
		{

			result.push_back(s_Kruskal + s_NoMstMsg);
			result.push_back(s_Prim + s_NoMstMsg);
			result.push_back(s_Kruskal2 + s_NoMstMsg);

		}
		else {

			auto kruskalRes1 = Kruskel(*graph); //res[0]
			result.push_back(s_Kruskal + kruskalRes1.second);

			auto prim = Prim(*graph);
			result.push_back(s_Prim + prim.second);

			graph->RemoveEdge(removedEdge.start_ver, removedEdge.end_ver); // res[1]
			cout << *graph;
			if (!graph->IsConnectedVisit()) {
				result.push_back(s_Kruskal2 + s_NoMstMsg);
			}
			else {
				auto kruskalRes2 = Kruskel(*graph); // res[2]
				result.push_back(s_Kruskal2 + kruskalRes2.second);
			}
			
		}

		for (auto res : result)
		{
			cout << res << endl;
			fResult << res << endl;
		}
	}
	catch (exception& e)
	{
		fResult << "NO MST" << endl;
		fResult << "NO MST" << endl;
		fResult << "NO MST" << endl;

		cout << s_invalidInput << endl;
	}
	cout << *graph;
	return 0;
}

void ExeSolution::createGraphFromInput(int& numVertixInput, int& numEdgesInput, vector<graphEdge>& edgesArrInput, graphEdge& removedEdgeInput)
{
	graph = new AdjListGraph(numVertixInput);
	graph->vertixAmount = numVertixInput;

	for (int i = 0; i < numEdgesInput; i++)
	{
		graphEdge addedEdge = edgesArrInput[i];
		graph->AddEdge(addedEdge.start_ver, addedEdge.end_ver, addedEdge.weight);
	}
}


void ExeSolution::readVertixNumberInput(string& line, int& numVertixInput)
{
	getline(fGraphInput, line);
	numVertixInput = stoi(line);
	if (numVertixInput <= 0)
	{
		throw errorMessage(s_invalidInput); 
	}
}

void ExeSolution::readEdgesNumberInput(string& line, int& numEdgesInput)
{
	getline(fGraphInput, line);
	numEdgesInput = stoi(line);
	if (numEdgesInput <= 0)
	{
		throw errorMessage(s_invalidInput);
	}
}

void ExeSolution::readEdgesArrayInput(string& delimiter, string& line, size_t& posEdge, int& numEdgesInput, vector<graphEdge>& edgesArrInput, string& token)
{
	for (int i = 0; i < numEdgesInput; i++)
	{
		int edgeTmp[3] = { -1,-1,-1 };
		getline(fGraphInput, line);
		for (int j = 0; j < 2; j++)
		{
			posEdge = line.find(delimiter);
			token = line.substr(0, posEdge);
			edgeTmp[j] = stoi(token)-1;
			line.erase(0, posEdge + delimiter.length());
		}

		posEdge = line.find(delimiter);
		token = line.substr(0, posEdge);
		edgeTmp[2] = stoi(token);
		line.erase(0, posEdge + delimiter.length());
		edgesArrInput.emplace_back(edgeTmp[0], edgeTmp[1], edgeTmp[2]);
	}
}

void ExeSolution::readRemovedEdgeInput(string& delimiter, string& line, size_t& posEdge, string& token)
{
	getline(fGraphInput, line);
	int edgeTmp[3] = { -1,-1,-1 };
	for (int j = 0; j < 2; j++)
	{
		posEdge = line.find(delimiter);
		token = line.substr(0, posEdge);
		edgeTmp[j] = stoi(token) - 1;
		line.erase(0, posEdge + delimiter.length());
	}

	removedEdge.start_ver = edgeTmp[0];
	removedEdge.end_ver = edgeTmp[1];
	line.erase();

	if (removedEdge.end_ver <= 0 || removedEdge.end_ver <= 0)
		throw errorMessage(s_invalidInput);
}

void ExeSolution::readInputFromFile(string& delimiter, string& line, size_t& posEdge, int& numVertixInput, int& numEdgesInput, vector<graphEdge>& edgesArrInput, graphEdge& removedEdgeInput, string& token)
{
	//(1)Vertix Number:
	readVertixNumberInput(line, numVertixInput);

	//(2)Edges Amount
	readEdgesNumberInput(line, numEdgesInput);

	//(3) edges[] (v1,v2,weight)
	readEdgesArrayInput(delimiter, line, posEdge, numEdgesInput, edgesArrInput, token);

	//(4) removed edge
	readRemovedEdgeInput(delimiter, line, posEdge, token);

}

void ExeSolution::readData()
{
	string delimiter = " ", line;
	size_t posEdge = 0;
	int numVertixInput = 0;
	int numEdgesInput = 0;
	vector<graphEdge> edgesArrInput;
	graphEdge removedEdgeInput;
	string token;

	readInputFromFile(delimiter, line, posEdge, numVertixInput, numEdgesInput, edgesArrInput, removedEdgeInput, token);
	createGraphFromInput(numVertixInput, numEdgesInput, edgesArrInput, removedEdgeInput);
}

void ExeSolution::CreatKruskelEdgesArray(vector<graphEdge>& Edges)
{
	bool flag = false;
	int wightInd = 1, currSize;
	for (int i = 0; i < graph->vertixAmount; i++)
	{
		Node* ptr = graph->GetAdjList(i).head;
		while (ptr != nullptr)
		{
			ptr->includedFlag = false;
			ptr = ptr->next;
		}
	}

	for (int i = 0; i < graph->vertixAmount; i++)
	{
		Node* ptr = graph->GetAdjList(i).head;
		while (ptr != nullptr)
		{
			graphEdge tmp = graphEdge(i, ptr->index, ptr->weight);
			if (ptr->brother->includedFlag == false)
			{
				ptr->brother->includedFlag = ptr->includedFlag = true;
				Edges.push_back(tmp);
			}
			ptr = ptr->next;
		}

	}
}



int ExeSolution::partition(vector<graphEdge>& edgesArr, int start, int end)

{
	int pivotValue = edgesArr[start].weight;
	int pivotPosition = start;

	for (int currPos = start; currPos <= end; ++currPos) {
		if (edgesArr[currPos].weight < pivotValue) {
			swap(edgesArr[pivotPosition + 1], edgesArr[currPos]);
			swap(edgesArr[pivotPosition], edgesArr[pivotPosition + 1]);
			pivotPosition++;
		}
	}

	return pivotPosition;
}

void ExeSolution::quickSort(vector<graphEdge>& edgesArr, int start, int end)
{
	if (start < end)
	{
		int p = partition(edgesArr, start, end);
		quickSort(edgesArr, start, p - 1);
		quickSort(edgesArr, p + 1, end);
	}

	return;
}


pair<vector<graphEdge>, string> ExeSolution::Kruskel(AdjListGraph& graph)
{
	int u, v, currWeight = 0;
	DisjointSet graphSet(graph.edgesAmount);
	vector<graphEdge>  Edges;
	pair<vector<graphEdge>, string> result;
	result.second = "0";
	CreatKruskelEdgesArray(Edges); 
	quickSort(Edges, 0, Edges.size() - 1);

	for (int i = 0; i < graph.vertixAmount ; i++) 
		graphSet.MakeSet(i);

	for (auto& Edge : Edges)
	{
		u = graphSet.Find(Edge.start_ver);
		v = graphSet.Find(Edge.end_ver);

		if (u != v && u != -1 && v != -1)
		{
			result.first.push_back(Edge);
			graphSet.UnionBySize(u, v);
		}
	}

	for (auto& i : result.first)
	{
		currWeight += i.weight;
	}
	result.second = to_string(currWeight);
	return result;
}

pair<vector<int>, string> ExeSolution::Prim(AdjListGraph& graph)
{

	Heap Q(graph.vertixAmount);
	vector<bool> inT(graph.vertixAmount); //in tree array
	vector<int> min(graph.vertixAmount); //Weight array
	vector<int> p(graph.vertixAmount); //parent Array

	min.front() = 0;
	p.front() = NO_PARENT;
	int currMinWeight = 0;
	for (int i = 1; i < graph.vertixAmount; ++i)
	{
		inT[i] = false;
		min[i] = INT_MAX;
		p[i] = NO_PARENT;
	}
	Q.Build(min);

	while (!Q.IsEmpty())
	{
		int minWeightIndex = Q.DeleteMin();
		//cout << "deleting current min(ID) : " << minWeightIndex + 1 << endl;
		inT[minWeightIndex] = true;
		Node* curr_neighbor = graph[minWeightIndex].head;
		while (curr_neighbor != nullptr)
		{
			//cout << "Passing neighbor: " << curr_neighbor->index + 1 << endl;
			if (!inT[curr_neighbor->index] && curr_neighbor->weight < min[curr_neighbor->index])
			{
				min[curr_neighbor->index] = curr_neighbor->weight;
				p[curr_neighbor->index] = minWeightIndex; // initiate parents to null
				Q.DecreaseKey(curr_neighbor->index, min[curr_neighbor->index]);
			}
			curr_neighbor = curr_neighbor->next;
		}
	}
	for (auto vertix : min) {
		currMinWeight += vertix;
	}


	pair<vector<int>, string> res;
	res.second = to_string(currMinWeight);
	res.first = p;
	return res;

}
