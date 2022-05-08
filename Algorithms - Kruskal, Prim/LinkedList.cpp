
#include "LinkedList.h"

#include <iostream>
#include <ostream>
#include "Utils.h"

using namespace std;

bool LinkedList::isEmpty()
{
    return head == nullptr;
}

void LinkedList::insertHead(int index, int weight)
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

void LinkedList::insertTail(int index, int weight)
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

bool LinkedList::RemoveFromList(int indexRemoved) {
    // to RemoveFromList an element, we go through the list, find the value given
    // if we find it, stop
    // to RemoveFromList, disconnect the link
    // relink the two values now (ie.
    // value 1->2->3->NULL, 2 is removed, 1->3->NULL )
    
    bool status = false;
    if (this->size == 0)
        return status;

    Node* current = head;
    Node* prev = nullptr;

    while (current != nullptr) {
        if (current->index == indexRemoved) { // if match
            status = true;
            break; // break out of while
        }
        prev = current;
        current = current->next; // go to prev value
        
        
    } // end while
    if (current == nullptr) { // if we reached end of list
        cout << "Can't RemoveFromList value: no match found.\n"; // no match, cant RemoveFromList
    }
    else { // found match
        if (current == tail) {
            tail = prev;
            tail->next = nullptr;
        }
        else if (current == head) {
            head = current->next;
        }
        else {
            prev->next = current;
        }
        --size;
        delete current;
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
        throw errorMessage("cant find vertix to remove in list " + this->head->index);
    }
    return ret_val;
    
}

ostream& operator<<(ostream& os, const Node& vertex)
{

    os << "(" << vertex.index
        << ", " << vertex.weight << ") ";
    return os;
}

 ostream& operator<<(ostream& os, const LinkedList& list)
{
    Node* ptr = list.head;
    while (ptr != nullptr) {
        os << *ptr << "->" ;
        ptr = ptr->next;

    }
    return os ;
}