#pragma once
#define UNINIT -1;
#include <climits>
#include <iostream>

#include "Heap.h"

using namespace std;

struct Node {
    int index = UNINIT;
    int weight = INT_MAX;
    Node* next;

    bool includedFlag = false;
    Node* brother;

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
    void insertHead(int index, int weight);
    void insertTail(int index, int weight);
    Node* find(int data);
    void display();
    bool remove(int index_removed);

private:
    Node* temp = nullptr;
    friend ostream& operator<<(ostream& os, const LinkedList& vertex);
   
};

