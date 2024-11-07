// LeetCode (136. Single Number): 
// https://leetcode.com/problems/single-number/ 


#include<vector> 
using namespace std; 


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int ans = 0; 
        for(int val : nums) ans ^= val; 
        
        return ans; 
    }
};


// T.C. = O(n) 
// S.C. = O(1) 

// Here, n = the total numbers of integers which are present inside the input vector "nums" 