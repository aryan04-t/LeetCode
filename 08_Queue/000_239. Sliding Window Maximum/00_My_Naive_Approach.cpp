// Leetcode (239. Sliding Window Maximum): 
// https://leetcode.com/problems/sliding-window-maximum/ 


#include<vector> 
using namespace std; 


class Solution {
public:

    vector<int> maxSlidingWindow(vector<int>& nums, int k){

        int n = nums.size();
        vector<int> ans; 

        int totalNumOfWindows = n - k + 1;
        int maxi; 

        for(int i=0; i < totalNumOfWindows; i++){
            
            maxi = INT_MIN;

            for(int j=i; j < i+k; j++){
                maxi = max(maxi, nums[j]); 
            } 

            ans.push_back(maxi);

        }

        return ans;

    }

}; 


// T.C. = O( (n-k+1) * (k) ) = O(n*k - k^2 + k) = O(n*k) 
// S.C. =  O(n-k+1) = O(n-k) 

// Here, n = total number of elements which are present inside the input vector named "nums", and k = value of input variable "k" 


// Time Limit Exceeded Error -> 37/51 testcases passed 