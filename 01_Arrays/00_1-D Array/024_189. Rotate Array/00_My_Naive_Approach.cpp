// LeetCode (189. Rotate Array): 
// https://leetcode.com/problems/rotate-array/ 


#include<vector> 
using namespace std; 


class Solution { 
public: 

    void rotate(vector<int>& nums, int k) {
        
        int n = nums.size();

        while(k--){
            
            int temp = nums[n-1];

            for(int i=n-2; i >= 0; i--){
                nums[i+1] = nums[i]; 
            }
            
            nums[0] = temp;

        }

    }

};


// T.C. = O(k*n) 
// S.C. = O(1) 

// Here, n = total number of elements which are present inside the input vector named "nums", and k = the value of input variable named "k" 