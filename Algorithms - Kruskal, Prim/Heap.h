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



typedef int Weight;

class Heap {
private:

	Weight* data;
	int heapSize;
	int parent(int index) { return (index - 1) / 2; }
	int left(int index) { return (2 * index + 1); }
	int right(int index) { return (2 * index + 2); }
	void fixHeapMin(int node);
	void Swap(Weight& pairA, Weight& pairB); 
	
	void deleteLastLeaf(int ind);
public:
	void Build();
	Weight DeleteMin();
	bool IsEmpty();
	void DecreaseKey(int place, int newKey);

	Heap() : heapSize(0) {};
	void insertMin(Weight item);


	Weight min() { return data[0]; }
	int getSize() { return heapSize; }
	void fixBotToTopMin(int index);
	void creatEmptyMin();

	Weight* getData() { return data; }
};

