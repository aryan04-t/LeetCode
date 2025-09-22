// LeetCode (3684. Maximize Sum of At Most K Distinct Elements): 
// https://leetcode.com/problems/maximize-sum-of-at-most-k-distinct-elements 


#include<vector>
#include<algorithm>
#include<functional>
using namespace std;


class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        
        sort(nums.begin(), nums.end(), greater<int>());
        
        vector<int> ans;

        int i = 0;
        int n = nums.size();

        while (k && i < n) {
            int num = nums[i];
            if (ans.empty() || ans.back() != num) {
                ans.push_back(num);
                k--;
            }
            i++;
        }

        return ans;
    }
};


// T.C. = O(n*log(n)) + O(n) = O(n*log(n)) 
// S.C. = O(log(n)) 

// Here, n = the length of input vector called "nums" 