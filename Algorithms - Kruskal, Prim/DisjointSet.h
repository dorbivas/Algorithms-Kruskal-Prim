#include <vector>



using namespace std;

class DisjointSet {
public:
	DisjointSet(int arrSize);
	int Find(int index);
	void UnionBySize(int aSet, int bSet);
	void MakeSet(int index);

private:
	typedef struct {
		int parent;
		int arrSize;
	}Element;

	int arrSize{};
	vector<Element> parentsArr;

};
