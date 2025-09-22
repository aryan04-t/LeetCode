// LeetCode (3689. Maximum Total Subarray Value I): 
// https://leetcode.com/problems/maximum-total-subarray-value-i 


// This solution has the best time and space complexity but in runtime the memory consumed in MBs is a lot as I am storing the mini and maxi in new variable, I can store the index at which they are present in "nums" vector and the solution will be better even in runtime memory consumption


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