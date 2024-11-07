// LeetCode (9. Palindrome Number): 
// https://leetcode.com/problems/palindrome-number/ 


// In this Approach we're reversing the whole number 


#include<limits.h> 
using namespace std; 


class Solution {
public:
    bool isPalindrome(int x) {
        
        if(x < 0) return false;

        int temp = x;
        int digit;
        int revNum = 0; 

        while(temp){
            
            if(revNum > INT_MAX/10 || revNum < INT_MIN/10) return false;

            digit = temp % 10;
            revNum = (revNum * 10) + digit;
            temp /= 10;
        }

        if(revNum == x) return true;

        return false;
    }
};


// T.C. = O(log(n) to the base 10) 
// S.C. = O(1) 

// Here, n = the value of input number named "x" 