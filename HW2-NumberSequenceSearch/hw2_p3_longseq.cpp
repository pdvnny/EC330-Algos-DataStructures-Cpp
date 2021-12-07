// Copyright 2021 Parker Dunn
// pgdunn@bu.edu

// EC330 - HW2 - Problem 3

// Just a test script to create a function
// that returns the longest sequence

#include<algorithm>
#include<iostream>
#include<vector>
#include<string>

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

int finding_seq (int* nums, int len) {

  int seq_length = 0;   //start_index;
  vector<int> printing_indices;

  for (int i = (len - 1); i >= 0; i--) {
    int dec_len = decreasing_nums(nums, i, len);
    if (dec_len > seq_length) {
      seq_length = dec_len;
      //start_index = i;

      // storing indices for printing
      if (printing_indices.empty()) printing_indices.push_back(i);
      else printing_indices.back() = i;

    } else if (nums[i] > nums[printing_indices.back()]) {
      seq_length++;
      //start_index = i;
      
      // storing indices for printing
      printing_indices.push_back(i);
    }
  }
  cout << "Starting index is " << printing_indices.back() << "\n";

  for (int ind : printing_indices)
    cout << ind << " ";
  
  cout << "Longest sequence: ";

  return seq_length;
}

int main() {

  int test1[10]       = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1},
      test2[8]        = {25, 24, 15, 12, 10, 6, 5, 1},
      tricky_seq1[8]  = {25, 20, 1, 2, 10, 8, 5, 2},
      tricky_seq2[16] = {2, 100, 92, 4, 50, 25, 23, 49, 
                         20, 18, 15, 12, 8, 42, 41, 40};

  cout << "\n" << finding_seq(test1, 10) << "\n";
  // should be 10
  // index 0

  cout << "\n" << finding_seq(test2, 8) << "\n";
  // should be 8
  // index 0

  cout << "\n" << finding_seq(tricky_seq1, 8) << "\n";
  // should be 6
  // index 0

  cout << "\n" << finding_seq(tricky_seq2, 16) << "\n";
  // should be 10 - I think
  // index = 1

  return 0;
}

// Thinking I might need recursive calls to allow for flexibility at
// each element of an array


// Would be convenient to be able to check if the next value in the seq
// is higher to potentially research the checking process

// Right idea ... not ready for it yet
/*
move_ptr = 0,

if (num_seq + move_ptr == num_seq.at(seq_len - 1)) {
    
  }

  if (num_seq > num_seq + move_ptr) {

  }


  cout << "Longest sequence for test1 - index 0: " << decreasing_nums(test1, 0, 10) << "\n";
  // should be 10
  cout << "Longest sequence for test1 - index 4: " << decreasing_nums(test1, 4, 10) << "\n";
  // should be 6
  cout << "Longest sequence for test2 - index 2: " << decreasing_nums(test2, 2, 8) << "\n";
  // should be 6

  cout << "Longest sequence for tricky_seq1 - index 0: " << decreasing_nums(tricky_seq1, 0, 8) << "\n";
  // should be 6


*/