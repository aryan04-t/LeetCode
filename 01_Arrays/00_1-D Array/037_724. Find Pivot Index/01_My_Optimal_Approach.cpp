// LeetCode (724. Find Pivot Index): 
// https://leetcode.com/problems/find-pivot-index/ 


#include<vector> 
using namespace std; 


class Solution {
public: 

    int pivotIndex(vector<int>& nums) {
        
        int sum = 0;
        for(int val : nums) sum += val; 

        int leftSum = 0;
        int rightSum = sum; 
        int n = nums.size(); 

        for(int i=0; i < n; i++){
            rightSum -= nums[i]; 
            if(leftSum == rightSum) return i; 
            leftSum += nums[i]; 
        }

        return -1; 
    }
};


// T.C. = O(n) + O(n) = O(2n) = O(n) 
// S.C. = O(1) 

// Here, n = the total number of elements which are present inside the input vector named "nums" 