#include "Heap.h"




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
void Heap::DecreaseKey(const int nodeId, const int newWeight)
{
	int heapNodeIndex = nodeIDArr[nodeId];

	if (heapNodeIndex > 0)
	{
		int lastHeapIndex;
		do {
			swap(data[heapNodeIndex], data[parent(heapNodeIndex)]); // a[i] = a[p(i)] 
			swap(nodeIDArr[data[heapNodeIndex].index], nodeIDArr[data[parent(heapNodeIndex)].index]);
			lastHeapIndex = heapNodeIndex;
			heapNodeIndex /= 2;
		} while (lastHeapIndex > 2);
	}
	data[0].weight = newWeight;
	fixHeap(0);

}

void Heap::FloydBuild()
{
	for (int i = heapSize / 2; i >= 0; i--)
		fixHeap(i);
}

void Heap::reassignWeights(vector<int>& min)
{
	int i = 0;
	for (HeapNode& node : data)
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
		nodeIDArr.push_back(i);
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
	--heapSize;
	swap(data[0], data[heapSize]);
	swap(nodeIDArr[data[0].index], nodeIDArr[data[heapSize].index]);
	//data[heapSize].weight = INT_MAX; // infinty
	//data[heapSize].index = UNINIT;
	fixHeap(0);
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



bool Heap::validatePointingTwoWays() const
{
	bool status = true;
	for (int i = 0; i < heapSize; ++i) {

		status = i == data[nodeIDArr[i]].index;
		if (!status) {

			cout << "index: " << i << " invalid" << endl;
			exit(1);

		}
	}
	return status;
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
	return false;
}

