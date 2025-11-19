// LeetCode (2154. Keep Multiplying Found Values by Two): 
// https://leetcode.com/problems/keep-multiplying-found-values-by-two/ 


#include<vector> 
#include<unordered_set> 
using namespace std; 


class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        
        unordered_set<int> st(nums.begin(), nums.end());
        
        for (int val : nums) {
            if (st.count(original)) original *= 2;
            else break;
        }

        return original;
    }
};


// T.C. = O(n) + O(n) = O(2n) = O(n) 
// S.C. = O(n) 

// Here, n = the length of input vector named "nums" 