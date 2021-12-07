// Copyright 2021 Parker Dunn
// pgdunn@bu.edu

// EC330 - HW2 - Problem 3

/*

EXPLANATION OF MaxDecSeq FUNCTION

The primary feature of this function is determining the longest sequence of an int array.

In its current configuration, the function iterates through the array of nums from end to beginning,
and reassesses at each number what the longest sequence of descending numbers is. If there is not a
longer descending sequence with interuptions by small numbers, then the function will still keep track 
of an index if the value there is larger than the last "stored" (by index) value.

While the function is not the most efficient method, this approach ensures that even tricky number sequences
(e.g., have a small value between very large values like 100, 99, 2, 98) does not interfere with identifying
the longest sequence of descending numbers. Calling "decreasing_nums" is not ideal for efficiency, but is valuable
for long arrays of integers where a long sequence of descending values may exist anywhere among potentially thousands
(or more) values.

Additionally, the printing system should have been integrated with the determination of the longest sequence. It is
redundant to return to the array of integers to re-find the longest descending sequence and print it. It is functional
for the time being, but it is inefficient and should be written to work seamlessly with process of determining
the longest descending sequence for the future.

*/



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
      printing_indices.clear();
      // storing indices for printing
      printing_indices.push_back(i);

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