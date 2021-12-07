// Copyright 2021 pgdunn@bu.edu
// Parker Dunn

// EC330 - HW1 - Problem 5

#include<iostream>
#include<string>
#include<vector>

using std::cin;
using std::cout;
using std::string;
using std::stoi;
using std::vector;

// OUTSTANDING ISSUES
// -- N=7 fringe case - this worked when tested night of 9/14
// -- boards larger than 10

vector<string> create_board(int n, int board_size) {
  vector<string> new_board(board_size, " ");
  for (int i = 0; i < board_size; i++) {
    string new_line(board_size, '.');
    for (int j = 0; j < (n+1); j++) {
      if (i == j) new_line.at(j) = 'x';
      if (i-1 == j) new_line.at(j) = 'x';
    }
    new_board.at(i) = new_line;
  }
  if (!(n%2)) {  // Add o's for N = even
    (new_board.at(n+1)).at(n+1) = 'o';
  } else {
    (new_board.at(n+2)).at(n+2) = 'o';
    (new_board.at(n)).at(n+2) = 'o';
  }

  return new_board;
}

int main(int argc, char *argv[]) {
  int size = 10;
  int N;
  vector<string> rows_of_board;
  
  // Error checking
  if (argc != 2) {
    cout << "You did not enter the correct number of arguments. Please try again.\n";
    return 0;
  } 
  char arg2 = *argv[1];
  if (arg2 >= '0' and arg2 <= '9') N = stoi(argv[1]);
  
  // Creation of pattern
  if (N <= size-2) rows_of_board = create_board(N, size);
  else {
    cout << "The board is not currently configured to produce a pattern this large."
         << "The board size can be changed within the script. Per assignment instructions,"
         << "the script is setup to handle up to N = 7 and not accept a board size input.\n";
    return 0;
  }

  // Prints out the pattern created by "create_board()"
  for (int k = rows_of_board.size() - 1; k > -1; k--) {
    cout << rows_of_board.at(k) << "\n";
  }
  cout << "\n";

  return 0;
}

// Initially used a way to read in values

  // cout << "Please provide board size: ";
  // cin >> size;

  // cout << "Provide value of N: ";
  // cin >> N;

// FROM "create_board"
    // How to add in the O's
    // if (n % 2 and i == (n+2)) {         // Odd N values & higher o
    //   new_line.at(i) = 'o';
    // } else if (n % 2 and i == n) {      // Odd N values & lower o
    //   new_line.at(i + 2) = 'o';
    // } else if (n%2 == 0 and i == n+1) { // Even N values
    //   new_line.at(i) = 'o';
    // }
