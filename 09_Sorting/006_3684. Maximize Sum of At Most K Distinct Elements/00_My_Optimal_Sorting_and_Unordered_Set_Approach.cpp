// LeetCode (3684. Maximize Sum of At Most K Distinct Elements):
// https://leetcode.com/problems/maximize-sum-of-at-most-k-distinct-elements 


#include<vector>
#include<algorithm>
#include<unordered_set>
#include<functional>
using namespace std; 


class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        
        sort(nums.begin(), nums.end(), greater<int>());
        
        vector<int> ans;
        unordered_set<int> st;

        int n = nums.size();
        int i = 0;
        int numCount = 0;

        while (numCount < k && i < n) {
            int num = nums[i];
            if (st.find(num) != st.end()) {
                i++;
                continue;
            }
            st.insert(num);
            ans.push_back(num);
            numCount++, i++;
        }

        return ans;
    }
};


// T.C. = O(n*log(n)) + O(n) = O(n*log(n)) 
// S.C. = O(log(n)) + O(n) = O(n) 

// Here, n = the length of input vector called "nums" 