#pragma once
#define UNINIT -1;
#include <iostream>

using namespace std;

struct Node {
    int index = UNINIT;
    int weight = UNINIT;
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
    bool RemoveFromList(int index_removed);

private:
    Node* temp = nullptr;
    friend auto operator<<(ostream& os, const LinkedList& vertex) -> ostream&;  // NOLINT(readability-inconsistent-declaration-parameter-name)
   
};

