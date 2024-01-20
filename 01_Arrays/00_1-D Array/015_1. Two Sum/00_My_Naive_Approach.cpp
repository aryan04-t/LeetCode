// LeetCode (1. Two Sum): 
// https://leetcode.com/problems/two-sum/ 


#include<vector>
using namespace std;


class Solution {
public:

    vector<int> twoSum(vector<int>& nums, int target) {
        
        int n = nums.size();
        vector<int> ans;

        for(int i=0; i < n-1; i++){
            for(int j=i+1; j < n; j++){
                if((nums[i] + nums[j]) == target){
                    ans.push_back(i);
                    ans.push_back(j);
                    return ans;
                }
            }
        }

        return ans;
    }
};


// T.C. = O((n * (n-1))/2) = O(n^2) 
// S.C. = O(1) 

// Here, n = total number of elements which are present inside the input vector named "nums" 