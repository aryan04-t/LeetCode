// LeetCode (540. Single Element in a Sorted Array): 
// https://leetcode.com/problems/single-element-in-a-sorted-array/ 


#include<vector> 
using namespace std; 


class Solution {
public:

    int singleNonDuplicate(vector<int>& nums) {

        int ans = 0;
        for(int val : nums) ans ^= val; 

        return ans; 
    }
};


// T.C. = O(n) 
// S.C. = O(1) 

// Here, n = the total number of elements which are present inside the input vector named "nums" 