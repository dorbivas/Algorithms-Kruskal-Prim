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
	

	int heapSize;
	int parent(int index) { return (index - 1) / 2; }
	int left(int index) { return (2 * index + 1); }
	int right(int index) { return (2 * index + 2); }
	void fixHeapMin(int node);
	void Swap(HeapNode& pairA, HeapNode& pairB);
	void FloydBuild();
	void reassignWeights(vector<int>& min);

	// void deleteLastLeaf(int ind);
	
public:


	vector<HeapNode> data;
	void Build(vector<int>& min);
	int DeleteMin();
	bool IsEmpty();
	void DecreaseKey(int searchedIndex, int newWeight);

	Heap(int size) : heapSize(size) , data(size) {};
	void insertMin(int item);


	// Weight min() { return data[0]; }
	int getSize() { return heapSize; }
	void  fixHeap(int index);
	void creatEmptyMin();

	// Weight* getData() { return data; }
};

