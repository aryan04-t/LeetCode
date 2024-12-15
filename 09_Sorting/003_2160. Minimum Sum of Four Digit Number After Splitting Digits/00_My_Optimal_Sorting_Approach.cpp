// LeetCode (2160. Minimum Sum of Four Digit Number After Splitting Digits): 
// https://leetcode.com/problems/minimum-sum-of-four-digit-number-after-splitting-digits 

#include<vector> 
#include<algorithm> 
using namespace std; 


class Solution {
public:

    int minimumSum(int num) {
        
        vector<int> digits(4, 0); 
        int i = 0; 

        while (num) {
            int digit = num % 10; 
            digits[i] = digit; 
            num /= 10; 
            i++; 
        }

        sort(digits.begin(), digits.end()); 

        int new1 = digits[0]*10 + digits[3]; 
        int new2 = digits[1]*10 + digits[2]; 

        return new1 + new2; 
    }
}; 


// T.C. = O(4) + O(4*(log(4) to the base 2)) + O(4) = O(1) 
// S.C. = O(4) + (log(4) to the base 2) = O(1) 