// LeetCode (26. Remove Duplicates from Sorted Array): 
// https://leetcode.com/problems/remove-duplicates-from-sorted-array/ 


#include<vector>
using namespace std;


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int n = nums.size();
        int validIndex = 1;

        for(int i=1; i < n; i++){
            if(nums[i] != nums[i-1]){ 
                nums[validIndex++] = nums[i];
            }
        }

        return validIndex;

    }
};


// T.C. = O(n) 
// S.C. = O(1) 

// Here, n = total number of elements which are present inside the input vector named "nums" 