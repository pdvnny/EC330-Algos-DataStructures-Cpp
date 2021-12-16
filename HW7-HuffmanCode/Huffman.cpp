//
// Created by dvnny on 11/20/2021.
//

#include <iostream>
#include <queue>
//#include <filesystem>
#include "Huffman.h"

using namespace std;

/********** BINARY TREE CLASS *************************/

BinaryTree::BinaryTree(string c) {
    this->key = c;
    this->freq = 0;
    this->right = nullptr;
    this->left = nullptr;
}

BinaryTree::BinaryTree(string c, int f) {
    this->key = c;
    this->freq = f;
    this->right = nullptr;
    this->left = nullptr;
}

BinaryTree::~BinaryTree() {
    if (this->right != nullptr) delete this->right;
    if (this->left != nullptr) delete this->left;
}

int BinaryTree::getFreq() const{
    return this->freq;
}

string BinaryTree::getKey() const{
    return this->key;
}

void BinaryTree::print() {
    cout << "\nTree " << this->key << endl;
    cout << "Right of this node..." << endl;
    if (this->right == nullptr) cout << "NULLPTR" << endl;
    else this->right->print();
    cout << "Left of this node..." << endl;
    if (this->left == nullptr) cout << "NULLPTR" << endl;
    else this->left->print();
}

void BinaryTree::assignRight(BinaryTree* child) {
    this->right = child;
}
void BinaryTree::assignLeft(BinaryTree* child) {
    this->left = child;
}

BinaryTree* BinaryTree::getLeft() { return this->left; }
BinaryTree* BinaryTree::getRight() { return this-> right;}

/************* HUFFMAN CLASS **************/

Huffman::Huffman() {
    this->huffTree = nullptr;
}

Huffman::~Huffman() {
    delete this->huffTree;
}

void Huffman::buildHuffmanTree(char chars[], int freqs[], int s) {
    int running_size = 0;
    for (int i = 0; i < s; i++) {
        string tmp;
        tmp.push_back(chars[i]);
        this->code_chars.push_back(tmp);
//        character new_character = {tmp, freqs[i]};
//        min_heap.push(new_character);
        BinaryTree* new_bt = new BinaryTree(tmp, freqs[i]);
        this->nodes.push_back(new_bt);
        min_heap.push(new_bt);
    }
    /// PRINTING CHARACTERS INTERPRETED BY THE FUNCTION
    cout << "\nCharacters read in to code_chars:\n";
    for (auto & chr : this->code_chars) cout << chr << "\n";
    /// END OF PRINTING

    while (!min_heap.empty()) {
        if (min_heap.size() == 1) {
//            this->huffTree = nodes[running_size-1];  //*(nodes.end());
            this->huffTree = min_heap.top();
            min_heap.pop();
        } else {
//            character br1 = min_heap.top();
            BinaryTree* bt1 = min_heap.top();
            min_heap.pop();
//            character br2 = min_heap.top();
            BinaryTree* bt2 = min_heap.top();
            min_heap.pop();
            /// CREATING TREE - UNNEEDED NOW THAT I AM QUEUEING BINARYTREE*
//            BinaryTree* new_bt1 = nullptr;
//            BinaryTree* new_bt2 = nullptr;
//            if (br1.first.size() == 1) order.push_back(br1);
//            if (br2.first.size() == 1) order.push_back(br2);
            /// CHECK IF "TREE PULLED FROM QUEUE" ALREADY EXISTS
            // if (/* in nodes*/) {
                /// then find the already created node and use it
//            for (auto & nd : nodes) {
//                if (nd->getKey() == br1.first) new_bt1 = nd;
//                if (nd->getKey() == br2.first) new_bt2 = nd;
//            }
//            if (!new_bt1) new_bt1 = new BinaryTree(br1.first, br1.second);
//            if (!new_bt2) new_bt2 = new BinaryTree(br2.first, br2.second);

//            BinaryTree* new_node = new BinaryTree((br1.first + br2.first), (br1.second + br2.second));
//            new_node->assignLeft(new_bt1);
//            new_node->assignRight(new_bt2);
            BinaryTree* new_node = new BinaryTree((bt1->getKey() + bt2->getKey()), (bt1->getFreq() + bt2->getFreq()));
            new_node->assignLeft(bt1);
            new_node->assignRight(bt2);
            nodes.push_back(new_node);
            running_size++;
            /// CREATE NEW OBJECT FOR QUEUE
//            character new_character = {(br1.first + br2.first), (br1.second + br2.second)};
            /// ADD NEW PAIR TO QUEUE
//            min_heap.push(new_character);
            min_heap.push(new_node);
        }
    }
    /// PRINTING THE HUFFMAN TREE HERE
    this->huffTree->print();
    /// END OF PRINT CALL
    this->genCodes(this->huffTree->getLeft(), "0");
    this->genCodes(this->huffTree->getRight(), "1");
    /// PRINTING ALL HUFFMAN
    cout << "HUFFMAN CODES:\n";
    for (auto & code : this->code_chars)
        cout << code << "\n";
}

void Huffman::genCodes(BinaryTree* bt, string str) {
    if (bt->getLeft() == nullptr and bt->getRight() == nullptr) {
        code cd = {bt->getKey(), str};
//        this->code_chars.push_back(bt->getKey());
        this->codes.insert(cd);
    }
    if (bt->getLeft() != nullptr) genCodes(bt->getLeft(), (str + "0"));
    if (bt->getRight() != nullptr) genCodes(bt->getRight(), (str + "1"));
}

void Huffman::printCodes() {
  if (huffTree == nullptr) {
    cerr << "Huffman Tree has not been generated properly." << endl;
  } else {
      cout << "Huffman Code\t\tCharacter" << endl;
      cout << "________________________" << endl;
      for (auto itrr = this->code_chars.rbegin(); itrr != this->code_chars.rend(); itrr++) {
          cout << this->codes[(*itrr)] << "\t\t" << *itrr << endl;
      }
      cout << "\n";
  }
}

bool Huffman::inCodes(string code) {
    for (auto & [key, value]: this->codes) {
        if (value == code) return true;
    }
    return false;
}

void Huffman::decodeText(string filename) {
//  filesystem::path filepath = filesystem::current_path();
    ifstream file(filename, ifstream::in);
    string line;
    if (file.is_open()) {
        while (getline(file, line)) {
            cout << "The decoded text is: ";
            int itr = 0;
            while (itr < line.size()) {
                string new_code;
                while (!inCodes(new_code) and itr < line.size()) {
                    new_code.push_back(line.at(itr));
                    itr++;
                }
                /// FOUND CODE; TIME TO PRINT CORRESPONDING CHARACTER
                for (auto & [key, value]: this->codes)
                    if (value == new_code) cout << key;
            }
//              while (line.at(itr) == '1' and itr < line.size()) {
//                new_code += "1";
//                itr++;
//              }
//              if (new_code.size() < (codes.size() - 1)) {
//                new_code += "0";
//                itr++;
//              }
//              for (auto &[key, value]: this->codes)
//                if (value == new_code) cout << key;
//            }
            cout << endl;
        }
    } else {
        cerr << "File provided could not be opened." << endl;
    }
}