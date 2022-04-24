
#include "DisjointSet.h"
#include "LinkedList.h"

// //tests main
// int main()
// {
// 	DisjointSet set(3);
// 	
// 	for (int i = 0; i < 3; i++)
// 	{
// 		set.MakeSet(i);
//
// 	}
// 	for (int i = 0; i < 2; i++)
// 	{
// 		set.UnionBySize(i, i + 1);
//
// 	}
// 	cout << set.Find(1);
// 	cout << set.Find(2);
// }

void DisjointSet::pathCompression()
{
		
}

DisjointSet::DisjointSet(int arrSize)
{

	parentsArr = new Element[arrSize];

	for (int i = 0; i < arrSize; i++) 
	{
		parentsArr[i].parent = -1;
		parentsArr[i].arrSize = 0;
	}
}

DisjointSet::~DisjointSet()
{ 
	delete[] parentsArr;
}

int DisjointSet::Find(int index)
{
    if (index > arrSize)
	{
		cout << "Invalid input";
		exit(1); // todo throw
	}
	if (parentsArr[index].parent != index)
		parentsArr[index].parent = Find(parentsArr[index].parent);

	return parentsArr[index].parent;
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
