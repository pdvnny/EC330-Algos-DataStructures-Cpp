//
//  main.cpp
//  BloomFilter
//
//  Created by Tali Moreshet
//

#include <iostream>
#include "BloomFilter.h"

using namespace std;

int main(){
//    string my_str = "aab";
//
//    /* Try different sizes here */
//    BloomFilter my_filter(10);
//
//    cout << "My empty filter looks like: " << my_filter.output() << endl;
//
//    my_filter.insert(my_str);
//    cout << "Inserting " << my_str << endl;
//    cout << "My filter now looks like: " << my_filter.output() << endl;
//
//    cout << "Is " << my_str << " in my filter? ";
//    if (my_filter.exists(my_str)) cout << "\t\tYes." << endl;
//    else cout << "\t\tNo." << endl;
//
//    string fake_str = "bab";
//    cout << "Is " << fake_str << " in my filter? ";
//    if (my_filter.exists(fake_str)) cout << "\t\tYes." << endl;
//    else cout << "\t\tNo." << endl;
//
//    /// MORE INSERTS FOR TESTING!
//    string test1 = "parker";
//    string test2 = "grant";
//    string test3 = "dunn";
//
//    my_filter.insert(test1);
//    my_filter.insert(test3);
//
//    cout << "My filter now looks like: " << my_filter.output() << endl;
//
//    cout << "Is " << test2 << " in my filter? ";
//    if (my_filter.exists(test2)) cout << "\t\tYes." << endl;
//    else cout << "\t\tNo." << endl;

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
    BloomFilter myfilter(512);
    cout << "Here is my empty BloomFilter: " << myfilter.output() << "\n";

    // Testing insert of strings
    for (const string& str : sarray) myfilter.insert(str);

    // Looking at new bloomfilter
    cout << "BloomFilter with inserts: " << myfilter.output() << "\n";

    cout << "\nNow, testing if certain elements might be present.\n";
    for (const string& str : testarray)
        cout << "Does " << str << " exist? " << myfilter.exists(str) << "\n";

}
