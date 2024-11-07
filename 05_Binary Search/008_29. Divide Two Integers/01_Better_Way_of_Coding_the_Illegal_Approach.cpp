// 29. Divide Two Integers (29. Divide Two Integers): 
// https://leetcode.com/problems/divide-two-integers/ 

 
#include<limits.h> 
using namespace std; 


class Solution {
public:
    int divide(int dividend, int divisor) {
        
        if(dividend == INT_MIN && divisor == -1){
            return INT_MAX;
        }

        return dividend/divisor;
    }
};


// T.C. = O(1) 
// S.C. = O(1) 

// Practically this approach don't really have O(1) time complexity, but we consider time complexity of basic operators as O(1). 
// Specifically when we operate with a fixed width of 64 or 128-bit at most, we can safely assume the time complexity as O(1), but still the time complexity is not really O(1), it is considered to be O(1) just because the width is limited because we're dealing with fixed width datatypes which have just considerable lengths 
// If we go on arbitrary precision level, we will understand that operators are not really O(1), but for enviornments like these where we're just working with fixed precision numbers, we can consider the time complexity to be O(1) 