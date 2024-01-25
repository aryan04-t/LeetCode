// LeetCode (704. Binary Search): 
// https://leetcode.com/problems/binary-search/ 


#include<vector> 
using namespace std; 


class Solution {
public:

    int search(vector<int>& nums, int target) {
        
        int start = 0;
        int end = nums.size() - 1;
        int mid; 

        while(start <= end){
            
            mid = start + (end - start)/2;
            
            if(nums[mid] == target){
                return mid;
            }
            else if(target > nums[mid]){
                start = mid+1;
            }
            else{
                end = mid-1;
            }
        
        }

        return -1;

    }
};


// T.C. = log(n) to the base 2 
// S.C. = O(1) 

// Here, n = total number of elements which are present inside the input vector named "nums" 

// Note: Always remember that binary search can only be applied when the give data set is already sorted 