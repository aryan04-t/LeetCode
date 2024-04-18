// LeetCode (69. Sqrt(x)): 
// https://leetcode.com/problems/sqrtx/ 


class Solution {
public:

    int mySqrt(int x) {

        if(x == 0 || x == 1) return x; 

        int start = 1; 
        int end = x; 

        while(start <= end){
            
            long long mid = start + (end - start)/2; 
            
            if(mid * mid == x) return mid; 
            else if(mid * mid > x) end = mid - 1; 
            else if(mid * mid < x) start = mid + 1; 

        }

        return end; 
    }
};


// T.C. = O(log(n) to the base 2) 
// S.C. = O(1) 

// Here, n = the value of input variable named "x" 