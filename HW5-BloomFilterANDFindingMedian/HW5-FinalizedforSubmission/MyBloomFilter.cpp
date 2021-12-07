//
// Created by pgdunn on 11/2/21.
//

/*******************************************************
 * Copyright 2021 Parker Dunn pgdunn@bu.edu
 *
 * DUE: 3rd November 2021
 *
 * This file is created for EC 330 at Boston University
 * All other files related to this assignment are property
 * of the instructor - see BloomFilter.h
 *
*******************************************************/

/********* EXPLANATION OF MY BLOOMFILTER IMPLEMENTATION ***************************

 This BloomFilter is not everything I had hoped for but seems to work pretty reliably.

 Quick note ... then discussion about my implemenation...
 Honestly, I had some trouble finding a way to convert back and forth between bits and
 characters. Since the BloomFilter class was pre-determined and I am not familiar with
 manipulating character arrays, there were many problems along the way. BUT, the BloomFilter
 should be working now; I just didn't get as much time to learn about and explore options
 for hash functions and bit operations as I would have liked.

 Information about my implementation:

 First, I used the resource on the next line to get a "classic (bit)" BloomFilter
 working:
 -- https://www.geeksforgeeks.org/bloom-filters-introduction-and-python-implementation/

 I explored information about other BloomFilters but did not have the chance to explore
 them enough to implement them or include any of their contents for this assignment. For example,
 the page above implemented a MumurHash in Python that I wanted to explore and implement. Instead,
 I used a combination of 4 hash functions provided in C++ at the link above to create a functional
 BloomFilter.

 I tested the hash functions separately and played around with them a little to see how well
 they performed with ~60 different strings. The functions seemed pretty reliable, so I implemented
 them exactly as they appeared on the website. All four hash functions implemented here hash an input
 string, and return a value within a certain bit range. Thus, all strings inserted to my BloomFilter
 are represented by 4 hashes.

 Next, I went to work on deciding how to display a bitmap as characters. Some major decisions outlined:

 (1) I wanted to come up with a reliable and predictable option for displaying bits as characters,
     so I did only use printable characters.

     (http://facweb.cs.depaul.edu/sjost/it212/documents/ascii-pr.htm)
 (2) I developed my bitmap in this implementation based on a subset of characters that I wanted to use.

 (3) I decided to keep my implementation a little simpler by defining the size of the binary values that
    could be used to represent characters. In other words, I used a set of characters that would map
    to a unique 6-bit number.


  // PLANNING - Printable characters

    First printable char: 33 or 0x21 or '!'
    Last printable char: 126 or 0x7e or '~'
    RANGE FOR CHARS: 126 - 32 = 95 values

    Natural range of printable characters doesn't work well...
    2^5 = 32
    2^6 = 64
    2^7 = 128
    USE 6 BITS WHICH COVERS 64 VALUES

    ASCII CHARS TO USE:
        Start - 48  or 0x30 (0b00110000) or '0'
        End   - 111 or 0x6F (0b01101111) or 'o'

************************************************************************************/

/// INCLUDES
#include<string>
#include<cmath>
#include<bitset>

#include "BloomFilter.h"

using namespace std;

#define ll long long

/******** NON-BLOOMFILTER FUNCTIONS AND HASH FUNCTIONS **************************/

/// CONVERT CHAR ARRAY TO BITS
void char_to_bitarray(const char* bf_char, int size, bool* bf_bits) {
   /// CONVERT CHARS TO BITS
    for (int i = 0; i < size; i++) {
        unsigned char chr = (bf_char[i] - 48);  // 0 if character is '0' and 63 if character is 'o'
        bitset<6> chr_bits(chr);
        for (int j = 0; j < 6; j++)
            bf_bits[i * 6 + j] = chr_bits[5-j];
    } // returns a filled bf_bits array

}
/// HASH 1
int h1(string s, int size) {
    ll int hash = 0;
    for (char c: s) {                     /// for each char in the input string
        hash = (hash + ((int) c));        /// converts char to int and adds to a total value
        hash = hash % size;
    }
    return hash % size;                      /// we are not actually double hashing
}             /// the % size in the for loop is specific to one of the converted chars
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

/************* FUNCTIONS FOR BLOOMFILTER.H FILE *************/

BloomFilter::BloomFilter(int len) {
    this->length = len;
    bf = new char[len];
    for (int i = 0; i < len; i++) bf[i] = '0';
    bf[len] = '\0';
}

/****
 * I am not extremely familiar with how C++ compilers free memory when programs run.
 * I am aware that memory leaks can occur when using the "new" operation in C++, and
 * I was pretty sure that I am supposed to "clean up" when I use the operation.
 *
 * So, I struggled a lot with trying to determine if I needed the destructor below implement the
 * creation of a char array in the method that I did in the constructor.
 *
 * I used the destructor for testing since it seemed like the best way to ensure I didn't cause
 * any problems while tyring to get the rest of my class to work.
 *
 * However, there is no destructor in the BloomFilter class, so I know I cannot submit code with that file.
 *
 * It appears my BloomFilter implementation in this file still works, but I didn't have a chance to test
 * it thoroughly with many devices. If I understand correctly that as long as memory allocation is small - like
 * a finite number of characters, the memory is free properly at the end of the program which seemed fine
 * for this program.
 *
 * I wanted to write all of this in case the grader ran into any problems. This code did work for me,so
 * I'm hoping it won't run into any problems anywhere else either.
 *
 ****/

//BloomFilter::~BloomFilter() {
//    delete [] bf;
//}

void BloomFilter::insert(string item) {

    /// Generate bitarray from char array
    int bits = (this->length) * 6;
    bool bitarray[bits];
    char_to_bitarray(this->bf, this->length, bitarray);

    /// check if new element is already in bitarray ELSE add the new bits
    if (!(this->exists(item))) {
        int a = h1(item, bits);
        int b = h2(item, bits);
        int c = h3(item, bits);
        int d = h4(item, bits);
        bitarray[a] = true;
        bitarray[b] = true;
        bitarray[c] = true;
        bitarray[d] = true;

        /// convert each 6 bits to a character and update char bloomfilter
        char* bf_ptr = this->bf;
        for (int i = 0; i < bits; i++) {
            if (i % 6 == 0) {
                unsigned char chr = 0;
                for (int j = 0; j < 6; j++) if (bitarray[i+j]) {
                    chr = chr + pow(2, 5-j);
                }
                char temp = chr + 48;  /// this gives me a char i can use
                *(bf_ptr) = temp;
                bf_ptr++;
            }
        }
    }
}

string BloomFilter::output() {
    return bf;
}

bool BloomFilter::exists(string item) {

    /// Generate bitarray from char array
    //bool* bitarray = char_to_bitarray(this->bf, this->length);
    int bits = (this->length) * 6;
    bool bitarray[bits];
    char_to_bitarray(this->bf, this->length, bitarray);

    /// Calculate hash functions and check if bits are filled
    int a = h1(item, bits);
    int b = h2(item, bits);
    int c = h3(item, bits);
    int d = h4(item, bits);

    if (bitarray[a] && bitarray[b] && bitarray[c] && bitarray[d])
        return true;
    else
        return false;
}