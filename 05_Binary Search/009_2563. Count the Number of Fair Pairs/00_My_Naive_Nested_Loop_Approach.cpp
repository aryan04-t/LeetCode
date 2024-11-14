// LeetCode (2563. Count the Number of Fair Pairs): 
// https://leetcode.com/problems/count-the-number-of-fair-pairs 


// This appraoch gives TLE (As Expected) 


#include<vector> 
using namespace std; 


class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        
        int n = nums.size(); 
        long long count = 0; 

        for (int i=0; i < n-1; i++) {
            for (int j=i+1; j < n; j++) {
                int num = nums[i] + nums[j]; 
                if (num >= lower && num <= upper) count++; 
            }
        }

        return count; 
    }
};


// T.C. = O((n*(n-1))/2) = O(n^2) 
// S.C. = O(1) 

// Here, n = total number of elements which are present inside the input vector named "nums" 