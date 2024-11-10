// LeetCode (3097. Shortest Subarray With OR at Least K II): 
// https://leetcode.com/problems/shortest-subarray-with-or-at-least-k-ii 


#include<limits.h> 
#include<vector> 
using namespace std; 


class Solution {

private: 
    int oredNum = 0; 
    vector<int> oredNumBits = vector<int>(32, 0); 

    void addBitsToOredNumBits (int givenNum) {
        int i = 31;
        while (givenNum) {
            int lsb = givenNum & 1; 
            if (lsb) oredNumBits[i]++; 
            givenNum >>= 1; 
            i--; 
        }
    }

    void removeBitsFromOredNumBits (int givenNum) {
        int i = 31; 
        while (givenNum) {
            int lsb = givenNum & 1; 
            if (lsb) oredNumBits[i]--; 
            givenNum >>= 1; 
            i--; 
        }

        int two = 1; 
        int newOredNum = 0; 
        for (int j=31; j >= 1; j--) {  
            if (oredNumBits[j]) newOredNum += two; 
            if (j != 1) two *= 2; 
        }

        oredNum = newOredNum; 
    }

public: 
    int minimumSubarrayLength(vector<int>& nums, int k) {
        
        if (k == 0) return 1; 

        int n = nums.size(); 
        int minSubArrLen = INT_MAX; 

        int j = 0; 
        for (int i = 0; i < n; i++) {

            oredNum |= nums[i]; 
            addBitsToOredNumBits(nums[i]); 

            while (oredNum >= k) {
                int currSubArrLen = i - j + 1; 
                if (currSubArrLen < minSubArrLen) {
                    minSubArrLen = currSubArrLen; 
                }
                removeBitsFromOredNumBits(nums[j]); 
                j++; 
            }

            if (minSubArrLen == 1) return 1; 
        }

        if (minSubArrLen == INT_MAX) return -1; 

        return minSubArrLen; 
    }
};


// T.C. = O(2n * O(32)) = O(n) 
// S.C. = O(32) = O(1) 

// Here, n = total number of elements which are present inside the input vector named nums 