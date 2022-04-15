
#include "ExeSolution.h"
#include <vector>
#include <algorithm>


vector<graphEdge> ExeSolution::Kruskel(DiaGraph graph)
{
	int u, v;
	DisjointSet graphSet(graph.edgesAmount);
	vector<graphEdge> weightEdges ,result;

	//LinkedList edgesList = graph.getAdjList(1); //TODO data for all edges?
	sort(weightEdges.begin(), weightEdges.end(), 
	[](const graphEdge& edgeA, const graphEdge& edgeB){	return edgeA.weight > edgeB.weight;}); // TODO qsort?

	for (int i = 0; i < 6 /*for each vertix in graph*/ ; i++) //TODO make arr to vector then use graph.size
		graphSet.MakeSet(i);

	for (auto& edge : weightEdges)
	{
		u = graphSet.Find(edge.start_ver);
		v = graphSet.Find(edge.end_ver);

		if (u != v)
		{
			result.push_back(edge);
			graphSet.UnionBySize(u, v);
		}
	}
	return result;
}



ExeSolution::ExeSolution()
{
}

ExeSolution::~ExeSolution()
{
}
