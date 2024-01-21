// LeetCode (217. Contains Duplicate): 
// https://leetcode.com/problems/contains-duplicate/ 


#include<vector>
using namespace std;


class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        int n = nums.size();

        for(int i=0; i < n-1; i++){
            for(int j=i+1; j < n; j++){
                if(nums[i] == nums[j]) return true;
            }
        }

        return false;
    }
};


// T.C. = O(n^2) 
// S.C. = O(1) 

// Here, n = total number of elements which are present inside the input vector named "nums" 


// TLE - 70/75 testcases passed 