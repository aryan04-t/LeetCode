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

        for(int i=0; i < n; i++){
            mp[nums[i]] = i;
        }

        int complement;
        
        for(int i=0; i < n; i++){

            complement = target - nums[i]; 
        
            if(mp.count(complement) && mp[complement] != i){
                ans.push_back(i);
                ans.push_back(mp[complement]);
                return ans;
            }
        
        }

        return ans;
    }
};


// T.C. = O(n) + O(n) = O(2n) = O(n) 
// S.C. = O(n) 

// Here, n = total number of elements which are present inside the input vector named "nums" 