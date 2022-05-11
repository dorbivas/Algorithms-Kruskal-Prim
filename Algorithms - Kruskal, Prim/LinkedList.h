#pragma once
#include <iostream>
#include "Utils.h"

#define UNINIT -1;
using namespace std;

struct Node
{
	int index = UNINIT;
	int weight = UNINIT;
	Node* next = nullptr;
	bool includedFlag = false;
	Node* brother = nullptr;
	~Node() = default; //no ctor or dtor actually needed.

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
	bool IsEmpty() const;
	void InsertHead(int index, int weight);
	void InsertTail(int index, int weight);
	bool removeNode(int indexRemoved);
	

private:
	Node* temp = nullptr;
	friend auto operator<<(ostream& os, const LinkedList& vertex)->ostream&;

};

