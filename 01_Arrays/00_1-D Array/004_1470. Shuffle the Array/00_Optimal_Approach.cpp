// LeetCode (1470. Shuffle the Array): 
// https://leetcode.com/problems/shuffle-the-array/ 


#include<vector>
using namespace std;


class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        
        vector<int> ans;

        for(int i=0, j=n; i < n; i++, j++){
            ans.push_back(nums[i]);
            ans.push_back(nums[j]);
        }

        return ans;
    }
};


// T.C. = O(n/2) = O(n) 
// S.C. = O(n) 

// Here, n = number of elements which are present inside the input vector named "nums" 