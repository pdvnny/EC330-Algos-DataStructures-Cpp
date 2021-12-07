//
// Created by dvnny on 11/5/2021.
//

/// TESTING A NEW IDEA THAT I HAD FOR QUESTION 1 ON HW5

#include<iostream>
#include<string>

using namespace std;


/// THIS STILL DOESN'T QUITE WORK ... DEBUGGING SHOWS THAT THE WHILE LOOPS DON'T QUITE WORK
/// FOR ARRAYS WITH AN EVEN NUMBER OF INDICES

//double median2arrays (int* A, int* B, int n) {
//    if (n % 2) {
//        int i = n/2;
//        int j = n/2;
//        /// decide if median of A[i] or median of B[i] is greater
//        /// then move one of the iterators back to 0
//        if (A[i] > B[j])
//            i = 0;
//        else if (B[j] > A[i]) {
//            j = 0;
//        } else {   /// if medians are the same return the average of them
//            return (A[i] + B[j]) / 2.0;
//        }
//        /// move iterators until we have the middle two!
//        while (i + j < (n+2)) {
//            if (A[i + 1] == A[i] or A[i+1] == B[j]) i++;
//            else if (B[j + 1] == B[j] or B[j+1] == A[i]) j++;
//            else if (A[i] > B[j]) j++;
//            else if (B[j] > A[i]) i++;
////            else if (A[i + 1] > B[j + 1]) j++;
////            else if (B[j + 1] > A[j + 1]) i++;
//            else if (j > i) i++;
//            else j++;
//        }
//
//        return (A[i] + B[j]) / 2.0;
//
//    } else {
//        int i = n/2;
//        int j = n/2;
//        if (A[i] > B[j])
//            i = 0;
//        else if (B[j] > A[i]) {
//            j = 0;
//        } else {
//            return (A[i] + B[j]) / 2.0;
//        }
//
//        while (i + j < n) {
//            if (A[i + 1] == A[i] or A[i+1] == B[j]) i++;
//            else if (B[j + 1] == B[j] or B[j+1] == A[i]) j++;
//            else if (A[i] > B[j]) j++;
//            else if (B[j] > A[i]) i++;
////            else if (A[i + 1] > B[j + 1]) j++;
////            else if (B[j + 1] > A[j + 1]) i++;
//            else if (j > i) i++;
//            else j++;
//        }
//
//        return (A[i] + B[j]) / 2.0;
//    }
//}

//double median2arrays(int* A1, int* A2, int size) {
//  if (size == 1)
//
//}

int main() {
    int C[5] = {3, 4, 5, 6, 7};
    int D[5] = {1, 2, 3, 4, 5};

    int E[4] = {1, 4, 6, 7};
    int F[4] = {1, 7, 8, 9};


    //double medCD = median2arrays(C, D, 5);
    double medEF = median2arrays(E, F, 4);

    //cout << "Median of C & D: " << medCD << "\n";
    cout << "Median of E & F: " << medEF << "\n";

    return 0;
}

