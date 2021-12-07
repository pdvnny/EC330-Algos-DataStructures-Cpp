/****************************************************************
 *
 * Copyright 2021 Parker Dunn
 *
 * Created as part of HW5 assignment for EC330
 *
 * We were tasked with building a variation of a BloomFilter
 * and I wanted to build a similar one to something I found on the internet
 * before making improvements and modifications to fit the requirements of
 * the assignment.
 *
 * We were allowed to use code/hash functions from research as part of the
 * assignment as long as everything is referenced.
 ***************************************************************/

/*** NOTES ABOUT IMPLEMENTING A BLOOMFILTER *****
 *
 *  ADD
 *      - save all hash numbers in a vector
 *      - use bitset.set() method to change the bit to 1
 *          at each of these saved hash values
 *
 ***********************************************/

/********* TESTING A SIMPLE BLOOM FILTER FIRST***********
 *
 * Relevent links:
 * (1) General BloomFilter code and info about bloom filters (GREAT LINK): https://www.geeksforgeeks.org/bloom-filters-introduction-and-python-implementation/
 * (2)
 *
 *
 *******************************************************/

#include <iostream>
#include "BloomFilter.h"

using namespace std;

int main() {
    string sarray[33]
            = { "abound",   "abounds",       "abundance",
                "abundant", "accessable",    "bloom",
                "blossom",  "bolster",       "bonny",
                "bonus",    "bonuses",       "coherent",
                "cohesive", "colorful",      "comely",
                "comfort",  "gems",          "generosity",
                "generous", "generously",    "genial",
                "bluff",    "cheater",       "hate",
                "war",      "humanity",      "racism",
                "hurt",     "nuke",          "gloomy",
                "facebook", "geeksforgeeks", "twitter" };
    string testarray[20]
            = {"abounds",  "abundance",  "abundant",      "accessable",
               "bloom",    "blossom",    "bolster",       "bonny",
               "parker",   "ec330",      "university",    "toyota",
               "comfort",  "gem",        "twitter",       "josh",
               "advanced", "algorithms", "facebook",      "data"};

    // Testing output of blank bloomfilter
    BloomFilter myfilter(1024);
    cout << "Here is my empty BloomFilter: " << myfilter.output() << "\n";

    // Testing insert of strings
    for (const string& str : sarray) myfilter.insert(str);

    // Looking at new bloomfilter
    cout << "BloomFilter with inserts: " << myfilter.output() << "\n";

    cout << "\nNow, testing if certain elements might be present.\n";
    for (const string& str : testarray)
        cout << "Does " << str << " exist? " << myfilter.exists(str) << "\n";

    return 0;
}
