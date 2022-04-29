#include "Heap.h"
#define NULL -1
//min heap which sorted by the lowest weight  

bool Heap::IsEmpty()
{
	return heapSize == 0;
}

bool Heap::validateInput(int nodeId)
{
	if (nodeId >= data.size() || nodeId < 0)
	{
		cout << "Invalid input at DecreaseKey" << endl;
		exit(1);
	}
	return false;
}

//todo: fix efficiency
void Heap::DecreaseKey(int nodeId, int newKey)
{
	//validatePointingTwoWays();
	//validateHeapSorted();
	//validateInput(nodeId);

	int heapNodeIndex = nodeIDArr[nodeId];
	int lastHeapIndex;

	if (heapNodeIndex > 0) {
		do {
			swap(data[heapNodeIndex], data[parent(heapNodeIndex)]);
			swap(nodeIDArr[data[heapNodeIndex].index], nodeIDArr[data[parent(heapNodeIndex)].index]);
			lastHeapIndex = heapNodeIndex;
			heapNodeIndex /= 2;
		} while (lastHeapIndex > 2);
	}
	data[0].weight = newKey;
	fixHeap(0);
	/*validatePointingTwoWays();
	validateHeapSorted();*/
}

bool Heap::validatePointingTwoWays() {
	bool status = true;
	for (int i = 0; i < heapSize; ++i) {

		status = i == data[nodeIDArr[i]].index; 
		if (!status) {
			
			cout << "index: " << i << " invalid" << endl;
			exit(1);
		
		}
	}
}
bool Heap::validateHeapSorted()
{
	bool status = true;
	for (int i = 0; i < heapSize; ++i) {
		if (left(i) > heapSize || data[i].weight > data[left(i)].weight) {
			status &= false;
		}
		if (right(i) > heapSize || data[i].weight > data[right(i)].weight) {
			status &= false;
		}
		if (!status) {
			cout << "index: " << i << " invalid" << endl;
			exit(1);
		}
		return status;
	}
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
	
	//assign wieghts at nodeId
 
	
	for (int i = 0; i < heapSize; ++i) {
		nodeIDArr.push_back(i);;
	}
	reassignWeights(min);
	FloydBuild();
}

int Heap::DeleteMin() {
	if (heapSize < 1)
	{
		cout << "Invalid input" << endl;
		exit(1);
	}
	
	int delNodeId = data[0].index;
	//validatePointingTwoWays();
	//validateHeapSorted();
	swap(data[0], data[--heapSize]);
	swap(nodeIDArr[data[0].index], nodeIDArr[data[heapSize].index]);

	//data[heapSize].weight = INT_MAX; // infinty
	//data[heapSize].index = UNINIT;
	fixHeap(0);
	//validatePointingTwoWays();
	//validateHeapSorted();
	return(delNodeId);
}

void Heap::fixHeap(int index)
{
	int min;
	int leftIndex = left(index);
	int rightIndex = right(index);

	if ((leftIndex < heapSize) && (data[leftIndex].weight < data[index].weight))
	{
		min = leftIndex;
	}
	else
	{
		min = index;
	}

	if ((rightIndex < heapSize) && (data[rightIndex].weight < data[min].weight))
	{
		min = rightIndex;
	}

	if (min != index)
	{
		swap(nodeIDArr[data[index].index], nodeIDArr[data[min].index]);
		swap(data[index], data[min]);
		fixHeap(min);
	}
}


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
// 
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

// void Heap::deleteLastLeaf(int ind) {
// 	Swap(data[ind], data[--heapSize]);
// 	data[heapSize] = INT_MAX;
// 	fixHeap(ind);
// }
