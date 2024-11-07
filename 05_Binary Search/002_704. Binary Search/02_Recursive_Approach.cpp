// LeetCode (704. Binary Search): 
// https://leetcode.com/problems/binary-search/ 


#include<vector> 
using namespace std; 


class Solution {
public:

    int searchHelper(vector<int> &nums, int target, int start, int end){

        if(start > end){
            return -1;
        }

        int mid = start + (end - start)/2;
            
        if(nums[mid] == target){
            return mid;
        }
        else if(target > nums[mid]){
            return searchHelper(nums, target, mid+1, end);
        }
        else{
            return searchHelper(nums, target, start, mid-1);
        }
        
    }

    int search(vector<int> &nums, int target) {
        
        int start = 0;
        int end = nums.size() - 1;

        return searchHelper(nums, target, start, end);

    }
};


// T.C. = log(n) to the base 2 
// S.C. = log(n) to the base 2 -> This space complexity is caused due to function call stack 

// Here, n = total number of elements which are present inside the input vector named "nums" 

// Note: Always remember that binary search can only be applied when the give data set is already sorted 