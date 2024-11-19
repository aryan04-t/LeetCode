// LeetCode (2461. Maximum Sum of Distinct Subarrays With Length K): 
// https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k 


#include<vector> 
#include<unordered_map> 
using namespace std; 


class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        
        int n = nums.size(); 
        long long sum = 0, maxSum = 0; 
        unordered_map<int, int> mp; 

        int i = 0, j = 0; 
        
        while (i < n) {
            
            sum += nums[i]; 
            mp[nums[i]]++; 

            if (i >= k-1) {
                
                if (sum > maxSum && mp.size() == k) maxSum = sum; 
                
                sum -= nums[j]; 
                mp[nums[j]]--; 
                
                unordered_map<int, int>::iterator it = mp.find(nums[j]); 
                if (it->second == 0) mp.erase(it); 
                
                j++; 
            }

            i++; 
        }

        return maxSum; 
    }
};


// T.C. = O(n) 
// S.C. = O(k) 

// Here, n = the total number of elements which are present inside the input vector named nums 