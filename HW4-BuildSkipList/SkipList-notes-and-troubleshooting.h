//
//  SkipList.h
//  Skip_List
//
//  Copyright © Tali Moreshet. All rights reserved.
//
//
//  This is an implementation of a Skip List class, consisting of Linked Lists, which are made up of Nodes.
//  All classes are templated, such that their types may be provided at creation.
//  Nodes contain data (which doubles as key), and pointers to all directions.

#ifndef SkipList_h
#define SkipList_h

#include <iostream>
#include <cstdlib>
#include <stdlib.h>

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
                                                    //  after node with provided location, return new node
    void printData();                               // prints linked list data
    void print();                                   // prints linked list with all nodes pointers
    Node<T>* head;                                  // head of list

    // My own additions to the LinkedList class
    LinkedList<T>* upLL;
    LinkedList<T>* downLL;
};

template <class T>
class SkipList {
public:
    SkipList(T minVal, T maxVal);                   // constructor: accepts -infinity, +infinity values,
                                                    //  creates skip list with top-level only
    ~SkipList();                                    // destructor
    Node<T>* search(T data);                        // search for data, return node <= data (existing node, or location
                                                    //  where new node should be inserted in the bottom-most list)
    Node<T>* insert(T data);                            // insert node with data, return pointer if inserted, NULL if error
    void printData();                               // prints skip list data
    void print();                                   // prints skip list with all nodes pointers
    LinkedList<T> *topList;                         // pointer to the top-most list
    int randSeed = 330;                            // to be used as seed for the getRand() function

    // My own additions to the SkipList class
    T min;
    T max;
    void newLLup();

};

//returns 0 or 1 with a 50% chance 
//When it returns 1, insert the node to next level of the skiplist
int getRand(){
    int rand_num = rand();
    int rand_int = rand_num%2;
    cout << "\nRandom number was " << rand_num << " and rand_int was " << rand_int << "\n";
    return rand_int;   //rand()%2;
}

/********************** From here down is the content of the LinkedList.cpp file: ***********************/

/****** Implementation of Node ******/

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
    cout << " * " << data << ": [addr: " << this << " next: " << this->next << " prev: " << this->prev << " up: " << this->up << " down: " << this->down << "]  ";
}


/************************ Implementation of linked list ***********************************/

// Constructor for the Linked List
// Functionality: creates first and last nodes using minVal and maxVal
//                should create two notes connected by their next and prev pointers
template<class T>
LinkedList<T>::LinkedList(T minVal, T maxVal) {
    // NEW FOR SKIPLIST
    this->upLL = nullptr;
    this->downLL = nullptr;
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
        cout << "Deleting node with key " << (head->prev->data) << "\n";  // Used for confirming deletion of nodes
        delete (head->prev);
    }
    cout << "Deleting final node with key: " << head->data << "\n";  // Used for confirming deletion of final node
    delete head;
    // cout << "\nLinked List has been destroyed.\n"; // Used for confirming deletion of final node
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
    cout << "Error in search!\n"; // BUT provides important error message/checking
    return nullptr;
}

template<class T>                                // insert node with data at new node to be placed directly
Node<T>* LinkedList<T>::insert(Node<T>* location, T data) {     //  after node with provided location, return new node
    if ((location->data > data) or (location->next->data < data)) {
        cout << "Error in insert! - LL not sorted so insert not completed.\n";
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
        cout << "\n";
        itr = itr -> next;
    }
}

template<class T>
void LinkedList<T>::print() {
    Node<T>* itr = this->head;
    while (itr != nullptr) {
        itr -> print();
        cout << "\n";
        itr = itr -> next;
    }
}


/********************** Skip List Implementation ************************/

template<class T>
SkipList<T>::SkipList(T minVal, T maxVal) {
    // TODO: (1) create the top/bottom level linked list
    // TODO: (2) initialize srand(this->randSeed) for getRand() func
    // TODO: (3) System to keep track of skip list levels ... ahhh this is done through "topList" pointer
    this->topList = new LinkedList<T>(minVal, maxVal); // creates memory for a new linked list
    srand(this->randSeed); // srand() is a void function
    // helpful to know the min and max values for later
    this->min = minVal;
    this->max = maxVal;
}

