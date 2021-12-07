//
// Created by dvnny on 11/3/2021.
//
#include<bitset>
#include<iostream>
#include<string>

using namespace std;

string int2bin(int num) {
    string bin;
    while (num > 0) {
        char dig = num % 2 + '0';
        bin = dig + bin;
        num = num / 2;
    }
    return bin;
}

int main() {

    char* chrptr;
    chrptr = new char[10];
    char* tempptr = chrptr;
    for (int i = 0; i < 10; i++) {
        *tempptr = 'a';
        tempptr++;
    }

    cout << "Chrptr is :" << chrptr << "\n";
    cout << "tempptr is: " << tempptr << "\n";
    cout << "tempptr - 10 is: " << (tempptr - 9) << "\n";


    delete [] chrptr;


//    cout << "Attempt to 'copy and past' to get this working.\n";
//    cout << "mystr: " << mystr << "\nchrptr: " << chrptr << "\nnew_str: " << new_str << "\n";

//    int input = 7;
//    cout << "7 in binary? " << int2bin(input) << "\n";
//
//    input = 65;
//    cout << "64 in binary? " << int2bin(input) << "\n";
//
//    input = 4;
//    cout << "4 in binary? " << int2bin(input) << "\n";
//
//
//    bitset<32> tmp(string("1010101010101010"));
//    cout << "tmp: " << tmp << "\n";

//    bool* bref = &tmp;
//    cout << "bref: " << bref << "\n";

    return 0;
}
