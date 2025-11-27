# 🔢 Modular Arithmetic Key Concepts Revision

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