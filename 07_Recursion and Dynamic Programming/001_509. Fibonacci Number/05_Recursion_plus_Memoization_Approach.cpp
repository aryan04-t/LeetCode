// LeetCode (509. Fibonacci Number): 
// https://leetcode.com/problems/fibonacci-number/ 


#include<vector>
using namespace std;


class Solution {
public:

    int fibRecursive(int n, vector<int> &dp){

        if(n == 0 || n == 1) return n;

        if(dp[n] != -1)  return dp[n];

        dp[n] = fibRecursive(n-1, dp) + fibRecursive(n-2, dp); 

        return dp[n];

    }

    int fib(int n) {
        
        vector<int> dp(n+1, -1); 
        return fibRecursive(n, dp); 

    }
};


// T.C. = O(2n-1) = O(n) 
// S.C. = "S.C. of DP array" + "Depth of Function Call Stack" = O(n+1) + O(n) = O(2n+1) = O(n) 

// Here, n = the value of input variable named "n" 