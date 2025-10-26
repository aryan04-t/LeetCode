// LeetCode (3718. Smallest Missing Multiple of K) 
// https://leetcode.com/problems/smallest-missing-multiple-of-k 


#include<vector>
#include<unordered_set>
using namespace std;


class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {

        unordered_set<int> st;
        for (int val : nums) st.insert(val);
        
        // unordered_set<int> st(nums.begin(), nums.end());
        
        int missingMultiple = k;

        while (true) {
            if (st.find(missingMultiple) == st.end()) {
                return missingMultiple;
            }
            missingMultiple += k;
        }
    }
};


// T.C. = O(n) + O(n) = O(2n) = O(n) 
// S.C. = O(n) 

// Here, n = the length of input vector named "nums" 