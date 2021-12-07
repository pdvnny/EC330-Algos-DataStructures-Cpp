//
//  main.cpp
//  Linked_List
//
//  Copyright © Tali Moreshet. All rights reserved.


#include <iostream>
#include <limits.h>
#include "LinkedList.h"

int main(int argc, const char * argv[]) {

  // NOTE: see www.cplusplus.com/reference/climits/ for more info on INT_MIN and INT_MAX
  // climits includes the min and max values for a handful of things - like char too

  LinkedList<int> *myLL = new LinkedList<int>(INT_MIN, INT_MAX);
  // For reference:
  // INT_MIN: -2147483648
  // INT_MAX: 2147483647

  Node<int> *newNodeLoc;

  /*** TEST CASE FROM ASSIGNMENT *****/
  /*
  newNodeLoc = myLL->search(myLL->head, 3);
  myLL->insert(newNodeLoc, 3);
  newNodeLoc = myLL->search(myLL->head, 1);
  myLL->insert(newNodeLoc, 1);
  newNodeLoc = myLL->search(myLL->head, 2);
  myLL->insert(newNodeLoc, 2);
  newNodeLoc = myLL->search(myLL->head, 3);
  myLL->insert(newNodeLoc, 3);

  cout << "Linked list data: \n";
  myLL->printData();

  cout << "\n Linked List entire content: \n";
  myLL->print();
  */

  /*** TEST CASE 5 ****/
  newNodeLoc = myLL->search(myLL->head, 1);
  myLL->insert(newNodeLoc, 1);
  newNodeLoc = myLL->search(myLL->head, 10);
  myLL->insert(newNodeLoc, 10);

  newNodeLoc = myLL->search(myLL->head, 1);
  myLL->insert(newNodeLoc, 1);

  myLL->printData();
  delete myLL;
    
  return 0;
}
