
#include "LinkedList.h"

#include <iostream>
#include <ostream>

using namespace std;

bool LinkedList::isEmpty()
{
    return head == nullptr;
}

void LinkedList::insertHead(Index index, Weight weight)
{
    temp = new Node;
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

void LinkedList::insertTail(Index index, Weight weight)
{
    temp = new Node;
    temp->index = index;
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

bool LinkedList::remove(Index indexRemoved) {
    // to remove an element, we go through the list, find the value given
    // if we find it, stop
    // to remove, disconnect the link
    // relink the two values now (ie.
    // value 1->2->3->NULL, 2 is removed, 1->3->NULL )
    
    bool status = false;
    if (this->size == 0)
        return status;

    Node* current = head;
    Node* prev = current;

    while (current != nullptr) {
        if (current->index == indexRemoved) { // if match
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

Node* LinkedList::find(int data)
{
    int i;
    Node* ret_val = nullptr;
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

ostream& operator<<(ostream& os, const Node& vertex)
{

    os << "(" << vertex.index
        << ", " << vertex.weight << ") ";
    os << endl;
    return os;
}

 ostream& operator<<(ostream& os, const LinkedList& list)
{
    Node* ptr = list.head;
    while (ptr != nullptr) {
        ptr = ptr->next;
        os << ptr;
    }
    return os;
}