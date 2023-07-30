#include "ExeSolution.h"
ExeSolution::ExeSolution(string inpuFileName)
{
	removedEdge.starVer = 0; removedEdge.endVer = 0; removedEdge.weight = 0;
	fGraphInput.open(inpuFileName); 
	fResult.open("Out.txt");
}

ExeSolution::~ExeSolution()
{
	fGraphInput.close();
	fResult.close();
	delete graph;
}
#wow good code
int ExeSolution::runProgram(){
	try{
		vector<string> result;
		readData();

		if (!graph->IsConnectedVisit())
		{
			ProgramException e;
			e.isConnected = false;

			result.push_back(s_Kruskal + s_NoMstMsg);
			result.push_back(s_Prim + s_NoMstMsg);
			result.push_back(s_Kruskal2 + s_NoMstMsg);
			throw e;
		}
		else {

			auto kruskalRes1 = Kruskel(*graph); //res[0]
			result.push_back(s_Kruskal + kruskalRes1.second);

			auto prim = Prim(*graph);
			result.push_back(s_Prim + prim.second);

			graph->RemoveEdge(removedEdge.starVer, removedEdge.endVer); // res[1]
			if (!graph->IsConnectedVisit()) {
				result.push_back(s_Kruskal2 + s_NoMstMsg);
			}
			else {
				auto kruskalRes2 = Kruskel(*graph); // res[2]
				result.push_back(s_Kruskal2 + kruskalRes2.second);
			}
		}

		for (const auto& res : result)
		{
			cout << res << endl;
			fResult << res << endl;
		}
	}
	catch(ProgramException& e)
	{
		cout << e.what() << endl;
		fResult << s_Kruskal + s_NoMstMsg << endl;
		fResult << s_Prim + s_NoMstMsg << endl;
		fResult << s_Kruskal2 + s_NoMstMsg << endl;
		//exit(1);
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
		fResult << s_Kruskal + s_NoMstMsg << endl;
		fResult << s_Prim + s_NoMstMsg << endl;
		fResult << s_Kruskal2 + s_NoMstMsg << endl;
		exit(1);
	}
	return 0;
}

void ExeSolution::createGraphFromInput(const int& numVertixInput,const int& numEdgesInput, const vector<graphEdge>& edgesArrInput,const  graphEdge& removedEdgeInput)
{
	graph = new AdjListGraph(numVertixInput);
	graph->vertixAmount = numVertixInput;

	for (int i = 0; i < numEdgesInput; i++)
	{
		graphEdge addedEdge = edgesArrInput[i];
		graph->AddEdge(addedEdge.starVer, addedEdge.endVer, addedEdge.weight);
	}
}

void ExeSolution::updateNumberIfStrIsNumber(string& string, int& number)
{
	if (isNumber(string)) {
		number = stoi(string);
	}
	else
	{
		throw ProgramException();
	}
}

void ExeSolution::readVertixNumberInput(string& line, int& numVertixInput)
{
	getline(fGraphInput, line);
	if (line.empty())
	{
		throw ProgramException();
	}
	updateNumberIfStrIsNumber(line, numVertixInput);
	if (numVertixInput <= 0)
		throw ProgramException();

}

void ExeSolution::readEdgesNumberInput(string& line, int& numEdgesInput)
{
	getline(fGraphInput, line);
	updateNumberIfStrIsNumber(line, numEdgesInput);
	numEdgesInput = stoi(line);
	if (numEdgesInput <= 0)
	{
		throw ProgramException();
	}
}



void ExeSolution::readEdgesArrayInput(string& delimiter, string& line, size_t& posEdge,int& numOfVertixInput, int& numEdgesInput, vector<graphEdge>& edgesArrInput, string& token)
{
	for (int i = 0; i < numEdgesInput; i++)
	{
		int edgeTmp[3] = { -1,-1,-1 };
		getline(fGraphInput, line);
		for (int j = 0; j < 2; j++)
		{
			posEdge = line.find(delimiter);
			token = line.substr(0, posEdge);
			updateNumberIfStrIsNumber(token, edgeTmp[j]); //valida
			edgeTmp[j]--; 
			if (edgeTmp[j] >= numOfVertixInput || edgeTmp[j] < 0) 
				throw ProgramException();
			
			line.erase(0, posEdge + delimiter.length());
			if (line.empty())
				throw ProgramException();
		}
		

		posEdge = line.find(delimiter);
		token = line.substr(0, posEdge);
		updateNumberIfStrIsNumber(token, edgeTmp[2]); //valida
		line.erase(0, posEdge + delimiter.length());
		edgesArrInput.emplace_back(edgeTmp[0], edgeTmp[1], edgeTmp[2]);
	}
}

