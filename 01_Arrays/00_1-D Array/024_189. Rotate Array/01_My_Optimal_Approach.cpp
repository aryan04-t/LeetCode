// LeetCode (189. Rotate Array): 
// https://leetcode.com/problems/rotate-array/ 


#include<vector> 
using namespace std; 


class Solution {
public:

    void rotate(vector<int>& nums, int k) {
        
        int n = nums.size();

        k = k % n;

        vector<int> rotatedNums;

        for(int i=n-k; i < n; i++){
            rotatedNums.push_back(nums[i]); 
        }

        for(int i=0; i < n-k; i++){
            rotatedNums.push_back(nums[i]); 
        }

        for(int i=0; i < n; i++){
            nums[i] = rotatedNums[i];
        }

    }

};


// T.C. = O(k) + O(n-k) + O(n) = O(n) + O(n) = O(2n) = O(n) 
// S.C. = O(n) 

// Here, n = total number of elements which are present inside the input vector named "nums", and k = the updated value of input variable named "k" after performing the "k modulo n" operation 