// LeetCode (334. Increasing Triplet Subsequence): 
// https://leetcode.com/problems/increasing-triplet-subsequence/ 


#include<vector> 
using namespace std; 


class Solution {
public:

    bool increasingTriplet(vector<int>& nums) {

        int n = nums.size();

        for(int i=0; i < n-2; i++){
            for(int j=i+1; j < n-1; j++){
                for(int k=j+1; k < n; k++){
                    if(nums[i] < nums[j] && nums[j] < nums[k]){
                        return true;
                    }
                }
            }
        }
    
        return false;

    }

};


// T.C. = O( ((n-2) * (n-1) * n) / 6 ) = O(n^3) 
// S.C. = O(1) 

// Here, n = the total number of elements which are present inside the input vector named "nums" 