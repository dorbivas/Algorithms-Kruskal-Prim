#include "DisjointSet.h"

#include "Utils.h"

DisjointSet::DisjointSet(int arrSize) : parentsArr(arrSize)
{
	for (int i = 0; i < arrSize; i++)
	{
		parentsArr[i].parent = -1;
		parentsArr[i].arrSize = 0;
	}
}

int DisjointSet::Find(int index)
{
	if (index > arrSize)
	{
		throw ProgramException();
	}
	else if (parentsArr[index].parent == index || index == -1)
	{
		return index;
	}
	else
	{
		parentsArr[index].parent = Find(parentsArr[index].parent); //path compression
		return parentsArr[index].parent;
	}
}

void DisjointSet::UnionBySize(int aSet, int bSet)
{
	if (parentsArr[aSet].arrSize > parentsArr[bSet].arrSize)
	{
		parentsArr[bSet].parent = aSet;
		parentsArr[aSet].arrSize += parentsArr[bSet].arrSize;
	}
	else {
		parentsArr[aSet].parent = bSet;
		parentsArr[bSet].arrSize += parentsArr[aSet].arrSize;
	}
}

void DisjointSet::MakeSet(int index)
{
	parentsArr[index].parent = index;
	parentsArr[index].arrSize = 1;
	++arrSize;
}
