// LeetCode (334. Increasing Triplet Subsequence): 
// https://leetcode.com/problems/increasing-triplet-subsequence/ 


#include<vector> 
#include<limits.h> 
using namespace std; 


class Solution {
public:

    bool increasingTriplet(vector<int>& nums) {

        int n = nums.size(); 

        int firstSmaller = INT_MAX; 
        int secondSmaller = INT_MAX; 

        for(int i=0; i < n; i++){
            if(nums[i] <= firstSmaller){
                firstSmaller = nums[i]; 
            }
            else if(nums[i] <= secondSmaller){
                secondSmaller = nums[i]; 
            }
            else{
                return true; 
            }
        }

        return false;

    }
};


// T.C. = O(n) 
// S.C. = O(1) 

// Here, n = the total number of elements which are present inside the input vector named "nums" 