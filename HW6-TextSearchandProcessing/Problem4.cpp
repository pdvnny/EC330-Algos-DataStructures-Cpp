/************************************************
// Created by dvnny on 11/14/2021.

 Parker Dunn
 BU ID: 67368938
 DUE DATE: 16 Nov 2021

 EC 330 - HW6

**************************************************/
#include<algorithm>
#include<iostream>
#include<fstream>
#include<unordered_map>
#include<string>
#include<vector>

#include "Problem4.h"

using namespace std;

/// HOME COMPUTER FILENAMES
//string filename = "C:/Users/dvnny/OneDrive/Documents/4-Code/EC330/HW6/TinyData.txt";
//string dictionary = "C:/Users/dvnny/OneDrive/Documents/4-Code/EC330/HW6/dictionary.txt";

/// LAPTOP FILENAMES
//string filename = "C:/Users/parke/OneDrive/Documents/4-Code/EC330/HW6/TinyData.txt";
//string dictionary = "C:/Users/parke/OneDrive/Documents/4-Code/EC330/HW6/dictionary.txt";

/// WORKING DIRECTORY FILE NAMES
//string filename = "./TinyData.txt";
string dictionary = "./dictionary.txt";
string filename = "./BigData.txt";

/********************* SUPPORTING FUNCTIONS **********************************/

bool check_character(char check, const vector<char>* char_set) {
    for (auto chr : *(char_set)) {
        if (chr == check) return true;
    }
    return false;
//    if (any_of(char_set->begin(), char_set->end(), [](char chr) {return check == chr}))
}

void pw_reset(bool* low, bool* up, bool* num, int* curr) {
    *low = false;
    *up = false;
    *num = false;
    *curr = 0;
}

bool is_password(bool* low, bool* up, bool* num, int* len) {
    if (*low and *up and *num and *len > 7 and *len < 21)
        return true;
    else
        return false;
}

int generate_dictionary(unordered_map<string, bool>* dict) {
    ifstream file(dictionary);
    string line;
    vector<char> p = {'p', 'P'};        /// BU ID is U67368938
    vector<char> b = {'b', 'B'};
    vector<char> m = {'m', 'M'};
    bool bool_p, bool_b, bool_m;
    int largest = 0;
    if (file.is_open()) {
        while(getline(file, line)) {
            bool_p = true;
            bool_b = true;
            bool_m = true;
            for (auto c : line) {
                if (p.at(0) == c or p.at(1) == c) bool_p = false;
                if (b.at(0) == c or b.at(1) == c) bool_b = false;
                if (m.at(0) == c or m.at(1) == c) bool_m = false;
            }
            if (bool_p or bool_b or bool_m) {
                dict->emplace(line, true);
                if (line.size() > largest) largest = line.size();
            }
        }
    } else {
        cerr << "\nFile was not opened.\n";
    }
    file.close();
    return largest;
}

bool check_dictionary(unordered_map<string, bool>* d, const string &s) {
    unordered_map<string, bool>::const_iterator search;
    search = d->find(s);
    if (search == d->end()) return false;
    else return true;
}

//bool already_found(unordered_map<string, int>* w, const string &s) {
//    unordered_map<string, int>::const_iterator result;
//    result = w->find(s);
//    if (result == w->end()) return false;
//    else return true;
//}

/************************** fourA, fourB, and fourC **************************/

/// RETURNS 1065 FOR TinyData.txt AS OF 11/15 @ 2:30 PM
int fourA() {
    ifstream file;
    const vector<char> whitespace = {'\t', '\n', ' ', '\f', '\r', '\v'};
    string line;
    int longest = 0;
    int current = 0;

    file.open(filename);        /// file opened
    if (file.is_open()) {
        int i = 0;
        while (getline(file, line)) {
            while (i < line.size()) {
                if (check_character(line.at(i), &whitespace)) {
                    if (current > longest) longest = current;
                    current = 0;
                } else {
                    current++;
                }
                i++;  /// used to move through each character from a line
            }
        }
    } else {
        cerr << "\nFile was not opened correctly.\n";
    }

    file.close();
    return longest;
}

/// RETURNS 921 FOR TinyData.txt AS OF 11/15 @ 2:30 PM
int fourB() {
    ifstream file;
    const vector<char> whitespace = {'\t', '\n', ' ', '\f', '\r', '\v'};
    string line;
    int total = 0;
    int len = 0;
    int i = 0;
    bool lower = false, upper = false, number = false;

    file.open(filename);        /// file opened
    if (file.is_open()) {
        while (getline(file, line)) {
            i = 0;
            while (i < line.size()) {
                if (check_character(line.at(i), &whitespace)) {
                    if (is_password(&upper, &lower, &number, &len))
                        total++;
                    pw_reset(&lower, &upper, &number, &len);
                } else {
                    /// check if char is a number
                    if (line.at(i) > 47 and line.at(i) < 58) number = true;     // '0' = 48 and '9' = 57
                    /// check if char is upper
                    if (line.at(i) > 64 and line.at(i) < 91) upper = true;      // 'A' = 65 and 'Z' = 90
                    /// check if char is lower
                    if (line.at(i) > 96 and line.at(i) < 123) lower = true;     // 'a' = 97 and 'z' = 122
                    /// always increment for non-white space
                    len++;
                }
                i++;
            }
        }
    } else {
        cerr << "\nFile was not opened correctly.\n";
    }
    file.close();
    return total;
}

/// RETURNS 573317 FOR TinyData.txt AS OF 11/16 @ 12:58 AM
int fourC() {
  /// SETUP
  ifstream file(filename);
  const vector<char> whitespace = {'\t', '\n', ' ', '\f', '\r', '\v'};

  unordered_map<string, bool> dict;
//  unordered_map<string, int> words;

  int i = 0, j;
  int found = 0, longest;
  string line;
  string cword;

  longest = generate_dictionary(&dict);   /// Generate the dictionary needed for comparison

  /// NEXT UP: Iterate through lines & (more importantly) iterate through chars of each line
  if (file.is_open()) {
      while (getline(file, line)) {
          i = 0;
          while (i < line.size()) {                                                                             /// RUNTIME: O (len_of_lin * (L2 + const.))
              j = 0;
              while (j < longest and (i+j) < line.size() and isalpha(line.at(i+j))) {                                           /// RUNTIME: O ( L2 = (length * length))
                  /// repeatedly check longer and longer words - use check_dictionary with line.substr()
                  cword = line.substr(i, j+1);
                  if (check_dictionary(&dict, cword)) {
                      /// substring found in dictionary
                      found++;
//                      if (already_found(&words, cword)) words.at(cword)++;
//                      else words.insert({cword, 1});
                  }
                  j++;
              }
//              if (i == (line.size()/2)) cout << "Halfway point.\n";
//              if (i == (3 * line.size()/4)) cout << "Three quarters point.\n";
              /// reset - (1) move to the next character
              i++;
          }
      }
  }
  file.close();
//  for (auto it = words.begin(); it != words.end(); ++it) found += it->second;

  return found;
}
