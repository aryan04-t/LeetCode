// LeetCode (896. Monotonic Array): 
// https://leetcode.com/problems/monotonic-array/ 


#include<vector> 
using namespace std; 


class Solution {
public: 

    bool isMonotonic(vector<int>& nums) {
        
        int n = nums.size(); 

        if(n == 1) return true; 

        bool monoDec = true; 
        
        for(int j=0; j < n-1; j++){
            if(nums[j] < nums[j+1]){
                monoDec = false;
                break;
            }
        }

        if(monoDec){
            return true;
        }

        bool monoInc = true;

        for(int j=0; j < n-1; j++){
            if(nums[j] > nums[j+1]){
                monoInc = false;
            }
        }

        if(monoInc){
            return true;
        }

        return false;

    }

};


// T.C. = O(n) 
// S.C. = O(1) 

// Here, n = total number of elements which are present inside the input vector named "nums" 