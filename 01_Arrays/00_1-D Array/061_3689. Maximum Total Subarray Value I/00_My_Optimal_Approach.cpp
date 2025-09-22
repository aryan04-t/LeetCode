// LeetCode (3689. Maximum Total Subarray Value I): 
// https://leetcode.com/problems/maximum-total-subarray-value-i 


#include<vector>
#include<climits>
using namespace std;


class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long mini = INT_MAX;
        long long maxi = INT_MIN;
        for (int num : nums) {
            if (num > maxi) maxi = num;
            if (num < mini) mini = num;
        }
        long long res = (maxi - mini) * k;
        return res;
    }
};


// T.C. = O(n) 
// S.C. = O(1) 

// Here, n = the length of input vector called "nums"