
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
        head = tail =  temp;
    
    else
    {
        tail->next = temp;
        tail = temp;
    }
    ++size;
}

bool LinkedList::removeNode(int indexRemoved)//XListNode* currX)
{
    bool status = false;
    Node* current = head, *prev = nullptr, *tmp;

    while (current != nullptr)
    {
        if (current->index == indexRemoved) { // if match
            status = true;
            break; // break out of while
        }
        prev = current;
        current = current->next; // go to prev value
    }

    if (status == false) //not found
        return status;
    

    tmp = current;
    /*remove from list with 1 node*/
    if (prev == nullptr && current->next == nullptr) // 
    {
        delete current;
        head = tail = nullptr;
    }
    /*remove first*/
    else if (prev == nullptr && current->next != nullptr)
    {
        head = current->next;
        delete tmp;
    }
    /*remove last*/
    else if (prev != nullptr && current->next == nullptr)
    {
        prev->next = nullptr;
        delete tmp;
    }
    else
    {
        prev->next = current->next;
        delete tmp;
    }
    --size;
    return status;
}


bool LinkedList::RemoveFromList(int indexRemoved) {
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
    else 
    { // found match
        if (current == tail)
        { //   X -- > NULL
            tail = prev;
            if (tail)
                tail->next = nullptr; 
        }
        if (current == head)
        {
            head = current->next;
        }
        if (!(head == tail && head == nullptr))
        {
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
    os << "(" << vertex.index + 1
        << ", " << vertex.weight << ") ";
    return os;
}

 ostream& operator<<(ostream& os, const LinkedList& list)
{
    Node* ptr = list.head;
    if (ptr == nullptr)
    {
        os << "empty";
    }
    while (ptr != nullptr) {
        os << *ptr << "->" ;
        ptr = ptr->next;

    }

    return os ;
}