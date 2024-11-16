// LeetCode (3254. Find the Power of K-Size Subarrays I): 
// https://leetcode.com/problems/find-the-power-of-k-size-subarrays-i 


#include<vector> 
using namespace std;


class Solution {
public:

    vector<int> resultsArray (vector<int>& nums, int k) {
        
        int n = nums.size(); 
        if (n == 1) return {nums[0]}; 
        if (k == 1) return nums; 

        vector<int> result(n - k + 1, 0); 

        int index = 0; 

        for (int i=0; i < n-k+1; i++) {
            bool isConsAscSorted = true; 
            for (int j=i+1; j < i+k; j++) {
                if ((nums[j] <= nums[j-1]) || (nums[j] != nums[j-1]+1)) {
                    isConsAscSorted = false; 
                    break; 
                }
            }
            result[index++] = (isConsAscSorted) ? nums[i+k-1] : -1; 
        }

        return result; 
    }
}; 


// T.C. = O((n-k+1)*(k-1)) = O(n*k - k^2 + k - n + k - 1) = O(n*k) 
// S.C. = O(1) 

// Here, n = the total number of elements which were present inside input vector named "nums" and k = the value of input variable k 