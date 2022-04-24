#pragma once
#define UNINIT -1;
#include <climits>
#include <iostream>

#include "Heap.h"

using namespace std;

typedef int Weight;
typedef int Index;

struct Node
{
    int index = UNINIT; //todo: might be nice
    int weight = INT_MAX; //todo: might be nice
    Node* next;

    private:
    friend ostream& operator<<(ostream& os, const Node& vertex);
 

};


class LinkedList  //todo: can be made generic with node outside
{
public:
    Node* head = nullptr;
    Node* tail = nullptr;
    int size = 0;

    bool isEmpty();
    void insertHead(Index index, Weight weight);
    void insertTail(Index index, Weight weight);
    Node* find(int data);
    void display();
    bool remove(Index index_removed);

private:
    Node* temp = nullptr;
    friend ostream& operator<<(ostream& os, const LinkedList& vertex);
   
};

