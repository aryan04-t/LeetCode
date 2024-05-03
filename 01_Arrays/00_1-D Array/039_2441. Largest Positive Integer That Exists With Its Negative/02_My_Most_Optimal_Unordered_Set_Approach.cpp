// LeetCode (2441. Largest Positive Integer That Exists With Its Negative): 
// https://leetcode.com/problems/largest-positive-integer-that-exists-with-its-negative/ 


#include<vector> 
#include<unordered_set> 
using namespace std; 


class Solution {
public:

    int findMaxK(vector<int>& nums) {
        
        unordered_set<int> s; 
        for(int val : nums) s.insert(val); 

        int ans = -1; 
        for(int val : nums){
            if(val > 0){
                if(s.find(-val) != s.end()){
                    if(val > ans) ans = val; 
                }
            }
        }

        return ans; 
    }
};


// T.C. = O(n) + O(n) = O(2n) = O(n) 
// S.C. = O(n) 

// Here, n = the total number of elements which are present inside the input vector named "nums" 