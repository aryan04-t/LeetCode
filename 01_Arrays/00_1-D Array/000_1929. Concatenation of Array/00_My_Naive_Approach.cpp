// LeetCode (1929. Concatenation of Array): 
// https://leetcode.com/problems/concatenation-of-array/


#include<vector>
using namespace std;


class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> ans(2*n);        // t.c = O(2n), s.c. = O(2n) 

        for(int i = 0; i < n; i++){
            ans[i] = nums[i];
            ans[i+n] = nums[i];
        }

        // for loop has t.c. O(n) 

        return ans;
    }
};


// T.C. = O(2n) + O(n) = O(3n) = O(n) 
// S.C. = O(n) 

// Here, n = number of elements present in input vector named "nums" 