# Sum Questions Tips

## Maximizing/Minimizing Sum

### Maximizing Sum or Vice Versa
- When you have to **maximize a sum** with a given constraint:
  - Pick the maximum elements, or
  - Remove the most minimum elements
- When you have to **minimize a sum** with a given constraint:
  - Pick the minimum elements, or
  - Remove the most maximum elements
- **Greedy approach**: Sort and pick from appropriate end

- - - 


## Prefix Sum

### When to Use Prefix Sum
- Calculate **range sum queries** efficiently: O(1) after O(n) preprocessing
- Find subarrays with **specific sum**
- Problems involving **cumulative values**

### Formula
```
prefix[i] = prefix[i-1] + arr[i]
sum(l, r) = prefix[r] - prefix[l-1]
```

- - -


## Suffix Sum

### When to Use Suffix Sum
- Need sum of elements **after** current index
- Problems requiring both left and right context

### Formula
```
suffix[i] = arr[i] + suffix[i+1]
```

- - - 


## Two Sum Patterns

### HashMap (Unsorted Array)
- **Build map on the run** to track only prior processed elements
- Store `(value, index)` or `(complement, index)` as you iterate
- Check if `target - current` exists in map before adding current element
- Time: O(n), Space: O(n)

### Two Pointers (Sorted Array)
- One pointer at **start**, one at **end**
- If `sum < target`: move **left** pointer right (increase sum)
- If `sum > target`: move **right** pointer left (decrease sum)
- If `sum == target`: found the pair
- Exploits **monotonicity** of sorted array
- Time: O(n), Space: O(1) 