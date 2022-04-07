#define UNINIT -1;
#include <climits>
#include <iostream>

using namespace std;

struct AdjNode {
    int index = UNINIT;
    int weight = INT_MAX;
    AdjNode* next;
};

class LinkedList 
{
public:
  
    AdjNode* head = nullptr;
    AdjNode* tail = nullptr;
    int size = 0;

    bool isEmpty();
    void insertHead(int index, int weight);
    void insertTail(int data, int weight);
    // bool remove(int data);
    AdjNode* find(int data);
    void display();
    bool remove(int remValue);

private:
    

    AdjNode* temp = nullptr;
    

};

