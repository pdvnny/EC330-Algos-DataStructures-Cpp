//
//  main.cpp
//  Huffman
//
//  Created by Tali Moreshet
//

#include <iostream>
#include <fstream>
#include "Huffman.h"

using namespace std;

int main(int argc, const char * argv[]) {
    char characters[] = {'b', 'p', 'r', 'o', 'k', 'e'};
	int freq[] = {1, 1, 1, 2, 2, 3};

    int size = sizeof(characters) / sizeof(characters[0]);
    
    Huffman huffman;
    
    huffman.buildHuffmanTree(characters, freq, size);
    huffman.printCodes();
    
    if (argc != 2)
        cout << "Please supply a file name with Huffman encoded text\n";
    huffman.decodeText(argv[1]);
    
    return 0;
}
