// LeetCode (3097. Shortest Subarray With OR at Least K II): 
// https://leetcode.com/problems/shortest-subarray-with-or-at-least-k-ii 


#include<limits.h> 
#include<vector> 
using namespace std; 


class Solution {
public: 
    int minimumSubarrayLength(vector<int>& nums, int k) {
        
        int n = nums.size(); 
        int minSubArrLen = INT_MAX; 

        for (int i=0; i < n; i++) {
            int oredNum = 0; 
            for (int j=i; j < n; j++) {
                oredNum |= nums[j]; 
                if (oredNum >= k) {
                    int subArrLen = j - i + 1; 
                    if (subArrLen < minSubArrLen) minSubArrLen = subArrLen;
                }
            }
        }

        if (minSubArrLen == INT_MAX) return -1; 

        return minSubArrLen; 
    }
}; 


// T.C. = O((n * (n+1)) / 2) = O(n^2) 
// S.C. = O(1) 

// Here, n = total number of elements which are present inside the input vector named nums 