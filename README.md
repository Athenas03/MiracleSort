# MiracleSort - Sorting Algorithm Comparison

## Overview

This project implements and compares three different sorting algorithms using C++: **Bubble Sort, Insertion Sort, and Merge Sort**.

The purpose of the project is to understand how different sorting algorithms work, how they handle different data types, and how their performance compares when sorting large amounts of data.

The program sorts integers, characters, and strings before generating an array of 100,000 random floating-point numbers to measure and compare the execution times of each sorting algorithm.

## Technologies Used

- C++
- C++ Standard Library
- Vectors and Templates
- Chrono Library (performance timing)
- Random Number Generation
- Mathematical Functions

## Sorting Algorithms

The project implements three sorting algorithms.

### 1. Bubble Sort

Bubble Sort repeatedly compares adjacent elements and swaps them if they are in the wrong order.

This process continues until the entire array is sorted.

- Compares neighboring elements.
- Swaps elements when necessary.
- Has an average and worst-case time complexity of O(n²).

### 2. Insertion Sort

Insertion Sort builds a sorted portion of the array one element at a time.

It takes each element and inserts it into its correct position among the previously sorted elements.

- Starts with the second element.
- Compares it with elements before it.
- Shifts larger elements to the right.
- Inserts the current element into its correct position.
- Has an average and worst-case time complexity of O(n²).

### 3. Merge Sort

Merge Sort uses the divide-and-conquer approach to sort an array.

It recursively divides the array into smaller sections until each section contains one element. It then merges the sections back together in sorted order.

- Divides the array into smaller halves.
- Recursively sorts each half.
- Merges the sorted halves together.
- Has a time complexity of O(n log n).

## Sorting Different Data Types

The program uses C++ templates to allow all three sorting algorithms to work with different data types.

The program tests sorting with:

- **Integers:** A collection of 21 integer values.
- **Characters:** Individual characters spelling "ChatGpt".
- **Strings:** A collection of six words, including "good", "morning", "Dearborn", and "Data".

Each sorting algorithm is tested with all three data types, and the sorted results are displayed in the console.

## Random Number Generation and Statistics

The program generates an array containing **100,000 random floating-point numbers**.

Each number is generated within a range of 0 to 50,000.

After generating the array, the program calculates two statistical measurements:

### Mean

The mean represents the average value of all numbers in the array.

It is calculated by adding all the values together and dividing by the total number of elements.

### Standard Deviation

Standard deviation measures how spread out the numbers are from the mean.

The program calculates the standard deviation using the differences between each value and the mean.

Both the mean and standard deviation are displayed in the console.

## Performance Comparison

The program measures how long each sorting algorithm takes to sort the same array of 100,000 random floating-point numbers.

It uses the C++ `chrono` library to measure execution time in milliseconds.

To ensure a fair comparison, the program creates three copies of the original random array. Each sorting algorithm receives its own copy of the same data.

The execution times are displayed for:

- Bubble Sort
- Insertion Sort
- Merge Sort

This allows the performance of the three algorithms to be compared using the same dataset.

## How to Run

### Requirements

- A C++ compiler that supports C++11 or later.
- A development environment such as Visual Studio or g++.

### Compiling

If using g++, compile the program with:

```bash
g++ -std=c++11 MiracleSort.cpp -o MiracleSort
```

### Running

Execute the compiled program:

```bash
./MiracleSort
```

On Windows, run:

```bash
MiracleSort.exe
```

Replace `MiracleSort.cpp` with the actual name of your source file if it is different.

## Output

The program displays the following information:

1. Bubble Sort results for integers, characters, and strings.
2. Insertion Sort results for integers, characters, and strings.
3. Merge Sort results for integers, characters, and strings.
4. The first 30 randomly generated floating-point numbers.
5. The mean of the 100,000 random numbers.
6. The standard deviation of the random numbers.
7. The execution time of each sorting algorithm in milliseconds.

## Project Goal

The goal of this project was to explore and compare different sorting algorithms while understanding their efficiency and performance.

By implementing Bubble Sort, Insertion Sort, and Merge Sort, the project demonstrates how different approaches to sorting affect execution time, especially when working with large datasets.

It also demonstrates the use of C++ templates, vectors, recursion, statistical calculations, and performance measurement to analyze sorting algorithms.
