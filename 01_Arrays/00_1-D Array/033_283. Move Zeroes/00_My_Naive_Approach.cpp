// LeetCode (283. Move Zeroes): 
// https://leetcode.com/problems/move-zeroes/ 


#include<vector> 
using namespace std; 


class Solution {
public:

    void moveZeroes(vector<int>& nums) {

        int n = nums.size(); 
        
        vector<int> ans; 
        int countZero = 0; 

        for(int i=0; i < n; i++){
            if(nums[i] != 0){
                ans.push_back(nums[i]); 
            }
            else{
                countZero++; 
            }
        }

        int m = ans.size(); 

        int i=0; 
        while(i < m) nums[i++] = ans[i]; 
        while(countZero--) nums[i++] = 0; 

    }
};


// T.C. = O(n) + O(n) = O(n) 
// S.C. = O(n) 

// Here, n = the total number of values which are present inside the input vector named "nums" 