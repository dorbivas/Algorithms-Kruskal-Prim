
#include "ExeSolution.h"




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
		cout << "test" << endl;
		//Kruskel(*graph);
		Prim(*graph);
		//read input into edges


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
	//RemoveFromList and do extra logic
}

//1. reads graph from user into AdjGraph
//2. updates graph instance and returns a pointer to it.
AdjListGraph* ExeSolution::readData()
{
	int numVectorsInput =0;
	int numEdgesInput =0;
	vector<graphEdge> edgesArrInput;
	graphEdge removed_edgeInput;

	//allocate adjListGraph from given data
	readInputFromFunc(numVectorsInput, numVectorsInput, edgesArrInput, removed_edgeInput);
	//todo:  readInputFromFile

	graph = new AdjListGraph(numVectorsInput);
	//allocate adjListGraph from given data


	for (auto graph_edge : edgesArrInput)
	{
		graph->AddEdge(graph_edge.end_ver, graph_edge.start_ver, graph_edge.weight);
	}

	
	return graph;
}

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

void ExeSolution::createEdgesArray(AdjListGraph graph, vector<graphEdge>& Edges)
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

vector<graphEdge> ExeSolution::Kruskel(AdjListGraph graph)
{
	int u, v, currWeight = 0;
	DisjointSet graphSet(graph.edgesAmount);
	vector<graphEdge> result;

	vector<graphEdge> Edges;

	createEdgesArray(graph, Edges);
	quickSort(Edges, 0,Edges.size() - 1);

	for (int i = 0; i < 6 /*for each vertix in graph*/; i++) //todo: make arr to vector then use graph.size
		graphSet.MakeSet(i);

	for (auto& Edge : Edges)
	{
		u = graphSet.Find(Edge.start_ver);
		v = graphSet.Find(Edge.end_ver);

		if (u != v && u != -1 && v != -1)
		{
			result.push_back(Edge);
			graphSet.UnionBySize(u, v);
		}
	}

	for (auto& i : result)
	{
		currWeight += i.weight;
	}

	return result;
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

vector<int> ExeSolution::Prim(AdjListGraph graph)
{
	
	Heap Q(6);
	vector<bool> inT(graph.vertixAmount); //in tree array
	vector<int> min(graph.vertixAmount); //Weight array
	vector<int> p(graph.vertixAmount); //parent Array
	
	min.front() = 0;
	p.front() = NO_PARENT;

	for (int i = 1; i < graph.vertixAmount; ++i)
	{
		inT[i] = false;
		min[i] =  INT_MAX;
		p[i] = NO_PARENT;
	}
	Q.Build(min);

	while (!Q.IsEmpty())
	{
		
		int minWeightIndex = Q.DeleteMin();
		cout << "deleting current min(ID) : " << minWeightIndex << endl;
		inT[minWeightIndex] = true;
		Node* curr_neighbor = graph[minWeightIndex].head;
		while (curr_neighbor)
		{
			cout << "Passing neighbor: " << curr_neighbor->index << endl;
			if (!inT[curr_neighbor->index] && curr_neighbor->weight < min[curr_neighbor->index])
			{
				min[curr_neighbor->index] = curr_neighbor->weight;
				p[curr_neighbor->index] = minWeightIndex; //todo: initiate parents to null
				Q.DecreaseKey(curr_neighbor->index, min[curr_neighbor->index]);
			}
			curr_neighbor = curr_neighbor->next;
		}
	}
	return p;

}
