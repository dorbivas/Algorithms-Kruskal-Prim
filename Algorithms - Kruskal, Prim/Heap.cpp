#include "Heap.h"

//min heap which sorted by the lowest weight  

bool Heap::IsEmpty()
{
	return heapSize == 0;
}

//todo: fix efficiency
void Heap::DecreaseKey(int searchedIndex, int newWeight)
{
	for (auto heap_node : data)
	{
		if (heap_node.index == searchedIndex)
		{
			heap_node.weight = newWeight;
		}
	}
	//(data[searchedIndex].weight < newWeight)
	//find in heap, change 
}

void Heap::fixHeapMin(int node) {
	int min;
	int curr_left = left(node);
	int curr_right = right(node);


	if (curr_right < heapSize && data[curr_right].weight <= data[node].weight)
	{
		min = curr_right;
	}
	else
	{
		min = node;
	}
	if (curr_left < heapSize && data[curr_left].weight <= data[node].weight)
	{
		min = curr_left;
	}
	if (min != node)
	{
		Swap(data[node], data[min]);
		fixHeapMin(min);
	}
}

void Heap::Swap(Heap::HeapNode& pairA, Heap::HeapNode& pairB)
{
	Heap::HeapNode temp = pairA;
	pairA = pairB;
	pairB = temp;
}

void Heap::Build()
{
	for (int i = heapSize/2; i >= 0; i--)
		fixBotToTopMin(i);
}

int Heap::DeleteMin() {
	if (heapSize < 1)
	{
		//throw handle exp TODO 
	}
	HeapNode min = data[0];

	Swap(data[0], data[--heapSize]);
	data[heapSize].weight = INT_MAX; // infinty
	data[heapSize].index = UNINIT;
	fixHeapMin(0);
	return(min.index);
}

// void Heap::deleteLastLeaf(int ind) {
// 	Swap(data[ind], data[--heapSize]);
// 	data[heapSize] = INT_MAX;
// 	fixBotToTopMin(ind);
// }

// void Heap::insertMin(Weight item) {
// 	int i = heapSize;
// 	if (heapSize == MAX_SIZE)
// 	{
// 		//throw handle exp TODO 
// 	}
// 	++heapSize;
// 	data[i] = item;
// 	data[i] = i;
//
// 	fixBotToTopMin(i);
// }

void Heap::fixBotToTopMin(int index) {
	int i = index;
	if (data[i].weight != INT_MAX)
	{
		while (i > 0 && data[parent(i)].weight >= data[i].weight)
		{
			Swap(data[i], data[parent(i)]);
			i = parent(i);
		}
	}
}

// void Heap::creatEmptyMin() {
// 	heapSize = 0;
//
// 	data = new Weight [MAX_SIZE];
//
// 	for (int i = 0; i < MAX_SIZE; i++)
// 	{
// 		data[i] = INT_MAX; //
// 	}
// }