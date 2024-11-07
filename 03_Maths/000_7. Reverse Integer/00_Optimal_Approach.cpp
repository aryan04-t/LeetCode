// LeetCode (7. Reverse Integer): 
// https://leetcode.com/problems/reverse-integer/ 


#include<limits.h>


class Solution {
public:
    int reverse(int x) {
        
        int digit = 0; 
        int revNum = 0;
        
        while(x){
            
            if(revNum < INT_MIN/10 || revNum > INT_MAX/10) return 0;

            digit = x % 10;
            revNum = revNum * 10 + digit;
            x /= 10;
        
        }

        return revNum;
    }
};


// T.C.: O(log(x) to the base 10) 
// S.C.: O(1) 

// Here, x = the input number 