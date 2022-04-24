#pragma once
#include "ExeSolution.h"
#include <vector>
#include <algorithm>
#include "AdjListGraph.h"
#include "Heap.h"
struct graphEdge;
using namespace std;



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

int ExeSolution::runProgram()
{
	try {
		//input
		//kruskal
		//prim
		//removeEdge
		graph = readData();

		Kruskel(*graph);
		Prim(*graph);
		//read input into edges
		Kruskel(*graph);

		//	Prim(*graph);


		run_tests(*graph);





	}
	catch (exception& e)
	{
		cout << e.what() << std::endl;
	}
	return 0;
	cout << "Hello World!\n";
	//read input from file
	//do kruskel
	//do prim
	//remove and do extra logic
}

//1. reads graph from user into AdjGraph
//2. updates graph instance and returns a pointer to it.
AdjListGraph* ExeSolution::readData()
{
	int numVectorsInput;
	int numEdgesInput;
	vector<graphEdge> edgesArrInput;
	graphEdge removed_edgeInput;
	
	//allocate adjListGraph from given data
	readInputFromFunc(numVectorsInput, numVectorsInput, edgesArrInput, removed_edgeInput);
	//todo:  readInputFromFile

	graph = new AdjListGraph(numVectorsInput);
	//allocate adjListGraph from given data


	for (auto graph_edge : edgesArrInput)
	{
		// graph->AddEdge
	}

	return nullptr;
}

void ExeSolution::readInputFromFunc(int& numVectors, int& numEdges, vector<graphEdge> graphEdges, graphEdge& removedEdge)
{
	numVectors = 6;
	numEdges = 9;
	graphEdges.push_back({ 1, 2, 16 });
	graphEdges.push_back({ 1, 2, 13 });
	graphEdges.push_back({ 2, 3, 10 });
	graphEdges.push_back({ 2, 4, 12 });
	graphEdges.push_back({ 4, 3, 9 });
	graphEdges.push_back({ 3, 5, 14 });
	graphEdges.push_back({ 5, 4, 7 });
	graphEdges.push_back({ 5, 6, 4 });
	graphEdges.push_back({ 4, 6, 20 });
	removedEdge = graphEdge(1,3,13);

}

void ExeSolution::createEdgesArray(AdjListGraph graph, int* weightEdges, vector<graphEdge>& Edges)
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
				weightEdges[0] = ptr->weight;
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
					weightEdges[wightInd++] = ptr->weight;
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

vector<graphEdge> ExeSolution::Kruskel(AdjListGraph graph)
{
	int u, v, currWeight = 0;
	DisjointSet graphSet(graph.edges_amount());
	vector<graphEdge> result;

	vector<graphEdge> Edges;
	int* weightEdges = new int(graph.edges_amount());

	createEdgesArray(graph, weightEdges, Edges);
	quickSort(weightEdges, 0, graph.vertixAmount - 1);

	for (int i = 0; i < 6 /*for each vertix in graph*/; i++) //TODO make arr to vector then use graph.size
		graphSet.MakeSet(i);

	for (int i = 0; i < Edges.size(); i++)
	{
		u = graphSet.Find(Edges[i].start_ver);
		v = graphSet.Find(Edges[i].end_ver);

		if (u != v)
		{
			result.push_back(Edges[i]);
			graphSet.UnionBySize(u, v);
		}
	}

	for (int i = 0; i < result.size(); i++)
	{
		currWeight += result[i].weight;
	}

	return result;
}






int ExeSolution::partition(int arr[], int start, int end)

{
	int pivot = arr[start], offset = 0;

	for (int i = start + 1; i <= end; i++)
	{
		if (arr[i] <= pivot)
			offset++;
	}
	int pivotIndex = start + offset;
	swap(arr[pivotIndex], arr[start]);

	int i = start, j = end;

	while (i < pivotIndex && j > pivotIndex) {

		while (arr[i] <= pivot) {
			i++;
		}

		while (arr[j] > pivot) {
			j--;
		}

		if (i < pivotIndex && j > pivotIndex) {
			swap(arr[i++], arr[j--]);
		}
	}

	return pivotIndex;
}

void ExeSolution::quickSort(int arr[], int start, int end)
{
	if (start >= end)
		return;
	int p = partition(arr, start, end);

	quickSort(arr, start, p - 1);
	quickSort(arr, p + 1, end);
}




vector<int> ExeSolution::Prim(AdjListGraph graph)
{
	Heap Q;
	vector<bool> inT; //in tree array
	vector<int> min; //Weight array
	vector<int> p; //parent Array

	min[0] = 0;
	p[0] = 0;

	
	for (int i = 0; i < Q.getSize(); ++i)
	{
		inT[i] = false;
		min[i] = _MAX_INT_DIG;
		p[i] = 0;
	}
	Q.Build();

	while (!Q.IsEmpty())
	{
		int minWeightIndex = Q.DeleteMin();
		inT[minWeightIndex] = true;
		Node* curr_neighbor = graph[minWeightIndex].head;
		while (curr_neighbor)
		{
			if (!inT[curr_neighbor->index] && curr_neighbor->weight < min[curr_neighbor->index])
			{
				min[curr_neighbor->index] = curr_neighbor->weight;
				p[curr_neighbor->weight] = minWeightIndex;
				Q.DecreaseKey(curr_neighbor->index, min[curr_neighbor->index]);
			}
			curr_neighbor = curr_neighbor->next;
		}
	}
	return p;

}
