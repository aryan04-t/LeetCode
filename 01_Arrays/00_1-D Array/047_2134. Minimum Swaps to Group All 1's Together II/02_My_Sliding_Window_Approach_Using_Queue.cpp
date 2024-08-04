// LeetCode (2134. Minimum Swaps to Group All 1's Together II): 
// https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together-ii/ 


#include<vector>
#include<queue> 
#include<algorithm> 
#include<limits.h> 
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

        queue<int> q; 
        for(int i=0; i < onesCount; i++){
            if(nums[i] == 0) totalSwaps++; 
            q.push(nums[i]); 
        }
        
        ans = min(ans, totalSwaps); 
        if(ans == 0) return 0; 

        int n = nums.size(); 

        for(int i=onesCount; i < n + onesCount; i++){
            
            int toBeRemovedElement = q.front(); 
            q.pop();
            if(toBeRemovedElement == 0) totalSwaps--; 

            int toBeProcessedIndex = i % n;
            if(nums[toBeProcessedIndex] == 0) totalSwaps++; 
            q.push(nums[toBeProcessedIndex]); 

            ans = min(ans, totalSwaps); 
            if(ans == 0) return 0; 
        }

        return ans; 
    }
};


// T.C. = O(n) 
// S.C. = O(n) 

// Here, n = the length of input array named nums, and m = the total number of ones which are present inside the nums array, in worst case m == n 