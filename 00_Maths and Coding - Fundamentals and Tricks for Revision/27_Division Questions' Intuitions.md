# Division Questions' Intuitions

## Core Operators
- **`/` (Division)**: Returns quotient
- **`%` (Modulo)**: Returns remainder
- Both operators are complementary parts of the complete division process

## Fundamental Formula
```
dividend = divisor × quotient + remainder
```
This equation captures the complete picture of division, not just the quotient.

## Integer Division
When dividing integers, we get two distinct outputs:
- **Quotient**: How many times divisor fits into dividend
- **Remainder**: What's left over after complete groups

Example: `17 ÷ 5 = 3 remainder 2` → `17 = 5 × 3 + 2`

## Decimal Division: Recursive Remainder Processing
Decimal output represents continued division of the remainder:

**Process:**
1. Perform integer division to get quotient and remainder
2. Multiply remainder by 10 (shift decimal place)
3. Divide this new value by divisor
4. Repeat until remainder becomes 0 (terminating) or pattern repeats (repeating)

**Example: 17 ÷ 5 = 3.4**
- Integer part: `17 ÷ 5 = 3 remainder 2`
- Decimal part: `2 × 10 = 20`, then `20 ÷ 5 = 4 remainder 0`
- Result: `3.4` (terminating decimal)

**Example: 10 ÷ 3 = 3.333...**
- Integer part: `10 ÷ 3 = 3 remainder 1`
- First decimal: `1 × 10 = 10`, then `10 ÷ 3 = 3 remainder 1`
- Second decimal: `1 × 10 = 10`, then `10 ÷ 3 = 3 remainder 1`
- Pattern repeats infinitely (non-terminating decimal)

## Key Insight
The decimal component isn't a separate entity—it's the continuation of the same division algorithm applied recursively to scaled remainders. Division either terminates (remainder = 0) or cycles (repeating pattern) based on the relationship between dividend and divisor.

## Problem-Solving Approach
When encountering division-related questions, consider which aspect the problem targets:
- **Modular arithmetic**: Focus on remainder patterns and cyclic behavior
- **Quotient analysis**: Examine how many complete groups fit
- **Decimal places**: Track recursive remainder processing and termination
- **Division formula**: Apply `dividend = divisor × quotient + remainder` for algebraic solutions

- - - 

## Reference Questions with Divison Intuitions Requirement:

3381. Maximum Subarray Sum With Length Divisible by K - [Link](https://leetcode.com/problems/maximum-subarray-sum-with-length-divisible-by-k)

166. Fraction to Recurring Decimal - [Link](https://leetcode.com/problems/fraction-to-recurring-decimal)

1590. Make Sum Divisible by P - [Link](https://leetcode.com/problems/make-sum-divisible-by-p)