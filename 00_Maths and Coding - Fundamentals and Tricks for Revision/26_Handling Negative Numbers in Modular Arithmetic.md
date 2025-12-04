## ⚠️ Handling Negative Numbers in Modular Arithmetic

### Two Valid Remainder Conventions
In C++, when `n % k = m` where **n is negative** and **k is positive**:
- C++ returns **m in range [-k+1, 0]** (can be negative)
- Example: `-7 % 3 = -1` in C++

**Both -1 and 2 are mathematically correct for `-7 % 3`:**
- `-7 = (-3) × 3 + 2` → remainder is `2` ✓
- `-7 = (-2) × 3 + (-1)` → remainder is `-1` ✓

**Congruence in modular arithmetic:** We say `-1 ≡ 2 (mod 3)` (read as "-1 is congruent to 2 modulo 3")
- **Meaning:** `-1` and `2` differ by a multiple of `3` → they're equivalent in mod 3 world
- **Check:** `2 - (-1) = 3` which is `1 × 3` ✓
- **Key insight:** Numbers are congruent mod k if their difference is divisible by k

### 🎯 Why We Prefer [0, k-1] Range

For algorithms using **remainders as hash keys** or **array indices**, we need consistency:
- Arrays require **non-negative indices**
- For grouping we need **one canonical value** per group (not multiple valid options)
  - **Canonical** = the single "standard" representative we agree to use
  - Just like `-1 ≡ 2 ≡ 5 ≡ -4 (mod 3)` are all equivalent, we pick `2` as the canonical one in [0, k-1]
- Range [0, k-1] provides exactly k buckets: `0, 1, 2, ..., k-1`

**Example problem:** If `-7 % 5` could be either `-2` or `3`, which array index do we use?
```cpp
int count[5];  // Indices: 0, 1, 2, 3, 4
count[-2]++;   // ❌ Negative index - invalid!
count[3]++;    // ✅ Valid index in [0, 4]
```

**Solution:** Always convert to [0, k-1] range for consistent grouping.

### ✅ Converting Negative Remainders to [0, k-1]

**Simple approach - Check and add k if negative:**
```cpp
int remainder = n % k;
if (remainder < 0) {
    remainder += k;  // Shift to [0, k-1] range
}
// Now remainder is always in [0, k-1]
```

**One-liner approach - Always works:**
```cpp
int remainder = ((n % k) + k) % k;  // Always in [0, k-1]
```

**Why adding k works:**
- If C++ gives remainder `m` (where m lies in range `[-k+1, 0]`)
- Adding k to negative values shifts it to positive: `m + k` (now in range `0` to `k-1`)
- Both `m` and `m+k` represent the same equivalence class in modular arithmetic (differ by exactly k)

**Example:**
```cpp
-7 % 3 = -1        // C++ result
-1 + 3 = 2         // Add k to get canonical positive remainder
// Both -1 and 2 mean "1 less than a multiple of 3"
```

### 💡 Practical Examples

**Example 1: Grouping by Remainder**
```cpp
int k = 5;
vector<int> nums = {-7, 3, 8, -2};

// Without normalization - inconsistent grouping
-7 % 5 = -2   // Where does this go?
3 % 5 = 3
8 % 5 = 3     // Same group as 3
-2 % 5 = -2   // Same as -7, but negative index!

// With normalization - consistent [0, 4] grouping
int rem1 = -7 % 5;              // -2
if (rem1 < 0) rem1 += 5;        // 3 ✓

int rem2 = 3 % 5;               // 3 ✓
int rem3 = 8 % 5;               // 3 ✓

int rem4 = -2 % 5;              // -2
if (rem4 < 0) rem4 += 5;        // 3 ✓

// All four numbers correctly grouped to bucket 3!
```

**Example 2: Array-Based Counting**
```cpp
vector<int> nums = {-8, -3, 2, 7, 12};
int k = 5;
int count[k] = {0};

for (int num : nums) {
    int remainder = num % k;
    if (remainder < 0) remainder += k;  // Normalize to [0, k-1]
    count[remainder]++;
}
// count[2] = 5 (all numbers map to index 2)
```

### 🎯 When to Use This Conversion

**Use normalization when:**
- ✅ Using remainder as array index
- ✅ Using remainder as hash map key for grouping
- ✅ Algorithm requires all remainders in [0, k-1] range

**Pattern:** If you're working with negative numbers AND need consistent non-negative grouping → normalize to [0, k-1].