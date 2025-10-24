// LeetCode (3719. Longest Balanced Subarray I) 
// https://leetcode.com/problems/longest-balanced-subarray-i 


#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;


class Solution {
public:
    int longestBalanced(vector<int>& nums) {

        int n = nums.size();
        int maxSubArrLen = 0;
        
        for (int i=0; i < n; i++) {
            
            unordered_set<int> even;
            unordered_set<int> odd;

            for (int j=i; j < n; j++) {
                
                int val = nums[j];
                
                if (val & 1) odd.insert(val);
                else even.insert(val);

                if (even.size() == odd.size()) {
                    int subArrLen = j - i + 1;
                    maxSubArrLen = max(subArrLen, maxSubArrLen);
                }
            }
        }

        return maxSubArrLen;
    }
};


// T.C = O((n*(n+1))/2) = O(n^2) 
// S.C. = O(n) 

// n = the length of input vector named "nums" 