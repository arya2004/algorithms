# Dearrangements

This directory contains implementations of the dearrangements algorithm in various programming languages.

A dearrangement is a permutation of the elements of a set, such that no element appears in its original position.

The number of dearrangements of a set of size n, denoted by !n, can be calculated using the following formula:
!n = (n-1) * (!(n-1) + !(n-2))

The implementations in this directory are:
- C: `c/dearrangements.c`
- C++: `dearrangements.cpp`
- Go: `dearrangements.go`
- Java: `Dearrangements.java`
- JavaScript:
    - `dearrangements.iterative.js`
    - `dearrangements.recursive.js`
- Python: `dearrangements.py`
