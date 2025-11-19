# PUSH_SWAP

## Overview:
This Project is about creating an algorithm that uses only stacks of numbers to sort a given sequence.
For this the sequence is inserted into stack A and then a given set of operations on stack A is allowed to move elements to stack B and back.
The algorithm outputs a sequence of these operations which after execution lead to a sorted stack A.

## Logic:
I am using a bucket sort algorithm to sort the numbers bit by bit into the two stacks, which leads to a stable algorithm with constant execution
time and operations used, regardless of the order of the numbers.

## Execution:
- make
- ./push_swap [list of numbers to sort]