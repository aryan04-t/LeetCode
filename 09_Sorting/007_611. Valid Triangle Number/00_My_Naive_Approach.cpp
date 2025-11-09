// LeetCode (611. Valid Triangle Number): 
// https://leetcode.com/problems/valid-triangle-number 


// This gives TLE (Time Limit Exceeded) Error due to high Time Complexity 


#include<vector>
using namespace std;


class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        
        int n = nums.size();
        int validTriangles = 0;

        for (int i=0; i < n-2; i++) {
            for (int j=i+1; j < n-1; j++) {
                for (int k=j+1; k < n; k++) {
                    if (
                        (nums[i] + nums[j] > nums[k]) &&
                        (nums[j] + nums[k] > nums[i]) &&
                        (nums[k] + nums[i] > nums[j])
                    ) {
                        validTriangles++;
                    }
                }
            }
        }

        return validTriangles;
    }
};


/*
  # This Approach Relies on The Property: 
    - if a, b and c are 3 lines 
    - And if ((a + b > c) && (b + c > a) && (c + a > b)) then a, b and c can form a valid triangle 
*/


// T.C. = O(n^3) 
// S.C. = O(1) 

// Here, n = the length of input vector named "nums" 