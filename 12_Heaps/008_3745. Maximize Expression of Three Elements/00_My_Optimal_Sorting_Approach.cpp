// LeetCode (3745. Maximize Expression of Three Elements): 
// https://leetcode.com/problems/maximize-expression-of-three-elements 


#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
    int maximizeExpressionOfThree(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());

        int n = nums.size();

        return (nums[n-1] + nums[n-2] - nums[0]);
    }
};


// T.C. = O(n*log(n)) 
// S.C. = O(log(n)) 

// Here, n = the length of input vector named "nums" 