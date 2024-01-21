// LeetCode (217. Contains Duplicate): 
// https://leetcode.com/problems/contains-duplicate/ 


#include<vector>
#include<unordered_set> 
using namespace std;


class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        int n = nums.size();
        unordered_set<int> newSet;

        for(int i=0; i < n; i++){
            if(newSet.count(nums[i])) return true; 
            newSet.insert(nums[i]); 
        }

        return false;
    }
};


// T.C. = O(n) 
// S.C. = O(n) 

// Here, n = total number of elements which are present inside the input vector named "nums" 