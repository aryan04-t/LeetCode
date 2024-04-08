// LeetCode (268. Missing Number): 
// https://leetcode.com/problems/missing-number/ 


#include<vector> 
using namespace std; 


class Solution {
public:
    int missingNumber(vector<int>& nums) {

        int n = nums.size(); 
        int ans = 0;

        for(int i=0; i < n; i++){
            ans ^= (i^nums[i]); 
        }

        return ans^n;
    }
};


// T.C. = O(n) 
// S.C. = O(1) 

// Here, n = the total number of values which are present inside the input vector "nums" 