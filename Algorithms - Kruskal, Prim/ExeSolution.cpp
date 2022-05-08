#pragma once
#include "ExeSolution.h"
#include "Utils.h"

//TODO:
// V     ***delete edge is acting weird - needs fixing (test with test1.txt)***
//go ever kruskal, prim and graph efficiency
// ***partly done*** handle errors
//			- to file ?
//			- error format
//			- place in catch write to file or console ?
// 
//test output file
// 
//V    ***create main **
//if desired for easier testing - you can use graph print operator(to see for example delete from edge isn't working)

int ExeSolution::runProgram()
{
	
	string s_NoMstMsg = "NO MST";
	string s_Kruskal = "Kruskal ";
	string s_Prim = "Prim ";
	string s_Kruskal2 = "Kruskal2 ";

	try {
		readData(); //todo: read from user
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

			graph->RemoveEdge(removedEdge.start_ver, removedEdge.end_ver); // TODO this is not working i think
			cout << *graph;
			if (!graph->IsConnectedVisit()) {
				result.push_back(s_Kruskal2 + s_NoMstMsg);
			}
			else {
				auto kruskalRes2 = Kruskel(*graph); // res[2]
				result.push_back(s_Kruskal2 + kruskalRes2.second);
			}

		}
		//PrintGraphWeights(resultsArr[0], resultArr[1], resultsArr[2]);
		for (auto res : result)
		{
			cout << res << endl;
			fResult << res << endl;
		}
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}


	return 0;
}

void ExeSolution::createGraphFromInput(int& numVertixInput, int& numEdgesInput, vector<graphEdge>& edgesArrInput, graphEdge& removedEdgeInput)
{
	graph = new AdjListGraph(numVertixInput);
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
		throw errorMessage("invalid input"); //todo: const
	}
}

void ExeSolution::readEdgesNumberInput(string& line, int& numEdgesInput)
{
	getline(fGraphInput, line);
	numEdgesInput = stoi(line);
	if (numEdgesInput <= 0)
	{
		throw errorMessage("invalid input");
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
		edgesArrInput.emplace_back(edgeTmp[0]-1, edgeTmp[1]-1, edgeTmp[2]);
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
		throw errorMessage("invalid input");
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

//vertix 0-9 
//edge 0-9
//edges (start, end, weight)

/*
*
8
10
1 2 1
2 3 3
2 4 4
2 5 2
3 4 4
4 5 1
5 6 1
5 8 5
6 7 3
7 8 4
1 3

*/
//
//void readEdgeLine(string line, graphEdge& edge)
//{
//	string delimiter = " ";
//	size_t pos = 0;
//	pos = line.find(delimiter);
//	line.erase(0, pos + delimiter.length()); //delete date
//
//	pos = line.find(delimiter);
//	edge.start_ver = getOneParam(delimiter, line, pos);
//	edge.end_ver = getOneParam(delimiter, line, pos);
//	edge.weight = getOneParam(delimiter, line, pos);
//
//}
//
//int getOneParam(string delimiter, string& line, size_t& pos)
//{
//	string token = line.substr(0, pos);
//	line.erase(0, pos + delimiter.length());
//	pos = line.find(delimiter);
//	return stoi(token);
//}



void ExeSolution::readInputFromFunc(int& numVectors, int& numEdges, vector<graphEdge>& graphEdges, graphEdge& removedEdge)
{
	numVectors = 6;
	numEdges = 9;
	graphEdges.emplace_back(0, 1, 16);
	graphEdges.emplace_back(0, 2, 13);
	graphEdges.emplace_back(1, 2, 10);
	graphEdges.emplace_back(1, 3, 12);
	graphEdges.emplace_back(3, 2, 9);
	graphEdges.emplace_back(2, 4, 14);
	graphEdges.emplace_back(4, 3, 7);
	graphEdges.emplace_back(4, 5, 4);
	graphEdges.emplace_back(3, 5, 20);
	removedEdge = graphEdge(0, 1, 13);

}

void ExeSolution::CreatKruskelEdgesArray(AdjListGraph graph, vector<graphEdge>& Edges)
{
	bool flag = false;
	int wightInd = 1;

	for (int i = 0; i < graph.vertixAmount; i++)
	{
		Node* ptr = graph[i].head;
		while (ptr != nullptr)
		{

			graphEdge tmp = graphEdge(i, ptr->index, ptr->weight);
			if (Edges.capacity() == 0)
			{
				Edges.push_back(tmp);
			}
			else
			{
				int currSize = Edges.size();
				for (int i = 0; i < currSize; i++)
				{
					graphEdge edge = Edges[i];
					flag |= (tmp.end_ver == edge.start_ver && tmp.start_ver == edge.end_ver);
				}
				if (flag == false)
				{
					Edges.push_back(tmp);
				}
				else // flag == true
				{
					flag = false;
				}
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

pair<vector<graphEdge>, string> ExeSolution::Kruskel(AdjListGraph graph)
{

	int u, v, currWeight = 0;
	DisjointSet graphSet(graph.edgesAmount);
	vector<graphEdge>  Edges;
	pair<vector<graphEdge>, string> result;
	result.second = "0";
	CreatKruskelEdgesArray(graph, Edges);
	quickSort(Edges, 0, Edges.size() - 1);

	for (int i = 0; i < 6 /*for each vertix in graph*/; i++) //todo: make arr to vector then use graph.size
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
	//calculate tree weight
	return result;
}

pair<vector<int>, string> ExeSolution::Prim(AdjListGraph graph)
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
		//cout << "deleting current min(ID) : " << minWeightIndex << endl;
		inT[minWeightIndex] = true;
		Node* curr_neighbor = graph[minWeightIndex].head;
		while (curr_neighbor)
		{
			//cout << "Passing neighbor: " << curr_neighbor->index << endl;
			if (!inT[curr_neighbor->index] && curr_neighbor->weight < min[curr_neighbor->index])
			{
				min[curr_neighbor->index] = curr_neighbor->weight;
				p[curr_neighbor->index] = minWeightIndex; //todo: initiate parents to null
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
bool ExeSolution::run_tests(AdjListGraph graph)
{
	cout << "(1, 2): " << graph.IsAdjacent(1, 2) << endl; //expected true
	cout << "(1, 3): " << graph.IsAdjacent(1, 3) << endl; //expected false

	LinkedList list = graph.GetAdjList(1); //expected to return 2 edges linked list
	cout << endl << "this " << list.head->index << " " << list.head->weight << endl; //print list actually

	graph.RemoveEdge(1, 2);
	graph.RemoveEdge(2, 3);

	return true;
}