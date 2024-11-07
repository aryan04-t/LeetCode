// LeetCode (2134. Minimum Swaps to Group All 1's Together II): 
// https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together-ii/ 


#include<vector> 
#include<limits.h> 
#include<algorithm> 
using namespace std;  


class Solution {
public:
    int minSwaps(vector<int>& nums) {
        
        int onesCount = 0;
        for(int val : nums){
            if(val == 1) onesCount++; 
        }
        
        int totalSwaps = 0;
        int ans = INT_MAX;

        for(int i=0; i < onesCount; i++){
            if(nums[i] == 0) totalSwaps++; 
        }
        
        ans = min(ans, totalSwaps); 
        if(ans == 0) return 0; 

        int n = nums.size(); 

        for(int i=onesCount; i < n + onesCount; i++){
            
            int toBeProcessedIndex = i % n;
            if(nums[toBeProcessedIndex] == 0) totalSwaps++; 
            
            int toBeRemovedIndex = toBeProcessedIndex - onesCount; 
            if(toBeRemovedIndex < 0) toBeRemovedIndex += n; 
            if(nums[toBeRemovedIndex] == 0) totalSwaps--; 
            
            ans = min(ans, totalSwaps); 

            if(ans == 0) return 0; 
        }

        return ans; 
    }
};


// T.C. = O(n) 
// S.C. = O(1) 

// Here, n = the length of input array named nums, and m = the total number of ones which are present inside the nums array, in worst case m == n 