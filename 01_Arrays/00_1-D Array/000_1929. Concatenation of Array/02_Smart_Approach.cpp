// LeetCode (1929. Concatenation of Array): 
// https://leetcode.com/problems/concatenation-of-array/


#include<vector>
using namespace std;


class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        
        int n = nums.size();

        for(int i=0; i < n; i++){
            nums.push_back(nums[i]);
        }

        return nums;
    }
};


// T.C. = O(n) 
// S.C. = O(1) 