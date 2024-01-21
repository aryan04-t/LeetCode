// LeetCode (217. Contains Duplicate): 
// https://leetcode.com/problems/contains-duplicate/ 


#include<vector> 
#include<algorithm> 
using namespace std;


class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());

        int n = nums.size();

        for(int i=1; i < n; i++){
            if(nums[i] == nums[i-1]) return true; 
        }

        return false;
    }
};


// T.C. = O(n * (log(n) to the base 2)) + O(n) = O(n * (log(n) to the base 2)) 
// S.C. = O(log(n) to the base 2) -> Introsort has this worst case space complexity 

// Here, n = total number of elements which are present inside the input vector named "nums" 