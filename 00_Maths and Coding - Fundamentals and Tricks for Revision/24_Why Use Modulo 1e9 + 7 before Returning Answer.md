# What is (1e9 + 7)?

- `1e9 + 7` is scientific notation in C++ (and many other programming languages) representing 10^9 + 7, which equals 1,000,000,007 (1 billion and 7).

- In C++, the `^` symbol represents the bitwise XOR operator, not exponentiation. For exponentiation, use `pow(base, exponent)` from the `<cmath>` library or implement a custom integer exponentiation function. However, C++ supports scientific notation like `1e9` to represent 10^9 directly.


# Why Use Modulo 1e9 + 7 Before Returning the Answer

**Preventing Overflow**
- When performing `(n % m)` where n is positive, the result always falls within the range [0, m-1].
- This modulo operation constrains the output to fit within [0, m-1], preventing variable overflow.

**Why a Large Prime Number**
- Multiple numbers can produce the same remainder after modulo. For example, if m = 5 and n ranges from 1 to 100, the numbers 4, 9, 14, 19, etc. all yield 4 when computing `(n % m)`.
- With m = 5, the output range is only 0 to 4, causing many numbers to collide with identical values.
- To handle overflow while minimizing collisions, we need m to be:
  - As large as possible (to maximize the output range)
  - Within the variable's storage capacity
  - A prime number (primes provide balanced distribution across the output range [0, m-1])

**Why 10^9 + 7 Specifically**
- 10^9 + 7 is a large prime number that fits within a 4-byte signed integer variable.
- Returning answers modulo 10^9 + 7 constrains all results to [0, 10^9 + 6].
- This ensures that even exponentially growing answers, which would otherwise overflow, remain within the integer variable's range.


# Rerferences Cited:

[GeeksForGeeks: Modulo 10^9+7 (1000000007)](https://www.geeksforgeeks.org/dsa/modulo-1097-1000000007/)