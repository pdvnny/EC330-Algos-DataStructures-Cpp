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


/*
Here is my solution for Problem 5 - Part a
"Description of the algorithm used below using pseudocode"

KEY:
board-itr = "Board iteration" == the integer passed to the program - 0<=N<=7
________

create a new/empty board

for i = 0 (first index) to last row of board
  for j = 0 to board-itr
    if coordinate (i,j) on diagonal of board
      place 'x'
    if coordinate (i,j) directly above diagonal of board
      place 'x'

if board-itr is even
  place 'o' in the next position of the diagonal - coordinate (board-itr, board-itr)

if board-itr is odd
  place 'o' at "two positions further along board diagonal" compared to last 'x' - coordinate (board-itr+2, board-itr+2)
  place 'o' down two increments from the first 'o' - coordinate (board-itr, board-itr+2)

*/

vector<string> create_board(int n, int bs) {
  vector<string> new_board(bs, " ");
  for (int i = 0; i < bs; i++) {
    string new_line(bs, '.');
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
  // Check: correct number of arguments
  if (argc != 2) {
    cout << "You did not enter the correct number of arguments. Please try again.\n";
    return 0;
  }
  // Check: Integer provided less than or equal to 9
  //     - Doesn't work with 10+ right now; could easily be changed
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