void ExeSolution::readRemovedEdgeInput(string& delimiter, string& line, size_t& posEdge, string& token, int& numOfVertixInput)
{
	getline(fGraphInput, line);
	int edgeTmp[3] = { -1,-1,-1 };
 	for (int j = 0; j < 2; j++)
	{
		posEdge = line.find(delimiter);
		token = line.substr(0, posEdge);
		updateNumberIfStrIsNumber(token, edgeTmp[j]); //valida
		if (token.empty())
		{
			throw ProgramException();
		}
		edgeTmp[j]--;
		line.erase(0, posEdge + delimiter.length());
		if (edgeTmp[j] >= numOfVertixInput || edgeTmp[j] < 0)
			throw ProgramException();

	}
	removedEdge.starVer = edgeTmp[0];
	removedEdge.endVer = edgeTmp[1];
	line.erase();
}

void ExeSolution::readInputFromFile(string& delimiter, string& line, size_t& posEdge, int& numVertixInput, int& numEdgesInput, vector<graphEdge>& edgesArrInput, graphEdge& removedEdgeInput, string& token)
{
	//(1)Vertix Number:
	readVertixNumberInput(line, numVertixInput);

	//(2)Edges Amount
	readEdgesNumberInput(line, numEdgesInput);

	//(3) edges[] (v1,v2,weight)
	readEdgesArrayInput(delimiter, line, posEdge, numVertixInput, numEdgesInput, edgesArrInput, token);

	//(4) removed edge
	readRemovedEdgeInput(delimiter, line, posEdge, token,numVertixInput);
	getline(fGraphInput, line);
	if (!line.empty())
	{
		throw ProgramException();
	}
}

void ExeSolution::readData()
{
	string token, delimiter = " ", line;
	size_t posEdge = 0;
	int numVertixInput = 0;
	int numEdgesInput = 0;
	vector<graphEdge> edgesArrInput;
	graphEdge removedEdgeInput;

	readInputFromFile(delimiter, line, posEdge, numVertixInput, numEdgesInput, edgesArrInput, removedEdgeInput, token);
	createGraphFromInput(numVertixInput, numEdgesInput, edgesArrInput, removedEdgeInput);
}

void ExeSolution::CreatKruskelEdgesArray(vector<graphEdge>& Edges)
{
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
			graphEdge tmp = graphEdge(i, ptr->nodeId, ptr->weight);
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
	DisjointSet graphSet(graph.vertixAmount);
	vector<graphEdge> Edges;
	pair<vector<graphEdge>, string> result;
	result.second = "0";
	CreatKruskelEdgesArray(Edges);
	quickSort(Edges, 0, Edges.size() - 1);

	for (int i = 0; i < graph.vertixAmount; i++)
		graphSet.MakeSet(i);

	for (auto& Edge : Edges)
	{
		u = graphSet.Find(Edge.starVer);
		v = graphSet.Find(Edge.endVer);

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
		//cout << "deleting current min(ID) : " << minWeightIndex + 1 << endl; // for testing
		
 		inT[minWeightIndex] = true;
		Node* curr_neighbor = graph[minWeightIndex].head;
		
		while (curr_neighbor != nullptr)
		{
			//cout << "Passing neighbor: " << curr_neighbor->nodeId+1 << endl;// for testing
			if (!inT[curr_neighbor->nodeId] && curr_neighbor->weight < min[curr_neighbor->nodeId])
			{
				//cout << "updating neighbor: " << curr_neighbor->nodeId + 1 << endl;// for testing
				min[curr_neighbor->nodeId] = curr_neighbor->weight;
 				p[curr_neighbor->nodeId] = minWeightIndex;
				Q.DecreaseKey(curr_neighbor->nodeId, min[curr_neighbor->nodeId]);
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

bool ExeSolution::isNumber(const string& s)
{
	return !s.empty() && std::find_if(s.begin(),
		s.end(), [](unsigned char c) { return !std::isdigit(c); }) == s.end();
}
