//
//  main.cpp
//  Linked_List
//
//  Written by Connor Greenwood.  cgre@bu.edu
//

#include <iostream>
#include <limits.h>
#include "LinkedList.h"


int main(int argc, const char * argv[]) {

  /* Uncomment */
  char testNum = argv[1][0];
  if(testNum == '0'){
    //output: -2147483648 1 2 3 2147483647
      LinkedList<int> *myLL = new LinkedList<int>(INT_MIN, INT_MAX);
      Node<int> *newNodeLoc;  
      newNodeLoc = myLL->search(myLL->head, 3);
      myLL->insert(newNodeLoc, 3);
      newNodeLoc = myLL->search(myLL->head, 1);
      myLL->insert(newNodeLoc, 1);
      newNodeLoc = myLL->search(myLL->head, 2);
      myLL->insert(newNodeLoc, 2);

      myLL->printData();
      delete myLL;
  }

  else if(testNum == '1'){
    //output: -2147483648 -50 -49 ... 49 50 2147483647
      LinkedList<int> *myLL = new LinkedList<int>(INT_MIN, INT_MAX);
      Node<int> *newNodeLoc;
      for(int i = -50; i <= 50; i++){
        newNodeLoc = myLL->search(myLL->head, i);
        myLL->insert(newNodeLoc, i);
      }
      myLL->printData();
      delete myLL;
  }

  else if(testNum == '2'){
    //output: -2147483648 -50 -49 ... 49 50 2147483647
      LinkedList<int> *myLL = new LinkedList<int>(INT_MIN, INT_MAX);
      Node<int> *newNodeLoc;
      for(int i = 50; i >= -50; i--){
        newNodeLoc = myLL->search(myLL->head, i);
        myLL->insert(newNodeLoc, i);
      }
      myLL->printData();
      delete myLL;
  }

  else if(testNum == '3'){
    //output: A e f g z
      LinkedList<char> *myLL = new LinkedList<char>('A','z');
      Node<char> *newNodeLoc;
      newNodeLoc = myLL->search(myLL->head, 'f');
      myLL->insert(newNodeLoc, 'f');
      newNodeLoc = myLL->search(myLL->head, 'e');
      myLL->insert(newNodeLoc, 'e');
      newNodeLoc = myLL->search(myLL->head, 'g');
      newNodeLoc = myLL->insert(newNodeLoc, 'g');
      myLL->printData();
      delete myLL;
  }

  else if(testNum == '4'){    
  //output: Null pointer recieved
      LinkedList<int> *myLL = new LinkedList<int>(INT_MIN, INT_MAX);
      Node<int> *newNodeLoc;
      newNodeLoc = myLL->search(myLL->head,1);
      myLL->insert(newNodeLoc,1);
      newNodeLoc = myLL->search(myLL->head,2);
      newNodeLoc = myLL->insert(newNodeLoc,2);
      newNodeLoc = myLL->insert(newNodeLoc,3);
      newNodeLoc = myLL->insert(newNodeLoc,4);
      if(newNodeLoc->data == 4){
        if(newNodeLoc->prev->data == 3){
          if(newNodeLoc->prev->next->data == 4){
            cout << "Pass" << endl;
          }else{
            cout << "Error, newNodeLoc->prev->next->data != 4" << endl;
          }
        }else{
          cout << "Error, newNodeLoc->prev->data != 3" << endl;
        }
      }else{
        cout << "Error, newNodeLoc->data != 4" << endl;
      }

      delete myLL;
  }

  else if(testNum == '5'){
    //output: -2147483648 1 10 2147483647     SHOULD NOT HAVE -1 IN IT
      LinkedList<int> *myLL = new LinkedList<int>(INT_MIN, INT_MAX);
      Node<int> *newNodeLoc;
      newNodeLoc = myLL->search(myLL->head,1);
      myLL->insert(newNodeLoc,1);
      newNodeLoc = myLL->search(myLL->head,10);
      newNodeLoc = myLL->insert(newNodeLoc,10);
      newNodeLoc = myLL->search(myLL->head,10);

      newNodeLoc = myLL->insert(newNodeLoc,-1);
      if(newNodeLoc != NULL){
        cout << "Error: invalid insert should return NULL" << endl;
      }
      myLL->printData();
      delete myLL;
  }

  //checking that you can traverse backwards through list.
  else if(testNum == '6'){
    //expected output: -2147483648 1 2 3 4 5 2147483647
    LinkedList<int> *myLL = new LinkedList<int>(INT_MIN, INT_MAX);
    Node<int> *newNodeLoc;
    Node<int> *currNode;
    Node<int> *nextNode;
    newNodeLoc = myLL->search(myLL->head,1);
    newNodeLoc = myLL->insert(newNodeLoc,1);
    newNodeLoc = myLL->insert(newNodeLoc,2);
    newNodeLoc = myLL->insert(newNodeLoc,3);
    newNodeLoc = myLL->insert(newNodeLoc,4);
    newNodeLoc = myLL->insert(newNodeLoc,5);

    currNode = myLL->search(myLL->head,3);
    nextNode = currNode->next;
    if(currNode->data != nextNode->prev->data){
      cout << "error, cannot traverse backwards" << endl;
    }
    nextNode = nextNode->next;
    if(currNode->data != nextNode->prev->prev->data){
      cout << "error, cannot traverse backwards x2" << endl;
    }
    if(currNode->prev->next->data != currNode->data){
      cout << "error, cannot traverse backwards then forwards" << endl;
    }
    myLL->printData();
    delete myLL;
  }    
//checking if you can attempt to insert a bad value
//then continue with the program and insert a correct value
  else if(testNum == '7'){
    //expected output:  -2147483648 1 2 3 10 2147483647
    LinkedList<int> *myLL = new LinkedList<int>(INT_MIN, INT_MAX);
    Node<int> *newNodeLoc;
    newNodeLoc = myLL->search(myLL->head,1);
    newNodeLoc = myLL->insert(newNodeLoc,1);
    newNodeLoc = myLL->insert(newNodeLoc,2);
    newNodeLoc = myLL->insert(newNodeLoc,3);
    
    newNodeLoc = myLL->search(myLL->head,3);
    newNodeLoc = myLL->insert(newNodeLoc,-1);
    if(newNodeLoc != NULL){
      cout << "error, did not return NULL on bad insert" << endl;
    }
    newNodeLoc = myLL->search(myLL->head,10);
    newNodeLoc = myLL->insert(newNodeLoc,10);
    myLL->printData();
    delete myLL;
  }
  
//testing that you can search for and find exact value 
  else if(testNum == '8'){
    //expected output:  Correct value
    LinkedList<int> *myLL = new LinkedList<int>(INT_MIN, INT_MAX);
    Node<int> *newNodeLoc;

    newNodeLoc = myLL->search(myLL->head,2);
    newNodeLoc = myLL->insert(newNodeLoc,2);

    newNodeLoc = myLL->search(myLL->head,-2);
    newNodeLoc = myLL->insert(newNodeLoc,-2);

    newNodeLoc = myLL->search(myLL->head,0);
    newNodeLoc = myLL->insert(newNodeLoc,0);

    newNodeLoc = myLL->search(myLL->head,2);

    if(newNodeLoc->data == 2){
      cout << "Correct value" << endl;
    } else {
      cout << "Wrong value" << endl;
    }
    
    delete myLL;
  }

  //testing that delete myLL does not throw any errors
    else if(testNum == '9'){
      //expected output:  No errors
    LinkedList<int> *myLL = new LinkedList<int>(INT_MIN, INT_MAX);
    Node<int> *newNodeLoc;
    newNodeLoc = myLL->search(myLL->head,2);
    newNodeLoc = myLL->insert(newNodeLoc,2);

    newNodeLoc = myLL->search(myLL->head,-2);
    newNodeLoc = myLL->insert(newNodeLoc,-2);

    newNodeLoc = myLL->search(myLL->head,0);
    newNodeLoc = myLL->insert(newNodeLoc,0);
    delete myLL;

    //DOESN'T NECESSARILY MEAN IT IS PROPERLY CLEANING UP
    //THE LINKED LIST, JUST THAT IT DOESN'T KILL THE PROGRAM
    //WITH AN ERROR
    cout << "No errors" << endl;
    }  
  return 0;
}