// LeetCode (33. Search in Rotated Sorted Array): 
// https://leetcode.com/problems/search-in-rotated-sorted-array/ 


#include<vector> 
using namespace std; 


class Solution {
public:

    int search(vector<int>& nums, int target) {

        int n = nums.size(); 

        int start = 0; 
        int end = n - 1;

        while(start <= end){

            int mid = start + (end - start)/2; 

            if(nums[mid] == target) return mid; 
            else if(nums[start] <= nums[mid]){
                if(target >= nums[start] && target < nums[mid]){
                    end = mid - 1;
                }
                else{
                    start = mid + 1; 
                }
            }
            else if(nums[start] > nums[mid]){
                if(target > nums[mid] && target <= nums[end]){
                    start = mid + 1; 
                }
                else{
                    end = mid - 1; 
                }
            }
        }
        
        return -1; 
    }
};


// T.C. = O(log(n)) 
// S.C. = O(1) 

// Here, n = the total number of elements which are present inside the input vector named "nums" 