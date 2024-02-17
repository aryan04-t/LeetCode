// LeetCode (26. Remove Duplicates from Sorted Array): 
// https://leetcode.com/problems/remove-duplicates-from-sorted-array/ 


#include<vector> 
using namespace std; 


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int n = nums.size(); 
        vector<int> ans; 

        int validNumIndex = 0;

        for(int i=1; i < n; i++){
            if(nums[i] != nums[i-1]){
                ans.push_back(nums[validNumIndex]);
                validNumIndex = i;
            }
        }

        ans.push_back(nums[validNumIndex]); 

        int ansSize = ans.size();

        for(int i=0; i < ansSize; i++){
            nums[i] = ans[i]; 
        } 

        return ansSize;

    }
};


// T.C. = O(n) + O(m) = O(n) 
// S.C. = O(m) 

// Here, n = total number of elements which are present inside the input vector named "nums", and m = total number of unique elements which are present inside the input vector named "nums" 