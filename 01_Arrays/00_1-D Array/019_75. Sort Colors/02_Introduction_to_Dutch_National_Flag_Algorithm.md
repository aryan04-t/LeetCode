# "Three Pointer Approach" is also known as "Dutch National Flag Algorithm" 

- So, what is "Three Pointer Approach" and why is it known as "Dutch National Flag Algorithm", let's understand. 


## Dutch National Flag Algorithm

The **Dutch National Flag algorithm** is a sorting algorithm designed to sort an array of 0s, 1s, and 2s in linear time. It was proposed by **Edsger W. Dijkstra**, a Dutch computer scientist, in 1976. The algorithm is named after the national flag of the Netherlands, which consists of three horizontal stripes of red, white, and blue.

## Problem Description

The problem the algorithm addresses is often referred to as the **"Three-Way Partitioning" problem**. The goal is to rearrange the elements of an array so that all 0s come before all 1s, and all 1s come before all 2s. The Dutch National Flag algorithm achieves this in a single pass through the array.

## Three Pointer Approach

Here's a high-level explanation of the algorithm using a **Three Pointer Approach**:

1. Initialize three pointers: `low`, `mid`, and `high`.
   - `low` points to the start of the array.
   - `mid` points to the current element being processed.
   - `high` points to the end of the array.

2. Iterate through the array until `mid` crosses `high`.
   - If the element at `mid` is 0, swap it with the element at `low` and increment both `low` and `mid`.
   - If the element at `mid` is 1, leave it in its place and just increment `mid`.
   - If the element at `mid` is 2, swap it with the element at `high` and decrement `high`.

The algorithm works by maintaining three partitions in the array: elements less than 1 (0s), elements equal to 1, and elements greater than 1 (2s). The pointers `low` and `high` help manage these partitions, and the `mid` pointer scans through the array.

## Time Complexity

The Dutch National Flag algorithm is efficient and has a time complexity of O(n), where n is the number of elements in the array. It is particularly useful in situations where there is a need to sort an array with a small number of distinct values quickly.
