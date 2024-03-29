// LeetCode (713. Subarray Product Less Than K): 
// https://leetcode.com/problems/subarray-product-less-than-k/ 


#include<vector> 
using namespace std; 


class Solution {
public:

    int numSubarrayProductLessThanK(vector<int>& nums, int k) {

        if(k == 0 || k == 1) return 0; 

        int n = nums.size(); 

        int left = 0;
        int right = 0; 
        int currProduct = 1; 
        int ans = 0;

        while(right < n){

            currProduct *= nums[right]; 

            while(left < n && currProduct >= k){
                currProduct /= nums[left];
                left++;
            }

            ans += (right - left + 1); 
            right++; 
        }

        return ans; 
    }
};


// T.C. = O(n) 
// S.C. = O(1) 

// Here, n = the total number of elements which are present inside the input vector named "nums" 