template<class T>
SkipList<T>::~SkipList() {
    // TODO: (1) move the destructor to the bottom level of the linked list...
    // TODO: (2) Save pointers to bottom LL and next LL
    // TODO: (3) delete the bottom LL first, using LL destructor
    int deletedLLs = 0;
    LinkedList<T>* tempLL = this->topList;
    while (tempLL->downLL != nullptr) tempLL = tempLL-> downLL;
    // now tempLL points to the bottom LL

    LinkedList<T>* deleteLL;
    while (tempLL != nullptr) {
        // save location of next LL to be deleted
        deleteLL = tempLL;
        tempLL = tempLL -> upLL;

        // delete the current LL
        cout << "\n\nLinkedList Level " << deletedLLs << " deleted. Here are the keys:" << "\n";
        delete(deleteLL);
        deletedLLs++;
    }
}

template<class T>
void SkipList<T>::printData() {
    // TODO: (1) setup iteration through the linked lists
    // TODO: (2) Use linked list printData to print data from each of the linked lists
    LinkedList<T>* itrLL = this->topList;
    // move itrLL to the bottom first
    // while (itrLL->downLL != nullptr) itrLL = itrLL -> downLL;

    int level = 0;
    while (itrLL != nullptr) {
        cout << "\nSkipList Level " << level << ":\n";
        itrLL -> printData();
        itrLL = itrLL->downLL;
        level--;
    }
}

template<class T>
void SkipList<T>::print() {
  // TODO: (1) setup iteration through the linked lists
  // TODO: (2) Use linked list print() function on each level of the skip list
  LinkedList<T>* itrLL = this->topList;
  //while (itrLL->downLL != nullptr) itrLL = itrLL->downLL;   // move itrLL to the bottom

  int level = 0;
  while (itrLL != nullptr) {
    cout << "SkipList Level " << level << ":\n";
    itrLL -> print();
    itrLL = itrLL->downLL;
    level--;
  }
}

template<class T>
Node<T>* SkipList<T>::search(T data) {
    // Searching Process...
    // (1) check if node to the right (pointed to by next) has a greater data value
    //         --if (node to right has greater value) --> move down
    //         -- else (i.e. node to right is smaller key) --> move right
    // (2)... repeat above until (current node) -> down != nullptr (i.e. reached the bottom level)
    // (3) now return pointer to "level 0" node that was found

    Node<T>* nodeitr = topList->head; // top left most node

    // WHILE LOOP MOVES THE ITERATOR DOWN THE SKIPLIST LEVELS
    // GOAL: ensure that no larger node keys exist on the left!!
    while (nodeitr->down != nullptr) {
        if (nodeitr->data == this->min) {
            // this case would indicate that nodeitr is on a MIN node
            if (nodeitr->next->data < data) nodeitr = nodeitr->next;
            else nodeitr = nodeitr->down;
        } else if (nodeitr->data == this->max) {
            // this case would indicate that nodeitr is on a MAX node
            if (nodeitr->prev->data > data) nodeitr = nodeitr->prev;
            else nodeitr = nodeitr->down;
        } else {
            // now we know we are at a middle node
            if (nodeitr->prev->data >= data) nodeitr = nodeitr->prev;    //  go left if value to the left is greater
            else if (nodeitr->next->data <= data) nodeitr = nodeitr->next; // go right if value to the right is greater
            else nodeitr = nodeitr->down;  // go down if value to the right is greater
        }
    }
    // At bottom, double-check location within bottom level
    bool confirmed = false;
    while (!confirmed and !(nodeitr->data == this->min or nodeitr->data == this->max)) {
        if (nodeitr->next->data > data and nodeitr->prev->data < data) confirmed = true; // if next = higher and prev = lower
        else if (nodeitr->prev->data <= data) nodeitr = nodeitr->next; // if prev = higher or same
        else nodeitr = nodeitr->next;
    }

    if (nodeitr->data == data) {   // want to return null if a node with the data already exists
        cout << "\nSearch found a node with this data already.\n";
        return nullptr;
    }
    return nodeitr;
}

template<class T>
void SkipList<T>::newLLup() {
    // create new level of SkipList
    // (1) create a new LL with same min and max
    // (2) link the new LL to the LL a level down
    // (3) connect MIN and MAX nodes to the LL down as well

    LinkedList<T>* newLevelLL = new LinkedList<T>(this->min, this->max);

    // connecting new LL with previous top level
    LinkedList<T>* prevtopList = topList; // saving previous topList
    newLevelLL->downLL = topList;  // newLevelLL points to prev topList
    topList->upLL = newLevelLL;  // prev topList points up to newLevelLL
    topList = newLevelLL; // move topList to the newest LL

    // connecting the MIN nodes up and down
    prevtopList->head->up = topList->head;
    topList->head->down = prevtopList->head;

    // go to prevtopList ... find MAX node
    Node<T>* tempNodeptr = prevtopList->head;
    while(tempNodeptr->next != nullptr) tempNodeptr = tempNodeptr->next; // moves to MAX node of prevtopList

    // connecting the MAX nodes
    tempNodeptr->up = topList->head->next;
    topList->head->next->down = tempNodeptr;
}

