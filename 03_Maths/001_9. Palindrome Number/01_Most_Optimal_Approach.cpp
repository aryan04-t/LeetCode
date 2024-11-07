// LeetCode (9. Palindrome Number): 
// https://leetcode.com/problems/palindrome-number/ 


// In this Approach we're reversing only the half number 


#include<limits.h> 
using namespace std; 


class Solution {
public:
    bool isPalindrome(int x) {
        
        if(x < 0 || (x != 0 && (x % 10 == 0))) return false;

        int digit;
        int revNum = 0; 

        while(x > revNum){
            
            if(revNum > INT_MAX/10 || revNum < INT_MIN/10) return false;

            digit = x % 10;
            revNum = (revNum * 10) + digit;
            x /= 10;
        }

        return (x == revNum) || (x == revNum/10); 
    
    }
};


// T.C. = O((log(n) to the base 10) / 2) = O(log(n) to the base 10) 
// S.C. = O(1) 

// Here, n = the value of input number named "x" 