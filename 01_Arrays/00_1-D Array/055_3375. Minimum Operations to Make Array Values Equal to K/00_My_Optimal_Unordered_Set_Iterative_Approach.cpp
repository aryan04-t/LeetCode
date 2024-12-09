// LeetCode (3375. Minimum Operations to Make Array Values Equal to K): 
// https://leetcode.com/problems/minimum-operations-to-make-array-values-equal-to-k 


#include<vector> 
#include<unordered_set> 
using namespace std; 


class Solution {
public:
    int minOperations(vector<int>& nums, int k) {

        int ans = 0;
        unordered_set<int> s; 
        
        for (int val : nums) {
            if (val < k) return -1; 
            else if (val > k) {
                if (s.find(val) == s.end()) {
                    ans++;
                    s.insert(val); 
                }
            }
        }

        return ans;
    }
};


// T.C. = O(n) 
// S.C. = O(n) 

// Here, n = the length of input vector named "nums"