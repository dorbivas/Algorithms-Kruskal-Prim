#include "Heap.h"

//min heap which sorted by the lowest weight  

bool Heap::IsEmpty()
{
	return heapSize == 0;
}

//todo: fix efficiency
void Heap::DecreaseKey(int searchedIndex, int newWeight)
{
	if (searchedIndex >= data.size() || searchedIndex < 0)
	{
		cout << "Invalid input" << endl;
		exit(1);
	}
	while ((searchedIndex > 0) && data[parent(searchedIndex)].weight >newWeight)
	{
		
	}

	vector<HeapNode>::iterator ptr = data.begin();

	for (auto& heap_node : data)
	{
		if (heap_node.index == searchedIndex)
		{
			//delete from data:
			//insert to to data
		
			heap_node.weight = newWeight;

			break;
		}
	}
	
	//(data[searchedIndex].weight < newWeight)
	//find in heap, change 
}



void Heap::Swap(Heap::HeapNode& pairA, Heap::HeapNode& pairB)
 {
	Heap::HeapNode temp = pairA;
	pairA = pairB;
	pairB = temp;
}


void Heap::FloydBuild()
{
	for (int i = heapSize/2; i >= 0; i--)
		fixHeap(i);
}

void Heap::reassignWeights(vector<int>& min)
{
	int i = 0;
	for (HeapNode& node: data)
	{
		node.weight = min[i];
		node.index = i++;
	}
}

//assumes heapSize is correct
void Heap::Build(vector<int>& min)
{
	reassignWeights(min);
	FloydBuild();
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
// 	fixHeap(ind);
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
// 	fixHeap(i);
// }

//void Heap::fixHeap(int index) {
//	int i = index;
//	if (data[i].weight != INT_MAX)
//	{
//		while (i > 0 && data[parent(i)].weight >= data[i].weight)
//		{
//			Swap(data[i], data[parent(i)]);
//			i = parent(i);
//		}
//	}
//}

void Heap::fixHeap(int index)
{
	int min;
	int leftIndex = left(index);
	int rightIndex = right(index);

	if ((leftIndex < data.size()) && (data[leftIndex].weight < data[index].weight))
	{
		min = leftIndex;
	}
	else
	{
		min = index;
	}

	if ((rightIndex < data.size()) && (data[rightIndex].weight < data[min].weight))
	{
		min = rightIndex;
	}

	if (min != index)
	{
		swap(data[index], data[min]);
		//swap(indenciesArr[data[index].data - 1], indenciesArr[data[min].data - 1]);

		fixHeap(min);
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