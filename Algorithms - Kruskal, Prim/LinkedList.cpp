
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

bool LinkedList::remove(int remValue) {
    // to remove an element, we go through the list, find the value given
    // if we find it, stop
    // to remove, disconnect the link
    // relink the two values now (ie.
    // value 1->2->3->NULL, 2 is removed, 1->3->NULL )
    
    bool status = false;
    if (this->size == 0)
        return status;

    AdjNode* current = head;
    AdjNode* prev = current;

    while (current != nullptr) {
        if (current->index == remValue) { // if match
            status = true;
            break; // break out of while
            
        }
        else {
            prev = current; // save in case
            current = current->next; // go to prev value
        }
    } // end while
    if (current == nullptr) { // if we reached end of list
        cout << "Can't remove value: no match found.\n"; // no match, cant remove
    }
    else { // found match
        --size;
        prev->next = current->next;
        delete current ;
        current = prev->next; // current is updated
    }
    return status;
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

