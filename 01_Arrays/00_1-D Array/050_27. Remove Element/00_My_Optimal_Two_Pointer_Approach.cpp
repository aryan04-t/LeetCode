// LeetCode (27. Remove Element): 
// https://leetcode.com/problems/remove-element/ 


#include<vector> 
using namespace std; 


class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        int n = nums.size(); 
        int i=0, j=0;
        
        while(i < n){
            if(nums[i] == val){
                i++; 
                continue; 
            }
            nums[j] = nums[i];
            i++; 
            j++; 
        }

        return j; 
    }
};


// T.C. = O(n) 
// S.C. = O(1) 

// Here, n = the total number of integers which are present inside the input vector named "nums" 