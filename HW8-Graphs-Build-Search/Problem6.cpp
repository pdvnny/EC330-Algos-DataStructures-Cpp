//
// Created by dvnny on 12/2/2021.
//

/*******************************************************
 *
 * Functions used in main.cpp
 *
 *
 *
 *******************************************************/


/******************** INCLUDES **********************/

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <fstream>
#include <queue>

/// I/O
using std::cout;
using std::cerr;
using std::endl;
/// FILES
using std::ifstream;
/// STL
using std::vector;
using std::string;
using std::stoi;
using std::priority_queue;

typedef struct {
  string name;
  vector<string> neighbors;
  int distance;
  bool queued;
  bool checked;
} Node;

//typedef std::pair<int, string> gnode;

class MyComparator {
  int operator() (const Node& nd1, const Node& nd2) {
    return nd1.distance > nd2.distance;
  }
};

vector<Node> buildGraph(ifstream* file) {
    int nodes, edges;
    int i = 0, j = 0;
    vector<Node> graph;
//    cout << "Step 1: Read in and print the lines of the file" << endl;

    string line;
    if (file->is_open()) {
      /// INFO FROM LINE 1
      getline(*file, line);
      while(line.at(i) != ' ') i++;
      nodes = stoi(line.substr(0,i));
      j = i+1;
      while(line.at(j) != ' ') j++;
      edges = stoi(line.substr((i+1), (j-i+1)));
      /// READ THE REST OF THE LINES
      while (getline(*file, line)) {
        if (line.empty() or line.at(0) == '\r' or line.at(0) == '\n' or line.at(0) == ' ') {
          continue;
        } else if (line.at(0) == '"') {           /// reading in an edge
              string v1, v2;
              i = 0;
              while (line.at(i) != ' ') i++;
              j = i+1;
              while (line.at(j) != ' ') j++;
              v1 = line.substr((i+1), (j-i-1));
              i = j + 1;
              while (line.at(i) != ' ') i++;
              v2 = line.substr((j+1), (i-j-1));
              for (auto & vertex : graph) {
                  if (vertex.name == v1) vertex.neighbors.push_back(v2);
                  if (vertex.name == v2) vertex.neighbors.push_back(v1);
              }
          } else {                              /// reading a new vertex
              i = 0;
              while (line.at(i) != ' ') i++;
              Node n = {line.substr(0,i), {}, 10, false, false};
              graph.push_back(n);
          }
      }
      if (graph.size() != nodes) cerr << "Number of nodes in graph does not match the expected number" << endl;
    } else {
        cerr << "File was not opened." << endl;
    }

    /// GRAPH SHOULD BE CONSTRUCTED NOW
    return graph;
}

void mark_search(Node* src, vector<Node>* g) {    /// Currently setup to check if this method should be called before the call --- no base case
    vector<Node*> check_these;
    src->checked = true;
    for (auto & neigh : src->neighbors) {
        for (auto & nd : *g) {
            if (nd.name == neigh and nd.distance > src->distance + 1) {
              nd.distance = src->distance + 1;
              check_these.push_back(&nd);
            }
        }
    }
    if (src->distance < 3) {
        for (auto & n : check_these) {
            if (!n->checked and !n->queued) {
              n->queued = true;
              mark_search(n, g);
            }
        }
    }
}

void distThreeNeighbors(vector<Node>* g, string src) {
    Node* start;
    for (auto & node : *g) {
      if (node.name == src) start = &node;
    }
    start->queued = true;
    start->distance = 0;
    mark_search(start, g);
//    priority_queue<Node, vector<Node>, MyComparator> q;
//    q.push(start);
//    cout << "Success" << endl;

    std::map<string, int> printable_graph;

    for (auto & node : *g) {
      if (node.distance < 4) printable_graph.emplace(node.name, node.distance);
    }
    cout << "Distance-3 Neighbors" << endl;
    cout << "____________________" << endl;
    for (auto & [key, value] : printable_graph)
      cout << key << endl;
};

//      /// Printing graph for reference
//      cout << "Location: " << node.name << endl;
//      cout << "Possible Designations: ";
//      for (auto & loc : node.neighbors) cout << loc << " ";
//      cout << "\n\n";