// LeetCode (509. Fibonacci Number): 
// https://leetcode.com/problems/fibonacci-number/ 


// Most Optimal Approach (Constant Space and Linear Time Complexity): 


class Solution {
public:

    int fibRecursive(int n){

        if(n == 0 || n == 1) return n;

        int prev2 = 0;
        int prev1 = 1;
        int curr;

        for(int i=2; i <= n; i++){
            curr = prev1 + prev2; 
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;

    }

    int fib(int n) {
        
        return fibRecursive(n); 

    }
};


// T.C. = O(n) 
// S.C. = O(1) 

// Here, n = the value of input variable named "n" 