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
	int parent(int index) { return (index - 1) / 2; }
	int left(int index) { return (2 * index + 1); }
	int right(int index) { return (2 * index + 2); }
	void  fixHeap(int index);

	void FloydBuild();
	void reassignWeights(vector<int>& min);

	bool validatePointingTwoWays(); //validates if two way pointers are correct, otherwise exits.
	bool validateHeapSorted();

public:
	int heapSize;
	vector<int>nodeIDArr; //nodeID at location x points to the index of nodeID in data.
	vector<HeapNode> data;
	void Build(vector<int>& min);
	int DeleteMin();
	bool IsEmpty();
	bool validateInput(int nodeId);
	void DecreaseKey(int searchedIndex, int newWeight);
	Heap(int size) : heapSize(size), data(size) { };
	int getSize() { return heapSize; }
	void insertMin(int nodeID, int weight);
	void creatEmptyMin(); //todo checl if not use delete
};

