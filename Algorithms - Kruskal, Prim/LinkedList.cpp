
#include "LinkedList.h"

#include <iostream>
#include <ostream>

using namespace std;

bool LinkedList::isEmpty()
{
    return head == nullptr;
}

void LinkedList::insertHead(int index ,int weight)
{
    temp = new AdjNode;
    temp->index = index;
    temp->weight = weight;

    if (isEmpty())
    {
        temp->next = nullptr;
        tail = temp;
    }
    else
        temp->next = head;
    head = temp;
    ++size;
}

void LinkedList::insertTail(int data, int weight)
{
    temp = new AdjNode;
    temp->index = data;
    temp->weight = weight;

    temp->next = nullptr;
    if (isEmpty())
    {
        head = temp;
        tail = temp;
    }
    else
    {
        tail->next = temp;
        tail = temp;
    }
    ++size;
}

void LinkedList::remove(int data)
{
    temp = head;
    AdjNode* prev = nullptr;
    while (temp->next != nullptr && temp->index != data)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp->index == data)
    {
        prev->next = temp->next;
        delete temp;
    }
    else if (temp->next == nullptr)
    {
        cout << "Error: Number Not found..." << endl;
    }
}

AdjNode* LinkedList::find(int data)
{
    int i;
    AdjNode* ret_val = nullptr;
    for (i = 1, temp = head; temp->next != nullptr && temp->index != data; temp = temp->next, i++);
    if (temp->index == data)
    {
        ret_val = temp;
        // cout << "Found at position:" << i << endl;
    }
    else if (temp->next == nullptr)
    {
        //throw "Error: Number Not found..." ; TODO 
    }
    return ret_val;
    
}

void LinkedList::display()
{
    if (!isEmpty())
    {
        for (temp = head; temp != nullptr; temp = temp->next)
            cout << temp->index << " ";
        cout << endl;
    }
    else
    {
        cout << "List is Empty!" << endl;
    }
}

