# Subarray/Substring - Formation, Intuition and Observations

## Core Formula
- **Time Complexity**: O(n²) or precisely `n(n+1)/2`
- Derives from **sum of first n natural numbers**: `1 + 2 + 3 + ... + n = n(n+1)/2`

## Nested Loop Pattern (Standard)
```
for i = 0 to n-1:
    for j = i to n-1:
        // process subarray[i...j]
```
- Outer loop runs n times
- Inner loop runs: n, n-1, n-2, ..., 1 times
- Total iterations = n + (n-1) + (n-2) + ... + 1 = n(n+1)/2

## Intuition: Each Length Adds Its Count
When adding element to array of length n → contributes **n new subarrays**

### Example Progression
- `arr = [1, 2, 3, 4]` (length 4) → 10 subarrays
- Add element: `arr = [1, 2, 3, 4, 5]` (length 5)
- **New subarrays from index 4**: `[5], [4,5], [3,4,5], [2,3,4,5], [1,2,3,4,5]` → 5 new
- **Total**: 10 + 5 = 15 subarrays

### Pattern
- Length 1 → 1 subarray
- Length 2 → 1 + 2 = 3 subarrays  
- Length 3 → 1 + 2 + 3 = 6 subarrays
- Length n → 1 + 2 + ... + n = n(n+1)/2 subarrays

## Key Takeaway
Each new element at position i contributes **(i+1) new subarrays** - all subarrays ending at that position

## Distribution by Length
For array of length n, subarrays are distributed as:
- **Length 1**: n subarrays (each single element)
- **Length 2**: n-1 subarrays (each consecutive pair)
- **Length 3**: n-2 subarrays (each consecutive triplet)
- **Length k**: n-k+1 subarrays
- **Length n**: 1 subarray (entire array)

**Total**: n + (n-1) + (n-2) + ... + 1 = n(n+1)/2

## Alternative Pattern (Length-based Sliding Window)
```
for length = 1 to n:           // outer loop defines subarray length
    for i = 0 to n-length:      // inner loop slides window across array
        // process subarray[i...i+length-1]
```
- Outer loop: iterates through lengths 1 to n
- Inner loop: slides window of current length across array
- Same complexity: n + (n-1) + (n-2) + ... + 1 = n(n+1)/2