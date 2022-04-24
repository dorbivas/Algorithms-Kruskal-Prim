#pragma once
#include "LinkedList.h"

#include <iostream>
#include<stdio.h>
#include<string>
#include <fstream>
#include <filesystem>
#include <vector>

using namespace std;
using std::string;
#define MAX_SIZE 100




class Heap {
private:
	struct HeapNode
	{
		unsigned int weight;
		unsigned int index;
	};

	// Weight* data;
	vector<HeapNode> data;

	int heapSize;
	int parent(int index) { return (index - 1) / 2; }
	int left(int index) { return (2 * index + 1); }
	int right(int index) { return (2 * index + 2); }
	void fixHeapMin(int node);
	void Swap(HeapNode& pairA, HeapNode& pairB); 
	
	// void deleteLastLeaf(int ind);
	
public:

	void Build();
	int DeleteMin();
	bool IsEmpty();
	void DecreaseKey(int searchedIndex, int newWeight);

	Heap() : heapSize(0) {};
	void insertMin(int item);


	// Weight min() { return data[0]; }
	int getSize() { return heapSize; }
	void  fixBotToTopMin(int index);
	void creatEmptyMin();

	// Weight* getData() { return data; }
};

