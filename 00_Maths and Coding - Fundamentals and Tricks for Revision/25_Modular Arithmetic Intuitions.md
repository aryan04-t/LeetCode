# 🔢 Modular Arithmetic Key Concepts and Intuitions 

## 📌 Basic Rule
When `n % k = m`, where n and k are positive integers, then **m is always in range [0, k-1]**

## ✨ Distributive Property of Modulus

### Addition
```
(a + b) % k = ((a % k) + (b % k)) % k
```

### Multiplication
```
(a × b) % k = ((a % k) × (b % k)) % k
```

### ⚠️ Division (Does NOT work)
```
(a / b) % k ≠ ((a % k) / (b % k)) % k
```

## 🚀 Preventing Overflow 

**Problem:** `(a[0] + a[1] + a[2] + ... + a[n-1]) % k` can overflow (1 <= k <= 10^8, and 1 <= a[i] <= 10^8, and 1 <= a.size() <= 10^4) 

**Solution:** Apply modulus at intermediate steps
```cpp
int result = 0;
for (int i = 0; i < n; i++) {
    result = (result + a[i]) % k;
}
```

**Why it works:** Only remainders matter for final remainder. Complete groups of k always divide evenly, and even after applying modulus at intermediate steps - due to `distributive property of modulus in addition` we're able to achieve the same output as `(a1 + a2 +a3 + ...) % k`.

## 💡 Key Insight
You can apply `% k` at **any intermediate step** in the case of **addition** without changing the final result.

**Result always stays in range [0, k-1]** → No overflow! ✅

- - - 

## 🔄 Cyclic Nature & Grouping with Remainders

### Remainders as Hash Keys
Since remainders are bounded in range **[0, k-1]**, they exhibit cyclic behavior:
- Different numbers can share the same remainder → natural grouping mechanism
- Use remainders as **hash map keys** to group values with identical modulo results
- Pattern: `n % k`, `(n + k) % k`, `(n + 2k) % k` all produce the same remainder

### Array-Based Hashing Optimization
The range **[0, k-1]** directly maps to array indices of size k:
- **Instead of hash map**: Use `int count[k]` where `count[r]` tracks frequency of remainder `r`
- **Direct indexing**: `count[num % k]++` maps remainder to array position
- **Benefits**: Eliminates hashing overhead, O(1) access with no collisions

**Example:**
```cpp
// Hash map approach
unordered_map<int, int> remainderCount;
remainderCount[num % k]++;

// Optimized array approach (when k is small)
int count[k] = {0};
count[num % k]++;
```

**When to use array over hash map:** If k ≤ 10^5, array indexing is faster and more memory-efficient than hash map operations.


## Reference Questions with Modular Arithmetic Intuitions Requirement:

3381. Maximum Subarray Sum With Length Divisible by K - [Link](https://leetcode.com/problems/maximum-subarray-sum-with-length-divisible-by-k)

166. Fraction to Recurring Decimal - [Link](https://leetcode.com/problems/fraction-to-recurring-decimal)

1590. Make Sum Divisible by P - [Link](https://leetcode.com/problems/make-sum-divisible-by-p)

974. Subarray Sums Divisible by K - [Link](https://leetcode.com/problems/subarray-sums-divisible-by-k)