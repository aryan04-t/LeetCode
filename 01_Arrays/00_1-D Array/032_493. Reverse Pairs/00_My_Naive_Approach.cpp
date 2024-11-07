// LeetCode (493. Reverse Pairs): 
// https://leetcode.com/problems/reverse-pairs/ 


#include<vector>
using namespace std; 


// This code gives TLE 

class Solution {
public:

    int reversePairs(vector<int>& nums) {

        int n = nums.size(); 
        int count = 0; 

        for(int i=0; i < n-1; i++){
            for(int j = i+1; j < n; j++){
                if((long long)nums[i] > 2*(long long)nums[j]) count++; 
            }
        }

        return count; 
    }
};


// T.C. = O((n*(n-1))/2) = O(n^2) 
// S.C. = O(1) 

// Here, n = the total number of values which are present inside the input vector named "nums" 