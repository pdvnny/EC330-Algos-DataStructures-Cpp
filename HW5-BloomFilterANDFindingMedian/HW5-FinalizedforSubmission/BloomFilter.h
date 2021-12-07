//
//  BloomFilter.h
//  BloomFilter
//
//  Created by Tali Moreshet, adapted from Ari Trachtenberg
//

#ifndef BloomFilter_h
#define BloomFilter_h

#include <string>

using namespace std;

class BloomFilter {
public:
    /** Instantiate an empty Bloom filter of length 'len' chars. **/
    //BloomFilter (int len){ length=len; }
    BloomFilter (int len);
//    ~BloomFilter();
    
    /** Inserts item into the filter **/
    void insert(string item);
    
    /**
     * Checks whether item is in the filter.
     * RETURNS true if the item is probably in the filter
     * RETURNS false if the item is definitely not in the filter
     */
    bool exists(string item);
    
    /** Returns a string of characters representing the Bloom filter **/
    string output();
    
protected:
    int length;     /** The length of the Bloom filter, in chars. */
    char *bf;       /** The Bloom filter */
};

#endif /* BloomFilter_h */


/********** NOTES ABOUT ASSIGNMENT **************

NOTE: Here is a curretly functional command to compile
       main.cpp with BloomFilter.h and MyBloomFilter.cpp

  "g++ -o bf -std=c++17 ./main.cpp ./MyBloomFilter.cpp

FROM RE-READING ASSIGNMENT:
-

/// TODO: Things that still confuse me...
     (1) How does the bitmap STL work?
     (2) A char array is initialized for the bf, but
            what do we need it for?
     (3) How am I meant to handle string inputs?


 REFERENCE LINKS USED:
 (1) https://daankolthof.com/2019/05/06/implementing-a-simple-high-performance-bloom-filter-in-c/
 (2) https://en.wikipedia.org/wiki/MD5
 (3) http://practicalcryptography.com/hashes/md5-hash/
 (4)


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


**************************************************/