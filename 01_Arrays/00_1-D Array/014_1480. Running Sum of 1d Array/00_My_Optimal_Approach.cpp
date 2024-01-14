// LeetCode (1480. Running Sum of 1d Array): 
// https://leetcode.com/problems/running-sum-of-1d-array/ 


#include<vector>
using namespace std;


class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> ans;
        int sum = 0;

        for(int i=0; i < n; i++){
            sum += nums[i];
            ans.push_back(sum);
        }

        return ans; 
    
    }
};


// T.C. = O(n) 
// S.C. = O(n) 

// Here, n = number of elements which are present inside the input vector named "nums" 