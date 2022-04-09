#include "Heap.h"

void Heap::fixHeapMax(int node) {
	int max;
	int curr_left = left(node);
	int curr_right = right(node);

	if (curr_right < heapSize && data[curr_right]->weight >= data[node]->weight)
	{
		max = curr_right;
	}
	else
	{
		max = node;
	}
	if (curr_left < heapSize && data[curr_left]->weight >= data[node]->weight)
	{
		max = curr_left;
	}
	if (max != node)
	{
		mySwap(data[node], data[max]);
		fixHeapMax(max);
	}
}

void Heap::mySwap(graphEdge*& pairA, graphEdge*& pairB)
{
	graphEdge* temp = pairA;
	int tempInd = pairB->weight;

	pairA = pairB;
	pairB = temp;

	pairA->weight = pairB->weight;
	pairB->weight = tempInd;
}

graphEdge* Heap::deleteMax() {
	if (heapSize < 1)
	{
		//throw handle exp TODO 
	}
	graphEdge* max = data[0];
	mySwap(data[0], data[--heapSize]);
	data[heapSize] = nullptr;

	fixHeapMax(0);
	return(max);
}

void Heap::deleteLastLeaf(int ind) {
	mySwap(data[ind], data[--heapSize]);
	data[heapSize] = nullptr;
	fixBotToTopMax(ind);
}

void Heap::insertMax(graphEdge* item) {
	int i = heapSize;
	if (heapSize == MAX_SIZE)
	{
		//throw handle exp TODO 
	}
	++heapSize;
	data[i] = item;
	data[i]->weight = i;

	fixBotToTopMax(i);
}

void Heap::fixBotToTopMax(int index) {
	int i = index;
	if (data[i] != nullptr)
	{
		while (i > 0 && data[parent(i)]->weight <= data[i]->weight)
		{
			mySwap(data[i], data[parent(i)]);
			i = parent(i);
		}
	}
}

void Heap::creatEmptyMax() {
	heapSize = 0;

	data = new graphEdge * [MAX_SIZE];

	for (int i = 0; i < MAX_SIZE; i++)
	{
		data[i] = nullptr;
	}
}