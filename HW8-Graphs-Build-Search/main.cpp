//
// Created by dvnny on 12/2/2021.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "Problem6.h"

using std::ifstream;
using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::vector;

int main(int argc, const char* argv[]) {

  if (argc != 3) {
    cerr << "You are missing a command line argument." << endl;
  } else {
//      cout << "Found " << argv[1] << " and " << argv[2] << endl;
      ifstream file(argv[1], ifstream::in);
      vector<Node> G = buildGraph(&file);
      distThreeNeighbors(&G, argv[2]);
  }

    return 0;
}
