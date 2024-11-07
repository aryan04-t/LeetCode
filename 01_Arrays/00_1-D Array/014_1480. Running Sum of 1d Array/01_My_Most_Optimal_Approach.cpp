// LeetCode (1480. Running Sum of 1d Array): 
// https://leetcode.com/problems/running-sum-of-1d-array/ 


#include<vector>
using namespace std;


class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        
        int n = nums.size();

        for(int i=1; i < n; i++){
            nums[i] = nums[i] + nums[i-1];
        }

        return nums; 
    
    }
};


// T.C. = O(n) 
// S.C. = O(1) 

// Here, n = number of elements which are present inside the input vector named "nums" 