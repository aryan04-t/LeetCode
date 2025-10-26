// LeetCode (3718. Smallest Missing Multiple of K) 
// https://leetcode.com/problems/smallest-missing-multiple-of-k 


#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {

        int n = nums.size();
        int kMultiple = k;
        
        while (true) {

            /*
            // Self implemented linear-search approach

            bool found = false;
            for (int i=0; i < n; i++) {
                if (nums[i] == kMultiple) {
                    found = true;
                    break;
                }
            }
            if (!found) return kMultiple;
            */

            // Stl implemented linear search approach  
            if (find(nums.begin(), nums.end(), kMultiple) == nums.end()) {
                return kMultiple;
            }
            
            kMultiple += k;
        }
    }
};


// T.C. = O(n^2) 
// S.C. = O(1) 

// Here, n = the length of input vector named "nums" 