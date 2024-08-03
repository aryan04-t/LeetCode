// LeetCode (2134. Minimum Swaps to Group All 1's Together II): 
// https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together-ii/ 


// This approach of mine gives TLE 


#include<string> 
#include<vector> 
#include<algorithm> 
using namespace std; 


class Solution {
public:
    int minSwaps(vector<int>& nums) {
        
        int onesCount = 0;
        for(int val : nums){
            if(val == 1) onesCount++; 
        }
        
        int ans = INT_MAX;

        int n = nums.size(); 
        for(int i=0; i < n; i++){
            int totalSwaps = 0;
            for(int j=i; j < i+onesCount; j++){
                if(nums[j%n] == 0) totalSwaps++; 
            }
            ans = min(ans, totalSwaps); 
        }

        return ans; 
    }
};


// T.C. = O(n*m) = O(n^2) 
// S.C. = O(1) 

// Here, n = the length of input array named nums, and m = the total number of ones which are present inside the nums array, in worst case m == n 