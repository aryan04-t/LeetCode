// LeetCode (2154. Keep Multiplying Found Values by Two): 
// https://leetcode.com/problems/keep-multiplying-found-values-by-two/ 


#include<vector> 
#include<algorithm> 
using namespace std; 


class Solution {
public:

    int isPresent(vector<int> &nums, int target){

        int n = nums.size();
        int start = 0; 
        int end = n-1; 

        while(start <= end){
            
            int mid = start + (end - start)/2; 
            
            if(nums[mid] == target) return mid; 
            else if(target > nums[mid]) start = mid + 1; 
            else if(target < nums[mid]) end = mid - 1;  
        }
        
        return -1; 
    }

    int findFinalValue(vector<int>& nums, int original) {

        sort(nums.begin(), nums.end()); 

        while(isPresent(nums, original) != -1){
            original *= 2; 
        }

        return original; 
    }
};


// T.C. = O(n * log(n)) + O(n * log(n)) = O(2 * n * log(n)) = O(n * log(n)) 
// S.C. = O(log(n)) 

// Here, n = the total number of elements which are present inside the input vector named "nums" 