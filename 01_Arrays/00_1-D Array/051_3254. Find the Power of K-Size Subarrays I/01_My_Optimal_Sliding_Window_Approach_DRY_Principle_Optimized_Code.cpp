// LeetCode (3254. Find the Power of K-Size Subarrays I): 
// https://leetcode.com/problems/find-the-power-of-k-size-subarrays-i 


#include<vector> 
using namespace std;


class Solution {
public:

    bool checkCurrElementIsConsAscSortedOrNot (vector<int> &nums, int i) {
        bool isConsAscSorted = true; 
        if ((nums[i] <= nums[i-1]) || (nums[i] != nums[i-1]+1)) {
            isConsAscSorted = false; 
        }
        return isConsAscSorted; 
    }

    vector<int> resultsArray (vector<int>& nums, int k) {
        
        int n = nums.size(); 
        if (n == 1) return {nums[0]}; 
        if (k == 1) return nums; 

        vector<int> result(n - k + 1, 0); 

        int i=1, j=0;
        bool isConsAscSorted = true; 

        while (i < n) {
            if (i < k) {
                isConsAscSorted = checkCurrElementIsConsAscSortedOrNot(nums, i); 
                if (!isConsAscSorted) i = k-1; 
                if (i == k-1) {
                    result[j++] = (isConsAscSorted) ? nums[i] : -1; 
                }
            }
            else {
                if (isConsAscSorted) {
                    isConsAscSorted = checkCurrElementIsConsAscSortedOrNot(nums, i); 
                    result[j++] = (isConsAscSorted) ? nums[i] : -1; 
                }
                else {
                    int tempI = i-k+2; 
                    isConsAscSorted = true; 
                    while (tempI <= i) {
                        isConsAscSorted = checkCurrElementIsConsAscSortedOrNot(nums, tempI); 
                        if (!isConsAscSorted) tempI = i; 
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