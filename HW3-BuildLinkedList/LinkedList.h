// Copyright 2021 Parker Dunn (pgdunn@bu.edu)
// File provided to students for assignment

// Course: EC330 @ Boston University
// Assignment: HW3 - Problem 3

/******************** NEXT BLOCK OF COMMENTS AND CODE ARE ALL PROVIDED ****************************/

//  LinkedList.h
//  Linked_List
//
//  Copyright © Tali Moreshet. All rights reserved.
//
//  This is an implementation of an ordered Linked List class, which is made up of Nodes.
//  All classes are templated, such that their types may be provided at creation.
//  Nodes contain data (which doubles as key), and pointers to all directions.

#ifndef LinkedList_h
#define LinkedList_h

#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

template<class T>
class Node {
public:
    Node(const T& data);                            // constructor
    T data;                                         // node data, doubles as key
    Node<T> *next;                                  // node next pointer
    Node<T> *prev;                                  // node previous pointer
    Node<T> *up;                                    // node above pointer
    Node<T> *down;                                  // node below pointer
    void printData();                               // prints data value
    void print();                                   // prints entire node object content
};

template <class T>
class LinkedList {
public:
    LinkedList(T minVal, T maxVal);                 // constructor: accepts -infinity, +infinity values,
                                                    //  creates linked list with two corresponding nodes
    ~LinkedList();                                  // destructor
    Node<T>* search(Node<T>* location, T data);     // search for data starting at location, return node <= data
    Node<T>* insert(Node<T>* location, T data);     // insert node with data at new node to be placed directly
                                                    //  after node with povided location, return new node
    void printData();                               // prints linked list data
    void print();                                   // prints linked list with all nodes pointers
    Node<T>* head;                                  // head of list
};

/********************** From here down is the content of the LinkedList.cpp file: ***********************/


/********************* Implementation of Node ****************************/

// Constructor
template<class T>
Node<T>::Node(const T& data)
{
    this->data = data;
    this->next = nullptr;
    this->prev = nullptr;
    this->up = nullptr;
    this->down = nullptr;
}

// Print node's data value
template <class T>
void Node<T>::printData()
{
    cout << data << " ";
}

// Print entire node object content (data value, object's address, and all pointers)
template <class T>
void Node<T>::print()
{
    cout << " * " << data << ": [addr: " << this << " next: " << this->next << " prev: " << this->prev
         << " up: " << this->up << " down: " << this->down << "]  ";
}


/****************************** Implementation of linked list **********************/

// Constructor for the Linked List
// Functionality: creates first and last nodes using minVal and maxVal
//                should create two notes connected by their next and prev pointers
template<class T>
LinkedList<T>::LinkedList(T minVal, T maxVal) {
  // create first node
  this -> head = new Node<T>(minVal); // this is creation of first node with minVal as the data
  Node<T>* temp = head;
  // create the second node
  temp -> next = new Node<T>(maxVal);
  temp = temp -> next;  // assigns temp to the newest node (i.e. node 2)
  // "settle up" connections between nodes
  temp -> prev = head; // now node 2 is linked back to node 1
}

template<class T>
LinkedList<T>::~LinkedList() {
  // while next doesn't point to nullptr (i.e. end of LL) delete nodes
  while (head->next != nullptr) {
      head = (head -> next);
//      cout << "Deleting node with key " << (head->prev->data) << "\n";  // Used for confirming delection of nodes
      delete (head->prev);
  }
  //cout << "Deleting final node with key: " << head->data << "\n";  // Used for confirming deletion of final node
  delete head;
//  cout << "\nLinked List has been destroyed.\n"; // Used for confirming deletion of final node
};

template<class T>
Node<T>* LinkedList<T>::search(Node<T>* location, T data) { // search for data starting at location, return node <= data
    Node<T>* itr = location;

    // iterate until data value is found or iteration pointer equals nullptr
    while (itr != nullptr) {
        if (itr->data == data) return itr;
        itr = itr->next;
    }
    // Check for the first value greater than data then return pointer to prev node
    itr = location; // start at the beginning again
    while (itr != nullptr) {
        if (itr->data > data) return itr -> prev;
        itr = itr->next;
    }
    // shouldn't ever reach this point
    cerr << "Error in search!\n"; // BUT provides important error message/checking
    return nullptr;
}

template<class T>                                // insert node with data at new node to be placed directly
Node<T>* LinkedList<T>::insert(Node<T>* location, T data) {     //  after node with povided location, return new node
    if ((location->data >= data) or (location->next->data < data)) {
        // cerr << "Error in insert! - LL not sorted so insert not completed.\n";
        return nullptr;
    }
    // After error checking LL order, insert element
    Node<T>* second_half = location -> next;  // save pointer to second part of LL
    Node<T>* adr_new_node = new Node<T>(data); // create a new node
    // connect first half of LL to new node
    location -> next = adr_new_node;
    // connect new node to first half of LL
    adr_new_node -> prev = location;
    // connect new node to next node
    location -> next -> next = second_half;
    // connect second half to new node
    second_half -> prev = adr_new_node;

    return (adr_new_node);
}

template<class T>
void LinkedList<T>::printData() {
  Node<T>* itr = this->head;
  while (itr != nullptr) {
      itr -> printData();
      itr = itr -> next;
  }
}

template<class T>
void LinkedList<T>::print() {
   Node<T>* itr = this->head;
   while (itr != nullptr) {
       itr -> print();
       itr = itr -> next;
   }
}

#endif /* LinkedList_h */
