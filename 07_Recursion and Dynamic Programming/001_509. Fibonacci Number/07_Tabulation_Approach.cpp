// LeetCode (509. Fibonacci Number): 
// https://leetcode.com/problems/fibonacci-number/ 


#include<vector>
using namespace std;


class Solution {
public:

    int fibRecursive(int n){

        if(n == 0 || n == 1) return n;

        vector<int> dp(n+1);
        dp[0] = 0;        
        dp[1] = 1;        
        
        for(int i=2; i <= n; i++){
            dp[i] = dp[i-1] + dp[i-2]; 
        }

        return dp[n];

    }

    int fib(int n) {
        
        return fibRecursive(n); 

    }
};


// T.C. = O(n) 
// S.C. = "S.C. of DP array" = O(n+1) = O(n) 

// Here, n = the value of input variable named "n" 