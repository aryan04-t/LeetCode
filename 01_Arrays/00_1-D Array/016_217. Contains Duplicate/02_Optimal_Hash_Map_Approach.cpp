// LeetCode (217. Contains Duplicate): 
// https://leetcode.com/problems/contains-duplicate/ 


#include<vector>
#include<unordered_map>
using namespace std;


class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        int n = nums.size();
        unordered_map<int, int> mp;

        for(int i=0; i < n; i++){
            if(mp.count(nums[i])) return true; 
            mp[nums[i]]++; 
        }

        return false;
    }
};


// T.C. = O(n) 
// S.C. = O(n) 

// Here, n = total number of elements which are present inside the input vector named "nums" 