// Copyright 2021 Parker Dunn pgdunn@bu.edu

// EC330 - HW2 - Problem 3

#include<algorithm>
#include<iostream>
#include<vector>

#include "Problem3.h" // provided with assignment

using namespace std;


// Function requested for the assignment

void MaxDecSeq(int* numbers, int len) {



}

// Additional function that seems useful
vector<int> gen_max_sequence(vector<int> sequence){

    int current_value = sequence.at(0),
        longest_len = 1;
    vector<int> long_seq = {current_value};

    for (int el : sequence) {
        bool save = true;
        if (el => current_value) {
            continue
        } else {
            for (int saved : long_seq) if (el == saved) save = false;
            if (save) {
                longest_len++;
                long_seq.push_back(el);
                current_value = el;
            }
        }
    }
    cout << "The longest descending sequence was " << longest_len << "values.\n";
    return long_seq;

    // Can't do it in current config; thinking I might want this function to return "longest_len"

    // WAIT THIS WON'T WORK CURRENTLY
    //  -- (if it compiles), the current configuration of this function will only find a descending list of values
    //  --                   the function does not double check that skipping a value will actually make the list longer!!!!!
    //  --                  e.g. [35, 1, 24, 22, 30, 5] (longest = 4) which would only return longest = 2

}



// starting with a replica of main from the assignment
int main() {

    int nums[] = {1, 5, 7, 3, 2, 4};
    int length = sizeof(nums)/sizeof(nums[0]);

    MaxDecSeq(nums, length);
    return 0;
}


/*
 * Thinking that it's probably faster to iterate through "nums" once and save the longest list ... WAIT
 *
 * Generally, the idea of iterating through a sequence and saving a series of sequences seems like a really long process...
 *
 * KEY: FIND A WAY TO GRADUALLY BUILD UP INFO ABOUT THE "NUMS" SEQUENCE THAT CAN BE USED TO REDUCE WORK
 *
 *
 *
 * /
