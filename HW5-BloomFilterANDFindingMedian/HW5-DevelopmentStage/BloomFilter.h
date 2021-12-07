//
// Created by dvnny on 11/3/2021.
//

#ifndef BLOOMFILTER_H
#define BLOOMFILTER_H

#include<math.h>
#include<string>
#include<vector>
#include<bitset>
//#include<bits/stdc++.h> - NOT SURE IF I NEED THIS YET

using namespace std;

#define ll long long // declares the type long long (for ints) to be "ll"


/******** HASH FUNCTIONS *************/
/// HASH 1
int h1(string s, int size) {
    ll int hash = 0;
    for (char c: s) {                     /// for each char in the input string
        hash = (hash + ((int) c));        /// converts char to int and adds to a total value
        hash = hash % size;
    }
    return hash % size;                      /// we are not actually double hashing
}                                            /// the % size in the for loop is specific to one of the converted chars
/// HASH 2
int h2(string s, int size) {
    ll int hash = 1;
    for (int i = 0; i < s.size(); i++) {
        hash = hash + pow(19, i) * s[i];
        hash = hash % size;
    }
    return hash % size;
}
/// HASH 3
int h3(string s, int size) {
    ll int hash = 7;
    for (char c : s) hash = (hash * 31 + c) % size;
    return hash % size;
}
/// HASH 4
int h4(string s, int size) {
    ll int hash = 3;
    int p = 7;
    for (int i = 0; i < s.size(); i++) {
        hash += hash * 7 + s[0] * pow(p, i);
        hash = hash % size;
    }
    return hash;
}
/*************************************/

class BloomFilter {
public:
    explicit BloomFilter(int len);  // Clang (c++ text monitoring feature) suggesed adding "explicit"
    ~BloomFilter() {
        delete [] bitarray;
        cout << "\nBitarray deleted.\n";
    }
    void insert(string item);
    bool exists(string item);
    string output();

protected: /// This is probably completely irrelevant since we aren't doing a derived class anymore
    int length;
    bool* bitarray;
    // char *bf;

};

BloomFilter::BloomFilter(int len) {
    this->length = len;
//    bool array[len];
//    for (int i = 0; i < this->length; i++) array[i] = false;
//    this->bitarray = array;
    this->bitarray = new bool[len];
    for (int i = 0; i < len; i++) *(bitarray+i) = false;
}

void BloomFilter::insert(string item) {  /// analog to "void insert(bool* bitarray, int Size, string s)"



    // check if the new element to insert is already present
    if(this->exists(item)) {
        cout << item << "is probably already inserted\n";
    } else {
        int a = h1(item, this->length);
        int b = h2(item, this->length);
        int c = h3(item, this->length);
        int d = h4(item, this->length);
        *(this->bitarray + a) = true;
        *(this->bitarray + b) = true;
        *(this->bitarray + c) = true;
        *(this->bitarray + d) = true;
        cout << item << " inserted.\n";
    }
}

bool BloomFilter::exists(string item) { /// analog to "bool lookup(bool* bitarray, int Size, strings)"
    int a = h1(item, this->length);
    int b = h2(item, this->length);
    int c = h3(item, this->length);
    int d = h4(item, this->length);

    if (*(bitarray+a) &&
        *(bitarray+b) &&
        *(bitarray+c) &&
        *(bitarray+d))
        return true;
    else
        return false;
}


/// DIFFERENT CONFIGURATION THAT I NEED FOR MY BLOOMFILTER!!
/// this output displays the exact boolean array!
string BloomFilter::output() {
    string bf;
    for (int j = 0; j < this->length; j++) {
        if (*(this->bitarray + j)) bf.append("1");
        else bf.append("0");
    }
    return bf;
}


#endif //BLOOMFILTER_H
