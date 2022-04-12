class DisjointSets
{

private:
	typedef struct {
		int parent;
		int size;
	}Element;

	void unionBySize() {}
	void pathCompression() {}
	int size;
	Element* parentsArr;

public:

	DisjointSets(int n) {
		for (int i = 0; i < size; i++) {
			parentsArr[i].parent = -1;
			parentsArr[i].size = 0;
		}
	}

	~DisjointSets() {    }

	int Find(int setX)
	{
		if (parentsArr[setX].parent == setX)
			return setX;

		else
			return parentsArr[setX].parent = Find(parentsArr[setX].parent);


	}
	void Union(int aSet, int bSet)
	{
		if (parentsArr[aSet].size > parentsArr[bSet].size)
		{
			parentsArr[bSet].parent = aSet;
			parentsArr[aSet].size += parentsArr[bSet].size;
		}
		else {
			parentsArr[aSet].parent = bSet;
			parentsArr[bSet].size += parentsArr[aSet].size;
		}

	}

	void MakeSet(int index)
	{
		parentsArr[index].parent = index;
		parentsArr[index].size = 1;
	}
};