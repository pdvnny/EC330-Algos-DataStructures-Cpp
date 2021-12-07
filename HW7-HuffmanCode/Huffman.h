//
// Created by dvnny on 11/20/2021.
//

#ifndef HW7_HUFFMAN_H
#define HW7_HUFFMAN_H

#include<queue>
#include<map>
#include<string>
#include<fstream>

typedef std::pair<std::string, int> character;
typedef std::pair<std::string, std::string> code;

using namespace std;

/*********************** FULL BINARY TREE ************************/

class BinaryTree {
private:
    int freq;
    string key;
    BinaryTree* left;
    BinaryTree* right;
public:
    explicit BinaryTree(string);
    BinaryTree(string, int);
    BinaryTree(const BinaryTree &BT);
    ~BinaryTree();
//    BTNode* root;
    [[nodiscard]] string getKey() const;
    [[nodiscard]] int getFreq() const;  /// NO IDEA WHY BUT CLION WANTED THIS TO BE MARKED
    void print();
    void assignLeft(BinaryTree*);
    void assignRight(BinaryTree*);
    BinaryTree* getLeft();
    BinaryTree* getRight();

    /// FOR THIS USE CASE WE DON'T NEED A LOT OF STANDARD BINARY TREE METHODS
//    BTNode* find(int); /// Use this method to find the insertion location for a new node
//    BTNode* insert(char, int); /// Will call on Node insert methods to perform the actual insertion
};

/**************** HUFFMAN CLASS AND RELATED STRUCTURES **********/

class myComparator {
public:
    int operator() (const character& chr1, const character& chr2) {
        if (chr1.second == chr2.second) {
            return chr1.first.size() > chr2.first.size();
        } else {
            return chr1.second > chr2.second;
        }
    }
};

class Huffman {
private:
    BinaryTree* huffTree;
    map<string, string> codes;
public:
    Huffman();
    ~Huffman();
    priority_queue<character, vector<character>, myComparator> min_heap;
    vector<BinaryTree*> nodes;
    vector<string> code_chars;
    void buildHuffmanTree(char [], int [], int);
    void printCodes();
    void genCodes(BinaryTree*, string);
    void decodeText(string);
};

#endif //HW7_HUFFMAN_H
