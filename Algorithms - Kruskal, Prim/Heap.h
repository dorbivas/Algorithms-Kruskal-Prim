#pragma once
#include <vector>
#include "Heap.h"
#include <iostream>
#include <ostream>

using namespace std;


#define MAX_SIZE 100

class Heap {
public:
	struct HeapNode
	{
		unsigned int weight;
		unsigned int nodeId;
	};

private:
	int parent(int index) { return (index - 1) / 2; }
	int left(int index) { return (2 * index + 1); }
	int right(int index) { return (2 * index + 2); }
	void  fixHeap(int index);

	void FloydBuild();
	void reassignWeights(vector<int>& min);

	bool validatePointingTwoWays() const; //validates if two way pointers are correct, otherwise exits.
	bool validateHeapSorted();

public:
	Heap(int size) : heapSize(size), data(size) { }; //no dtor needed as nothing is dynamic
	int heapSize;
	vector<int>nodeIDArr; //nodeID at location x points to the nodeId of nodeID in data.
	vector<HeapNode> data;
	void Build(vector<int>& min);
	int DeleteMin();
	bool IsEmpty();
	bool validateInput(int nodeId);
	void DecreaseKey(int searchedIndex, int newWeight);
	
	int getSize() { return heapSize; }
	void insertMin(int nodeID, int weight);
	void creatEmptyMin(); //todo checl if not use delete
};

