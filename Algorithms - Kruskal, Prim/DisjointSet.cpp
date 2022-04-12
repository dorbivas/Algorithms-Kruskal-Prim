
#include "DisjointSet.h"
#include "LinkedList.h"

//tests main
int main()
{
	DisjointSet set(3);
	
	for (int i = 0; i < 3; i++)
	{
		set.MakeSet(i);

	}
	for (int i = 0; i < 2; i++)
	{
		set.UnionBySize(i, i + 1);

	}
	cout << set.Find(1);
	cout << set.Find(2);
}