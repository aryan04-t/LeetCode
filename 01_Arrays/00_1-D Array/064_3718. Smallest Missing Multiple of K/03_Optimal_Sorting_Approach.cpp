// LeetCode (3718. Smallest Missing Multiple of K) 
// https://leetcode.com/problems/smallest-missing-multiple-of-k 


#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:

    int missingMultiple(vector<int>& nums, int k) {
        
        sort(nums.begin(), nums.end());

        int missingMultiple = k;
        for (int val : nums) {
            if (missingMultiple == val) {
                missingMultiple += k;
            }
        }

        return missingMultiple;
    }
};


// T.C. = O(n*log(n)) + O(n) = = O(n*log(n)) 
// S.C. = O(log(n)) 

// Here, n = the length of input vector named "nums" 