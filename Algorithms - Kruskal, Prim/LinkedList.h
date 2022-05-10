#pragma once
#include <iostream>
#define UNINIT -1;
using namespace std;

struct Node
{
	int index = UNINIT;
	int weight = UNINIT;
	Node* next = nullptr;
	bool includedFlag = false;
	Node* brother = nullptr;
	~Node() = default;

private:
	friend ostream& operator<<(ostream& os, const Node& vertex);
};


class LinkedList
{
public:
	Node* head = nullptr;
	Node* tail = nullptr;
	Node* find(int data);
	int size = 0;

	~LinkedList();
	bool isEmpty();
	void insertHead(int index, int weight);
	void insertTail(int index, int weight);
	bool removeNode(int indexRemoved);//?
	bool RemoveFromList(int index_removed);

private:
	Node* temp = nullptr;
	friend auto operator<<(ostream& os, const LinkedList& vertex)->ostream&;

};

