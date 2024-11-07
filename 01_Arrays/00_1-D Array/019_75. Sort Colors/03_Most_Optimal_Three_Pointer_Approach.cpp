// LeetCode (75. Sort Colors): 
// https://leetcode.com/problems/sort-colors/ 


#include<vector> 
#include<utility> 
using namespace std; 


class Solution {
public:

    void sortColors(vector<int>& nums) {
        
        int low = 0;
        int mid = 0;
        int high = nums.size() - 1;

        while(mid <= high){

            if(nums[mid] == 0){
                swap(nums[mid], nums[low]);
                mid++;
                low++;
            }
            else if(nums[mid] == 1){
                mid++;
            }
            else{
                swap(nums[mid], nums[high]);
                high--;
            }

        }

    }
    
};


// T.C. = O(n) 
// S.C. = O(1) 

// Here, n = total number of elements which are present inside the input vector named "nums" 