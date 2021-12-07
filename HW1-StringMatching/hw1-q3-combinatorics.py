# -*- coding: utf-8 -*-
"""
Created on Mon Sep 13 20:53:37 2021

@author: Parker
"""

# Copyright 2021 pgdunn@bu.edu
# Name: Parker Dunn

# For EC330 HW1 - Questoin 3 - Combinatorics Questions

# For Part A - Need # of 12-digit hexidecimal values without characters


def convert_base(decimal_num):
    hexidec = ""
    while (decimal_num > 0):
        dig = decimal_num % 16
        decimal_num = decimal_num // 16        
        if (dig > 9):
            num = (dig-10) + 97  # 'a' = 97
        else:
            num = dig + ord('0') # ord('0') is the ASCII value of 0
        add_char = chr(num)
        hexidec = add_char + hexidec
    return hexidec

siz = 4
twelve_digit_nums = 16**siz

counter = 0;
only_digits = 0;

while (counter < twelve_digit_nums):
    hexnum = convert_base(counter)
    while (len(hexnum) < siz):
        hexnum = "0" + hexnum
    print(hexnum)
    if (hexnum.isnumeric()):
        only_digits += 1
    counter += 1
print("The number of only digit values was {}".format(only_digits))