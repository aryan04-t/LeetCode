// LeetCode (2154. Keep Multiplying Found Values by Two): 
// https://leetcode.com/problems/keep-multiplying-found-values-by-two/ 


#include<vector> 
using namespace std; 


class Solution {
public:

    bool isPresent(vector<int> &nums, int target){

        for(int val : nums){
            if(val == target) return true; 
        }
        
        return false; 
    }

    int findFinalValue(vector<int>& nums, int original) {

        while(isPresent(nums, original)){
            original *= 2; 
        }

        return original; 
    }
};


// T.C. = O(n^2) 
// S.C. = O(1) 

// Here, n = the total number of elements which are present inside the input vector named "nums" 