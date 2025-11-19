# push_swap

## Overview
This project implements a program that sorts a sequence of integers using **two stacks** (A and B) and a **limited set of allowed operations** (swap, push, rotate, reverse rotate).  
The goal is to produce the **shortest possible sequence of operations** that results in a fully sorted stack A.

## Approach
I implemented a bucket-based radix sorting algorithm.  
The algorithm processes the list **bit by bit**, distributing elements between stack A and B and restoring them in sorted order.  

This approach guarantees:
- stable performance  
- predictable number of operations  
- consistent execution time regardless of initial order  

## Usage
Compile:
```make```

Run:
```./push_swap [list of numbers]```