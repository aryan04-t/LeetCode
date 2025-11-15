// LeetCode (1. Two Sum): 
// https://leetcode.com/problems/two-sum/ 


#include<vector> 
#include<unordered_map> 
using namespace std; 


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        int n = nums.size();
        unordered_map<int, int> numsIdxMap;

        for (int i=0; i < n; i++) {
            int val = nums[i];
            int complement = target - val;
            if (numsIdxMap.count(complement)) {
                int compIdx = numsIdxMap[complement];
                return { i, compIdx };
            }
            numsIdxMap[val] = i;
        }

        return {};
    }
};


// T.C. = O(n) 
// S.C. = O(n) 

// Here, n = the length of input vector named "nums"