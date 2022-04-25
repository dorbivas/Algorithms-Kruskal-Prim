
class DisjointSet {

private:

	typedef struct {
		int parent;
		int arrSize;
	}Element;
	
	int arrSize;
	Element* parentsArr;

	void pathCompression();

public:
	explicit DisjointSet(int arrSize);

	~DisjointSet();


	int Find(int index);


	void UnionBySize(int aSet, int bSet);

	void MakeSet(int index);
};