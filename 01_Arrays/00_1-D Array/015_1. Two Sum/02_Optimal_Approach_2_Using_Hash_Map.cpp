// LeetCode (1. Two Sum): 
// https://leetcode.com/problems/two-sum/ 


#include<vector> 
#include<unordered_map> 
using namespace std; 


class Solution {
public:

    vector<int> twoSum(vector<int>& nums, int target) {
        
        int n = nums.size();
        vector<int> ans;

        unordered_map<int, int> mp;

        int complement;
        
        for(int i=0; i < n; i++){

            complement = target - nums[i]; 
        
            if(mp.count(complement)){
                ans.push_back(i);
                ans.push_back(mp[complement]);
                return ans;
            }

            mp[nums[i]] = i;
        }

        return ans;
    }
};


// T.C. = O(n) 
// S.C. = O(n) 

// Here, n = total number of elements which are present inside the input vector named "nums" 