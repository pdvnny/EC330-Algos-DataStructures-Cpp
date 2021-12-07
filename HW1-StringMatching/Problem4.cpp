// Copyright 2021 pgdunn@bu.edu
// Parker Dunn
// EC330 - HW1 - Problem 4

#include<fstream>
#include<iostream>
#include<string>

using std::cin;
using std::cout;
using std::string;
using std::fstream;

int StringSearch(string filename, string pattern) {
  int found = 0;
  string line;
  fstream myfile;
  myfile.open(filename);
  while ( getline(myfile,line) ) {
    int current = 0;
    while (current < line.size()) {
      if (line.substr(current, pattern.size()) == pattern) found++;
      current++;
    }
  }
  myfile.close();
  return found;
}

int main(int argc, char **argv) {
  fstream txtfile;
  // error checking the number of inputs
  if (argc != 3) {
    cout << "You did not enter the correct number of arguments. "
         << "Please try again.\n";
    return 0;
  }
  // error checking file open - it is redundant; would improve for future
  txtfile.open(argv[1]);
  if (txtfile.is_open()) {
    txtfile.close();
  } else {
    cout << "The filename provided could not be opened." << "\n";
    return 0;
  }
  // error checking the string provided
  string check_input = argv[2];
  if (check_input.empty()) {
    cout << "You must provide a valid string input as the second argument." << "\n";
    return 0;
  }
  // Calling StringSearch function after error checking
  cout << StringSearch(argv[1], argv[2]) << "\n";
  return 0;
}