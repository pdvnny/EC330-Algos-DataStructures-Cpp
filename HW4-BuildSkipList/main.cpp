// Copyright 2021 Parker Dunn pgdunn@bu.edu
// part of assignment for EC 330 @ Boston University
// Assignment: Homework #4
// Date: 10 Oct 2021

//  main.cpp
//  Skip_List
//
//  Copyright © Tali Moreshet. All rights reserved.
//

#include <iostream>
#include <limits.h>
#include "SkipList.h"

int main(int argc, const char * argv[]) {

  /* Uncomment */
  SkipList<int> *mySL= new SkipList<int>(INT_MIN, INT_MAX);


  mySL->insert(2);
  mySL->insert(1);
  mySL->insert(7);
  mySL->insert(5);
  mySL->insert(9);
  mySL->insert(6);
  mySL->insert(3);

  mySL->insert(7);

  cout << "\nSkipList data: \n";
  mySL->printData();
    
  cout << "\nSkipList entire content: \n";
  mySL->print();
  delete mySL;

  return 0;
}
