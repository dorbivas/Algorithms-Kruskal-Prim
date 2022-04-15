
class DisjointSet {

private:

	typedef struct {
		int parent;
		int arrSize;
	}Element;
	
	int arrSize;
	Element* parentsArr;

	void pathCompression()
	{
		
	}

public:

	DisjointSet(int arrSize) {

		parentsArr = new Element[arrSize];

		for (int i = 0; i < arrSize; i++) 
		{
			parentsArr[i].parent = -1;
			parentsArr[i].arrSize = 0;
		}
	}

	~DisjointSet() { 
		delete[] parentsArr;
	}


	int Find(int index)
	{
		if (parentsArr[index].parent != index)
			parentsArr[index].parent = Find(parentsArr[index].parent);

		return parentsArr[index].parent;
	}



	void UnionBySize(int aSet, int bSet)
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

	void MakeSet(int index)
	{
		parentsArr[index].parent = index;
		parentsArr[index].arrSize = 1;
		++arrSize;
	}
};