template<class T>
Node<T>* SkipList<T>::insert(T data) {
    // (1) USE "search()" to find insertion location first
    // (2) ... NOTE: Drew a diagram for the rest of the work
    /******THIS SECTION SETS UP THE "LEVEL 0" NODE******/
    // Setup/save important addresses
    Node<T>* prevNodeptr = this->search(data);
    if (prevNodeptr == nullptr) return nullptr;  // this line ends method if the data you are looking for already exists
    Node<T>* postNewNodeptr = prevNodeptr->next;
    // Create new node
    Node<T>* newNodeptr = new Node<T>(data);
    // connect to new node
    postNewNodeptr->prev = newNodeptr;
    prevNodeptr->next = newNodeptr;
    // connect new node to previous and next
    newNodeptr->prev = prevNodeptr;
    newNodeptr->next = postNewNodeptr;

    Node<T>* itrNode;

    /***** USE RELATIVE REFERENCES AND COIN FLIP TO ADD THE NEW NODE TO HIGHER LEVELS OF SKIPLIST********/
    // NOTE: By design, newNodeptr will always point to the newest node created!!!
    int add_levels = 0;
    while (getRand()) {
       add_levels++;

       /******* CREATE A NEW LL LEVEL IF NEEDED *******************/
       itrNode = newNodeptr;
       // traverse LL to find head of the SkipList level
       while ((itrNode != this->topList->head) and (itrNode != nullptr)) itrNode = itrNode->prev;
       // NOTE: After the while loop, itrNode would point to head of current LL
       if (itrNode != nullptr) newLLup();

       /****** SETUP THE NODE ON A NEW LEVEL OF LINKED LIST ******/
       // setup - reassigning after using itrNode
       itrNode = newNodeptr;  // using newNodeptr because I am going to ensure that it always points to the most recently created node!

       // search left, go up level, create new node, connect new node
       while (itrNode->up == nullptr) itrNode = itrNode->prev; // search left
       itrNode = itrNode->up;  // move up

       // create new node
       Node<T>* lowernewNode = newNodeptr;
       prevNodeptr = newNodeptr;  // saving the last level node created
       newNodeptr = new Node<T>(data);

       // save important addresses
       prevNodeptr = itrNode;
       postNewNodeptr = itrNode->next;  // save to reconnect new node to the second half of the linked list

       // connect to new node
       lowernewNode->up = newNodeptr;
       postNewNodeptr->prev = newNodeptr;
       prevNodeptr->next = newNodeptr;

       // connect new node to other parts of LL
       newNodeptr->prev = prevNodeptr;
       newNodeptr->down = lowernewNode;
       newNodeptr->next = postNewNodeptr;
    }

    /******** CREATE A NEW LL LEVEL IF NEEDED ********/
    // NEED THIS BLOCK in case we never add new node up a level up
    itrNode = newNodeptr;
    // traverse LL to find head of the SkipList level
    while ((itrNode != this->topList->head) and (itrNode != nullptr)) itrNode = itrNode->prev;
    // NOTE: After the while loop, itrNode would point to head of current LL
    if (itrNode != nullptr) newLLup();

    cout << "\nAdded node to " << add_levels << " levels\n";

    return newNodeptr;
}


/************ OLD VERSION OF SKIPLIST DESTRUCTOR - NOT FINISHED *********************/
//    Node<T>* tempNode = this->topList->head;
//
//    // reassign temp down a level until it reaches the bottom where tempLL->head->down = nullptr
//    while (tempNode->down != nullptr) tempNode = tempNode->down;
//    // now, tempNode points to the head of the bottom most LL
//
//    Node<T>* nextNodeDelete = tempNode->up; // saves head ptr of the next LL to be deleted
//
//    while (nextNodeDelete != nullptr) {  // This was my original test condition: this->topList->head != nextNodeDelete
//        // delete the nodes of the current linked list
//        NOT FINISHING THIS ... JUST REALIZED THERE'S A BETTER WAY TO DO THIS
//
//        // prepping for next loop
//        tempNode = nextNodeDelete; // assign tempNode to the new node to be deleted
//        nextNodeDelete = tempNode -> up;
//    }



#endif /* SkipList_h */
