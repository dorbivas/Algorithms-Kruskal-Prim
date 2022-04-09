#pragma once
#include "LinkedList.h"
#include "AdjacencyList.h"

#include <iostream>
#include<stdio.h>
#include<string>
#include <fstream>
#include <filesystem>

using namespace std;
using std::string;
#define MAX_SIZE 100



class Heap {
private:
	graphEdge** data;
	int heapSize;
	int parent(int index) { return (index - 1) / 2; }
	int left(int index) { return (2 * index + 1); }
	int right(int index) { return (2 * index + 2); }

public:
	Heap() : heapSize(0) {};
	void insertMax(graphEdge* item);
	graphEdge* max() { return data[0]; }
	graphEdge* deleteMax();
	void deleteLastLeaf(int ind);
	void fixHeapMax(int node);
	void mySwap(graphEdge*& pairA, graphEdge*& pairB); //todo


	int getSize() { return heapSize; }
	void fixBotToTopMax(int index);
	void creatEmptyMax();

	graphEdge** getData() { return data; }
};

