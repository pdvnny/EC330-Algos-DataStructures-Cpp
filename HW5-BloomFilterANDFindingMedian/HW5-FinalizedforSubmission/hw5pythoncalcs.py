# -*- coding: utf-8 -*-
"""
Created on Thu Nov  4 14:42:16 2021

@author: dvnny
"""
import statistics as stat

#%%

numbers = [89, 19, 50, 59, 70, 26]

hash_vals = [num % 11 for num in numbers]
print(hash_vals)

#%%

"""     HOMEWORK 5 - PROBLEM 1
    
    Taking a new approach to this problem. I am going to use some inforamtion
    given about the problem and the arrays to try to approach this problem.

    KNOW:
        (1) (*from TA*) the solution should be better than THETA(n)
        (2) "Selection" is part of the solution
        (3) The incoming arrays are sorted
        (4) (!!!!!) the 

"""

def median_two_lists(A, B, n):

    # just printing out the actual median
    AB = A + B
    AB.sort();
    print("\nMedian is {}".format(stat.median(AB)))

    # the actual algorithm
    ai = 0
    bi = 0
    for i in range(n-1):
        # print("\nHere is A[ai] {} and B[bi] {}".format(A[ai], B[bi]))
        if (A[ai] >= B[bi]):
            bi += 1
        else:
            ai += 1
    # determine what value to return
    if (A[ai] >  B[bi]):
        num1 = B[bi]
        bi +=1
        # print("IF -- Num1 is {}. Preparing to a pick the second A[ai] {} OR B[bi] {}".format(num1, A[ai], B[bi]))
        if (A[ai] >= B[bi]):
            num2 = B[bi]
        else:
            num2 = A[ai]

    elif (B[bi] > A[ai]):
        num1 = A[ai]
        ai += 1
        # print("ELIF -- Num1 is {}. Preparing to a pick the second A[ai] {} OR B[bi] {}".format(num1, A[ai], B[bi]))
        if (A[ai] >= B[bi]):
            num2 = B[bi]
        else:
            num2 = A[ai]
    else:
        # print("ELSE A[ai] is {} and B[bi] is {}".format(A[ai], B[bi]))
        num1 = A[ai]
        num2 = B[bi]

    return (num1 + num2) / 2

def median_two_lists2(A, B, n):
    # just printing out the actual median
    AB = A + B
    AB.sort();
    print("\nMedian is {}".format(stat.median(AB)))

    #printing out the elements of each list between the medians
    medA = stat.median(A)
    medB = stat.median(B)
    if (medA > medB):
        Abeg = [el for el in A if el < medA]
        Bend = [el for el in B if el > medB]
        print("medA is greater than medB ", Bend + Abeg)
    elif (medB > medA):
        Aend = [el for el in A if el > medA]
        Bbeg = [el for el in B if el < medB]
        print("medB is greater than medA ", Aend + Bbeg)
    else:
        print("medA and medB were equal.")

    # The better version of the algorithm

def larger_median_and_splice(A, B, medA, medB):
    if (medB > medA):
        newA = [a for a in A if a >= medA]
        newB = [b for b in B if b <= medB]
    else:
        newA = [a for a in A if a <= medA]
        newB = [b for b in B if b >= medB]
    return newA, newB
     
def soln_med_two_lists(A, B, n):
    if (n == 1):
        return (A[0] + B[0])/2.0
    if (n % 2):  # ODD SIZES
        medA = A[n//2]
        medB = B[n//2]
        halfA, halfB = larger_median_and_splice(A, B, medA, medB)
        return soln_med_two_lists(halfA, halfB, len(halfA))
    
    else: # EVEN SIZES
        medA = (A[n//2 - 1] + A[n//2]) / 2
        medB = (B[n//2 - 1] + B[n//2]) / 2
        halfA, halfB = larger_median_and_splice(A, B, medA, medB)
        return soln_med_two_lists(halfA, halfB, len(halfA))


#%%

A = list(range(1,11,2)) # size = 5
B = list(range(2,12,2)) # size = 5

A1 = list(range(3,8,1))
B1 = list(range(1,6,1))

C = [3, 4, 9, 10, 11]
D = [1, 2, 3, 4, 5]

E = [1, 4, 6, 7]
F = [1, 7, 8, 10]

print("Algorithm returned median = {}".format(soln_med_two_lists(A1, B1, len(A))))
print("Algorithm returned median = {}".format(soln_med_two_lists(C, D, len(C))))
print("Algorithm returned median = {}\n".format(soln_med_two_lists(E, F, len(C))))

median_two_lists2(A1, B1, len(A))
median_two_lists2(C, D, len(C))
#median_two_lists2(C, B, len(C))
median_two_lists2(E, F, len(E))

#%%


    # if (ai > bi):
    #     num1 = B[bi]
    #     bi += 1
    #     if (A[ai] => B[bi]):
    #         num2 = B[bi]
    #     else:
    #         num2 = A[ai]
    # elif (bi < ai):
    #     num1 = A[ai]
    #     ai += 1
    #     if (A[ai] => B[bi]):
    #         num2 = B[bi]
    #     else:
    #         num2 = A[ai]
    # else:
    #     num1 = A[ai];
    #     num2 = B[];

