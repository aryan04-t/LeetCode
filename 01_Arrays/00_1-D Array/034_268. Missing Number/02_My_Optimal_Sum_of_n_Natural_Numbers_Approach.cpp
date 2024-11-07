// LeetCode (268. Missing Number): 
// https://leetcode.com/problems/missing-number/ 


#include<vector> 
using namespace std; 


class Solution {
public:
    int missingNumber(vector<int>& nums) {

        int n = nums.size(); 
        int idealSum = (n * (n+1)) / 2; 

        int currSum = 0;
        for(int val : nums) currSum += val; 
        
        return idealSum - currSum; 
    }
};


// T.C. = O(n) 
// S.C. = O(1) 

// Here, n = the total number of values which are present inside the input vector "nums" 