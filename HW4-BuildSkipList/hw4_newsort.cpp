// Copyright 2021 Parker Dunn pgdunn@bu.edu
// Created by dvnny on 10/17/2021.
//

#include<iostream>

using namespace std;

void newsort(int array[], int size) {
    for (int i = 1; i < size; i++) {
        int x = array[i];
        int k = 0;
        for (int j = 0; j < i; j++) {
            if (array[j] <= x) {
                k++;
                int temp = array[k];
                array[k] = array[j];
                array[j] = temp;
                cout << "\nAt some point array[j] was less than or equal to x\n" <<
                        "Here is array[j]: " << array[j] << " and here is x: " << x << "\n";
            }
        }
        int temp2 = array[k+1];
        array[k+1] = array[i];
        array[i] = temp2;

        cout << "i = " << i << "and k = " << k << "\n";
        for (int d = 0; d < size; d++) {
            cout << array[d] << " ";
        }
        cout << "\n";
    }
}

int main() {

    int test1[6] = {6, 5, 4, 3, 2, 1};
    int test2[6] = {2, 4, 3, 5, 1, 6};

    for (int i = 0; i < 6; i++) {
        cout << test2[i] << " ";
    }
    cout << "\n";
    newsort(test2, 6);
//    for (int i = 0; i < 6; i++) {
//        cout << test1[i] << " ";
//    }
    cout << "\n";
    return 0;
}
