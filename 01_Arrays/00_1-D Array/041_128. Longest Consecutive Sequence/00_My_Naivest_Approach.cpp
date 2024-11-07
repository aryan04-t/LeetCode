// LeetCode (128. Longest Consecutive Sequence): 
// https://leetcode.com/problems/longest-consecutive-sequence/ 


#include<vector> 
using namespace std; 


class Solution {
public:

    bool isPresent(vector<int> &nums, int target){
        for(int val : nums){
            if(val == target) return true;
        }
        return false;
    }

    int longestConsecutive(vector<int>& nums) {

        int n = nums.size(); 
        int finalAns = 0; 

        for(int val : nums){
            int ans = 1; 
            while(isPresent(nums, val+1)){
                val++; 
                ans++; 
            }
            if(ans > finalAns) finalAns = ans;  
        }

        return finalAns; 
    }
};


// T.C. = O(n^3) 
// S.C. = O(1) 

// Here, n = the total number of elements which are present inside the input vector named "nums" 