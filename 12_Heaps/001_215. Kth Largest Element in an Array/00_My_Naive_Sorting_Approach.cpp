// LeetCode (215. Kth Largest Element in an Array): 
// https://leetcode.com/problems/kth-largest-element-in-an-array/ 


#include<vector> 
#include<algorithm> 
using namespace std; 


class Solution {
public:

    int findKthLargest(vector<int>& nums, int k) {

        int n = nums.size(); 
        sort(nums.begin(), nums.end());

        return nums[n-k]; 
    }
};


// T.C. = O(n * log(n)) 
// S.C. = O(log(n)) 

// Here, n = the total number of elements which are present inside the given input vector named "nums" 