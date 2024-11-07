// LeetCode (2441. Largest Positive Integer That Exists With Its Negative): 
// https://leetcode.com/problems/largest-positive-integer-that-exists-with-its-negative/ 


#include<vector> 
using namespace std; 


class Solution {
public:

    int findMaxK(vector<int>& nums) {

        int n = nums.size(); 
        int ans = -1; 

        for(int i=0; i < n; i++){
            if(nums[i] > 0){
                for(int j=0; j < n; j++){
                    if(j == i) continue; 
                    else{
                        if(-nums[i] == nums[j]){
                            if(nums[i] > ans){
                                ans = nums[i]; 
                            }
                        }
                    }
                }
            }
        }

        return ans; 
    }
};


// T.C. = O(n^2) 
// S.C. = O(1) 

// Here, n = the total number of elements which are present inside the input vector named "nums" 