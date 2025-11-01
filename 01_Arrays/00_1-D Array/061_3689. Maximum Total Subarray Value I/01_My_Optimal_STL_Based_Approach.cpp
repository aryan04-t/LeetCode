// LeetCode (3689. Maximum Total Subarray Value I): 
// https://leetcode.com/problems/maximum-total-subarray-value-i 


#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        
        vector<int>::iterator miniIt = min_element(nums.begin(), nums.end()); 
        vector<int>::iterator maxiIt = max_element(nums.begin(), nums.end()); 

        long long mini = *miniIt;
        long long maxi = *maxiIt;

        long long res = (long long)(maxi - mini) * (long long)(k);

        return res;
    }
};


// T.C. = O(n) + O(n) = O(2n) = O(n) 
// S.C. = O(1) 

// Here, n = the length of input vector named "nums"