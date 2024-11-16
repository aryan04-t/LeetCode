// LeetCode (3254. Find the Power of K-Size Subarrays I): 
// https://leetcode.com/problems/find-the-power-of-k-size-subarrays-i 


// After getting the sliding window intuition I coded this approach in a raw manner first, so this code breaks DRY (Don't repeat yourself) principle of coding. There are few places where it can be optimized from DRY principle's perspectve, but this raw intuition code is easy to understand from my naive coder's perspective 


#include<vector> 
using namespace std;


class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        
        int n = nums.size(); 
        if (n == 1) return {nums[0]}; 
        if (k == 1) return nums; 

        vector<int> result(n - k + 1, 0); 

        int i=1, j=0;
        bool isConsAscSorted = true; 

        while (i < n) {
            if (i < k) {
                if ((nums[i] <= nums[i-1]) || (nums[i] != nums[i-1]+1)) {
                    isConsAscSorted = false; 
                    i = k-1; 
                }
                if (i == k-1) {
                    result[j++] = (isConsAscSorted) ? nums[i] : -1; 
                }
            }
            else {
                if (isConsAscSorted) {
                    if ((nums[i] <= nums[i-1]) || (nums[i] != nums[i-1]+1)) {
                        isConsAscSorted = false; 
                        result[j++] = -1; 
                    }
                    else {
                        result[j++] = nums[i]; 
                    }
                }
                else {
                    int tempI = i-k+2; 
                    isConsAscSorted = true; 
                    while (tempI <= i) {
                        if ((nums[tempI] <= nums[tempI-1]) || (nums[tempI] != nums[tempI-1]+1)) {
                            isConsAscSorted = false; 
                            tempI = i; 
                        }
                        if (tempI == i) result[j++] = (isConsAscSorted) ? nums[i] : -1; 
                        tempI++; 
                    }
                }
            }
            i++; 
        }

        return result; 
    }
};