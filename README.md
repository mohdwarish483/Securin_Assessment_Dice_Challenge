# Securin Assessment Solution

## How to Run

To execute the code, simply compile and run the provided C++ program. Ensure that a C++ compiler is installed on your system.

```bash
g++ -o Dice Dice.cpp
./Dice
```


## Overview

This repository contains the solution for the Doomed Dice Challenge presented in the Securin assessment. The challenge involves dealing with two six-sided dice, Die A and Die B, and addressing specific conditions set by the mischievous Norse God Loki.

## Problem Statement

The task divided into two parts:

### Part A:

1. **Total Combinations:**
   - Calculate and display the total number of combinations possible by rolling both Die A and Die B together.

2. **Combination Distribution:**
   - Calculate and display the distribution of all possible combinations that can be obtained when rolling both Die A and Die B together.

3. **Probability of Sums:**
   - Calculate the probability of all possible sums occurring among the number of combinations.

### Part B:

The challenge involves transforming the dice according to Loki's conditions. The objective is to reattach the spots on the dice such that the following conditions are met:
- Die A cannot have more than 4 spots on a face.
- Die B can have as many spots on a face as necessary.

## Code Structure

1. **Main Function:**
   - Initializes original dice values.
   - Displays original dice values, total combinations, combination distribution matrix, and probabilities before transformation.
   - Calls the function to undo the transformation and prints the results.

2. **Dice Combinations Generation Functions:**
   - `dieAPossibleCombinations`: Generates all possible combinations for Dice A.
   - `dieBPossibleCombinations`: Generates all possible combinations for Dice B.

3. **Combinations Distribution and Probability Functions:**
   - `calculateCombinationDistribution`: Generates and displays the combination distribution matrix.
   - `calculateProbabilityOfSums`: Calculates and prints probabilities of sums before any transformation.

4. **Undooming the Dice:**
   - `undoom_dice`: Finds and displays the reattached spots on Dice A and Dice B, ensuring that the probability distribution matches the original.

5. **Global Variables:**
   - `sumCount`: An array to keep track of the occurrences of each sum (2-12).

## Output

======================================================================
Dice A before transformation : 1 2 3 4 5 6
======================================================================
Dice B before transformation: 1 2 3 4 5 6
======================================================================
Total Combinations : 36

======================================================================
Combination Distribution Matrix:
2 3 4 5 6 7
3 4 5 6 7 8
4 5 6 7 8 9
5 6 7 8 9 10
6 7 8 9 10 11
7 8 9 10 11 12

======================================================================

 Probabilities of sums before transformation:

======================================================================
P(Sum = 2) = 1/36 = 0.0277778
P(Sum = 3) = 2/36 = 0.0555556
P(Sum = 4) = 3/36 = 0.0833333
P(Sum = 5) = 4/36 = 0.111111
P(Sum = 6) = 5/36 = 0.138889
P(Sum = 7) = 6/36 = 0.166667
P(Sum = 8) = 5/36 = 0.138889
P(Sum = 9) = 4/36 = 0.111111
P(Sum = 10) = 3/36 = 0.0833333
P(Sum = 11) = 2/36 = 0.0555556
P(Sum = 12) = 1/36 = 0.0277778

=====================================================================
Undooming dice and Reattaching the spots :

======================================================================
Transformed DiceA : 1 2 2 3 3 4
======================================================================
Transformed DiceB : 1 3 4 5 6 8
======================================================================
Probability of sums After Transforming:
======================================================================
P(Sum = 2) = 1/36 = 0.0277778
P(Sum = 3) = 2/36 = 0.0555556
P(Sum = 4) = 3/36 = 0.0833333
P(Sum = 5) = 4/36 = 0.111111
P(Sum = 6) = 5/36 = 0.138889
P(Sum = 7) = 6/36 = 0.166667
P(Sum = 8) = 5/36 = 0.138889
P(Sum = 9) = 4/36 = 0.111111
P(Sum = 10) = 3/36 = 0.0833333
P(Sum = 11) = 2/36 = 0.0555556
P(Sum = 12) = 1/36 = 0.0277778

## Author

- **Warish**
- Roll Number: S20200010232
- Institution: IIIT Sri City Chittor


Feel free to reach out for any clarifications or additional information.

**Happy Coding!**
