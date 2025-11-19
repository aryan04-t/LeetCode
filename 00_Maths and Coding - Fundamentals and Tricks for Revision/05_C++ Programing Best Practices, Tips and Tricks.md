# C++ Programming Best Practices & Tips

## Odd/Even Number Checking

* To find whether a number is odd or even, use bitwise AND (&), try to stay away from modulus it is a heavy operation

**Example Code:**
```cpp
if(num & 1){
    cout << "Number is Odd" << endl;
}
else{
    cout << "Number is Even" << endl;
}
```

---

## Dynamic Memory Management

* Always remember "new" keyword returns a "pointer"
* Always delete the dynamically allocated memory using the "delete" keyword

**Important:** Use "delete" for freeing memory a dynamically allocated variable or object's memory, and use "delete[]" for freeing a dynamically allocated "array's" memory.

---

## Linked List Pointer Safety

* Never forget to check that a "pointer" should not be pointing to null before checking its next or prev in a "Linked List"

---

## Container Safety Checks

* Never forget to check that:
  - A "Vector" should not be empty before calling its "back()" member function
  - A "Stack" should not be empty before calling its "top()" member function
  - A "Queue" should not be empty before calling its "front()" member function
  - A "Deque" should not be empty before calling its "front()" or "back()" member function

---

## Binary Search

**Prerequisite:** The data set should be in sorted order before applying binary search.

---

## Heap Conversion Trick

If you're only allowed to use max_heap but you want to use min_heap, then you can make the max_heap into min_heap by just multiplying the numbers with -1 before inserting and after retrieval also multiply the number -1 to recover the original number value.

--- 

## Subarray/Substring Counting Pattern

* When counting valid subarrays/substrings, if you extend a valid streak by one element, you add **k new subarrays** where k is the current length of the streak

**Example:**
```
Array: [1, 2, 3]
- At index 0: streak length = 1, adds 1 new subarray → [1]
- At index 1: streak length = 2, adds 2 new subarrays → [2], [1,2]
- At index 2: streak length = 3, adds 3 new subarrays → [3], [2,3], [1,2,3]
Total = 1 + 2 + 3 = 6 subarrays
```

* For a continuous valid range of length **n**, the total number of subarrays/substrings = **n × (n + 1) / 2**
  - This is the sum of natural numbers formula: 1 + 2 + 3 + ... + n
  - Use this when you need to count all possible subarrays in a contiguous valid segment