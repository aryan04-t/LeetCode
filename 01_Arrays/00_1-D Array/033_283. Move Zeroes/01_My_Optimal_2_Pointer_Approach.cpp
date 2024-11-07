// LeetCode (283. Move Zeroes): 
// https://leetcode.com/problems/move-zeroes/ 


#include<vector> 
#include<utility> 
using namespace std; 


class Solution {
public:

    void moveZeroes(vector<int>& nums) {

        int n = nums.size(); 

        int i = 0;
        int j = 0; 

        while(i < n && j < n){
            if(i < j){
                swap(nums[i], nums[j]); 
            }
            else{
                j++;
            }
            while(i < n && nums[i] != 0) i++;
            while(j < n && nums[j] == 0) j++; 
        }

    }
}; 


// T.C. = O(n) 
// S.C. = O(1) 

// Here, n = the total number of values which are present inside the input vector named "nums" 