// LeetCode (3254. Find the Power of K-Size Subarrays I): 
// https://leetcode.com/problems/find-the-power-of-k-size-subarrays-i 


// I brought down t.c. of my sliding window approach to O(n), and this code might even loop scary and lengthy because question was really simple and it could be solved in way less loc (lines of code) I looked solutions tab after writing this approach, but honestly I love this approach of mine, as I have thought this through on my own completely, and I feel it is easy to understand, but I will dry run less loc O(n) approaches from solutions tab and I will uncomplicate my thinking process with time. 


#include<vector> 
using namespace std;


class Solution {
public:

    bool checkCurrElementIsConsAscSortedOrNot (vector<int> &nums, int i) {
        return (nums[i] == nums[i-1]+1) ? true : false; 
    }

    vector<int> resultsArray (vector<int>& nums, int k) {
        
        int n = nums.size(); 
        if (n == 1) return {nums[0]}; 
        if (k == 1) return nums; 

        vector<int> result(n - k + 1, 0); 

        int i=1, j=0, inSlidingWindowLastConsAscSortedIndex = 0;
        bool isConsAscSorted = true; 

        while (i < n) {
            if (i < k) {
                isConsAscSorted = checkCurrElementIsConsAscSortedOrNot(nums, i); 
                if (!isConsAscSorted) {
                    inSlidingWindowLastConsAscSortedIndex = i-1; 
                    i = k-1; 
                }
                if (i == k-1) {
                    result[j++] = (isConsAscSorted) ? nums[i] : -1; 
                }
            }
            else {
                if (isConsAscSorted) {
                    isConsAscSorted = checkCurrElementIsConsAscSortedOrNot(nums, i); 
                    if (!isConsAscSorted) inSlidingWindowLastConsAscSortedIndex = i-1; 
                    result[j++] = (isConsAscSorted) ? nums[i] : -1; 
                }
                else {
                    int subArrStartIndex = i-k+1;
                    int tempI = subArrStartIndex + 1; 
                    if (
                        (inSlidingWindowLastConsAscSortedIndex >= subArrStartIndex) 
                        && 
                        (inSlidingWindowLastConsAscSortedIndex <= i) 
                    ) {
                        result[j++] = -1; 
                        i++;
                        continue; 
                    }
                    isConsAscSorted = true; 
                    while (tempI <= i) {
                        isConsAscSorted = checkCurrElementIsConsAscSortedOrNot(nums, tempI); 
                        if (!isConsAscSorted) {
                            inSlidingWindowLastConsAscSortedIndex = tempI-1; 
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


// T.C. = O(2n) = O(n) 
// S.C. = O(1) 

// Here, n = the total number of elements which were present inside input vector named "nums" and k = the value of input variable k 