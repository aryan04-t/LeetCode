// LeetCode (713. Subarray Product Less Than K): 
// https://leetcode.com/problems/subarray-product-less-than-k/ 


#include<vector> 
using namespace std; 


class Solution {
public:

    int numSubarrayProductLessThanK(vector<int>& nums, int k) {

        int n = nums.size(); 
        int ans = 0;

        for(int i=0; i < n; i++){
            
            int currProduct = 1; 
            
            for(int j=i; j < n; j++){
                
                currProduct *= nums[j]; 
                if(currProduct >= k) break; 
                ans++; 
            
            }
        }

        return ans; 

    }
}; 


// T.C. = O( (n * (n+1)) / 2 ) = O(n^2) 
// S.C. = O(1) 

// Here, n = the total number of elements which are present inside the input vector named "nums" 
