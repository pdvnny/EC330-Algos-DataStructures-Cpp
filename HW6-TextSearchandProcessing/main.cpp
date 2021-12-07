#include <iostream>
#include "Problem4.h"

using namespace std;

int main()
{

    /// Getting started with implementations of the functions
//    cout << "Number of white spaces: " << fourA() << endl;
    cout << "Longest Word Length: " << fourA() << endl;
    cout << "Valid Passwords: " << fourB() << endl;
    cout << "Number of valid dictionary words: " << fourC() << endl;
//    cout << "Here is some testing of fourC:\n" << fourC() << "<-- return value\n";

    return 0;
}
/// USED FOR TESTING fourC()
//  search = dict.find("Aani");
//  cout << "Here is " << search->first << " in the dictionary: " << search->second << "\n";
//  search = dict.find("scalawaggy");
//  cout << "Here is " << search->first << " in the dictionary: " << search->second << "\n";
//  search = dict.find("alis");
//  if (search == dict.end()) cout << "alis resulted in end of dictionary.\n";
//  else cout << "Found alis unexpectedly.\n";
//  search = dict.find("aback");
//  if (search == dict.end()) cout << "aback resulted in end of dictionary.\n";
//  else cout << "Found aback unexpectedly.\n";