// Copyright 2021 Parker Dunn
// pgdunn@bu.edu

// EC330 - HW2 - Problem 3

// Just a test script to create a function
// that returns the longest sequence

#include<iostream>
#include<vector>

using namespace std;

int decreasing_nums(int num_seq[], int index, int seq_len) {
  int longest_seq = 1, // 1 to account for first element
      current = index + 1,
      last = index;
  while (current < seq_len) {
    // When next number is smaller
    if (num_seq[current] < num_seq[last]) {
      longest_seq++;
      last = current;
    }
    current++;
  }
  return longest_seq;
}

void MaxDecSeq (int* nums, int len) {
  int seq_length = 0;   //start_index;
  vector<int> printing_indices;

  for (int i = (len - 1); i >= 0; i--) {
    int dec_len = decreasing_nums(nums, i, len);
    if (dec_len > seq_length) {
      seq_length = dec_len;
      // storing indices for printing
      if (printing_indices.empty()) printing_indices.push_back(i);
      else printing_indices.back() = i;

    } else if (nums[i] > nums[printing_indices.back()]) {
      seq_length++;      
      // storing indices for printing
      printing_indices.push_back(i);
    }
  }
  //printing statements
  while (printing_indices.back() != printing_indices.front()) {
    cout << nums[printing_indices.back()] << " ";
    printing_indices.pop_back();
  }
  int last = printing_indices.front();
  cout << nums[last] << " ";
  for (int i = (last + 1); i < len; i++) {
    if (nums[i] < nums[last]) {
      cout << nums[i] << " ";
      last = i;
    }
  }
  cout << "\n";
}

int main() {

  int test1[10]       = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1},
      test2[8]        = {25, 24, 15, 12, 10, 6, 5, 1},
      tricky_seq1[8]  = {25, 20, 1, 2, 10, 8, 5, 2},
      tricky_seq2[16] = {2, 100, 92, 4, 50, 25, 23, 49, 
                         20, 18, 15, 12, 8, 42, 41, 40},
      tricky_printing_seq[16] = {4, 100, 99, 2, 80, 1, 79, 2,
                                 3, 78, 2, 73, 4, 70, 1, 69};

  cout << "\n" << "Sequence: ";
  MaxDecSeq(test1, 10);
  cout << "\n";
  // should be 10
  // index 0

  cout << "\n" << "Sequence: ";
  MaxDecSeq(test2, 8);
  cout << "\n";
  // should be 8
  // index 0

  cout << "\n" << "Sequence: ";
  MaxDecSeq(tricky_seq1, 8);
  cout << "\n";
  // should be 6
  // index 0

  cout << "\n" << "Sequence: ";
  MaxDecSeq(tricky_seq2, 16);
  cout << "\n";
  // should be 10 - I think
  // index = 1

  cout << "\n" << "Sequence: ";
  MaxDecSeq(tricky_printing_seq, 16);
  cout << "\n";
  // should be length of 8
  // indices ... the program was smarter than me lmao

  return 0;
}