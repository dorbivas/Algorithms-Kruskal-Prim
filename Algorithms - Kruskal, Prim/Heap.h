#pragma once
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include "AdjListGraph.h"
#include "Heap.h"

using namespace std;
using std::string;
#define MAX_SIZE 100




class Heap {
public:
	struct HeapNode
	{
		unsigned int weight;
		unsigned int index;
	};

private:
	

	// Weight* data;
	
	bool validatePointingTwoWays(); //validates if two way pointers are correct, otherwise exists.
	bool validateHeapSorted();
	int parent(int index) { return (index - 1) / 2; }
	int left(int index) { return (2 * index + 1); }
	int right(int index) { return (2 * index + 2); }
	void  fixHeap(int index);
	
	//void fixHeapMin(int node);
	void FloydBuild();
	void reassignWeights(vector<int>& min);

	// void deleteLastLeaf(int ind);
	
public:
	int heapSize;
	vector<int>nodeIDArr; //nodeID at location x points to the index of nodeID in data.
	vector<HeapNode> data;
	void Build(vector<int>& min);
	int DeleteMin();
	bool IsEmpty();
	bool validateInput(int nodeId);
	void DecreaseKey(int searchedIndex, int newWeight);
	Heap(int size) : heapSize(size) , data(size) {};
	void insertMin(int nodeID, int weight);
	int getSize() { return heapSize; }
	void creatEmptyMin();
};

