// LeetCode (509. Fibonacci Number): 
// https://leetcode.com/problems/fibonacci-number/ 


class Solution {
public:

    int fibRecursive(int n){

        if(n == 0 || n == 1) return n;

        return fibRecursive(n-1) + fibRecursive(n-2); 

    }

    int fib(int n) {
        
        return fibRecursive(n);

    }
};


// T.C. = O(2^n) 

// S.C. = O(n) -> (This space complexity is caused due to the function call stack) 

// Space complexity is O(n) because the depth of the recursion tree is proportional to the input "n". 


// Here, n = the value of input variable named "n" 