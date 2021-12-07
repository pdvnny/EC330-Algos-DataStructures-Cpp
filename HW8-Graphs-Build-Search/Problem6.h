//
// Created by Parker on 12/3/2021.
//

#ifndef HW8__PROBLEM6_H_
#define HW8__PROBLEM6_H_

#include <vector>
#include <string>
#include <fstream>

using namespace std;

typedef struct {
  string name;
  vector<string> neighbors;
  int distance;
  bool queued;
  bool checked;
} Node;

vector<Node> buildGraph(ifstream*);
void distThreeNeighbors(vector<Node>*, string);

#endif //HW8__PROBLEM6_H_
