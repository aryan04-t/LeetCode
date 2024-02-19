// LeetCode (896. Monotonic Array): 
// https://leetcode.com/problems/monotonic-array/ 


#include<vector> 
using namespace std; 


class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        
        int n = nums.size();

        if(n == 1) return true;

        bool monoDec = false;
        bool monoInc = false;

        int i = 0;

        while( (i < n-1) && (nums[i] == nums[i+1]) ){
            i++;
        }

        if(i == n-1){
            return true;
        }

        if(nums[i] > nums[i+1]){
            monoDec = true; 
        }
        else{
            monoInc = true; 
        }

        if(monoDec){

            for(int j=i; j < n-1; j++){
                if(nums[j] < nums[j+1]){
                    return false;
                }
            }

        }
        else{

            for(int j=i; j < n-1; j++){
                if(nums[j] > nums[j+1]){
                    return false;
                }
            }

        }

        return true;

    }
};


// T.C. = O(n) 
// S.C. = O(1) 

// Here, n = total number of elements which are present inside the input vector named "nums" 