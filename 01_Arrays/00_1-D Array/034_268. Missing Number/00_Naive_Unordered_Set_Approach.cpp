// LeetCode (268. Missing Number): 
// https://leetcode.com/problems/missing-number/ 


#include<vector> 
#include<unordered_set> 
using namespace std; 


class Solution {
public:
    int missingNumber(vector<int>& nums) {

        unordered_set<int> s;
        for(int val : nums) s.insert(val);
        
        int n = nums.size(); 
        for(int i=0; i <= n; i++){
            if(s.find(i) == s.end()) return i; 
        }
        
        return -1; 
    }
};


// T.C. = O(n) 
// S.C. = O(n) 

// Here, n = the total number of values which are present inside the input vector "nums" 