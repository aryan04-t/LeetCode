// LeetCode (3254. Find the Power of K-Size Subarrays I): 
// https://leetcode.com/problems/find-the-power-of-k-size-subarrays-i 


#include<vector> 
using namespace std;


class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        
        int n = nums.size(); 
        if (n == 1) return {nums[0]}; 
        if (k == 1) return nums; 

        int index = 0; 
        vector<int> result(n-k+1, 0); 

        int consecCount = 1; 
        int i = 1, j = 0;

        while (i < n) {
            if (nums[i] == nums[i-1] + 1) consecCount++; 
            if (i >= k) {
                if (nums[j]+1 == nums[j+1]) consecCount--; 
                j++; 
            } 
            if (i >= k-1) result[index++] = (consecCount == k) ? nums[i] : -1; 
            i++; 
        }

        return result; 
    }
};


// T.C. = O(n) 
// S.C. = O(n) 

// Here, n = the total number of elements which were present inside input vector named "nums" and k = the value of input variable k 