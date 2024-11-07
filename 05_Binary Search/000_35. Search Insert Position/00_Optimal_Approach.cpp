// LeetCode (35. Search Insert Position): 
// https://leetcode.com/problems/search-insert-position/description/ 


#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        int n = nums.size();
        
        int start = 0;
        int end = n-1;
        int mid;

        while(start <= end){

            mid = start + (end - start)/2;    

            if(nums[mid] == target){
                return mid;
            }
            else if(target > nums[mid]){
                start = mid + 1;
            }
            else if(target < nums[mid]){
                end = mid - 1;
            }
        }

        return start;
    }
};


// T.C. = O(log(n) to the base 2) 
// S.C. = O(1) 

// Here, n = number of elements present inside the input vector named "nums" 