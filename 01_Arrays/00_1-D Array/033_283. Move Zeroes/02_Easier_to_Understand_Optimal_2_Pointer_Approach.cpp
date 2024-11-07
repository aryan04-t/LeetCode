// LeetCode (283. Move Zeroes): 
// https://leetcode.com/problems/move-zeroes/ 


#include<vector> 
#include<utility> 
using namespace std; 


class Solution {
public:

    void moveZeroes(vector<int>& nums) {

        int n = nums.size(); 

        for(int left=0, right=0; right < n; right++){
            if(nums[right] != 0){
                swap(nums[left], nums[right]);
                left++; 
            }
        }

    }
};


// T.C. = O(n) 
// S.C. = O(1) 

// Here, n = the total number of values which are present inside the input vector named "nums" 