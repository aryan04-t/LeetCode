// LeetCode (128. Longest Consecutive Sequence): 
// https://leetcode.com/problems/longest-consecutive-sequence/ 


#include<vector> 
#include<unordered_set> 
using namespace std; 


class Solution {
public:

    int longestConsecutive(vector<int>& nums) {

        int n = nums.size(); 

        unordered_set<int> s; 
        for(int val : nums) s.insert(val); 

        int finalAns = 0;

        for(int val : nums){
            int ans = 1;
            while(s.find(val+1) != s.end()){
                val++; 
                ans++; 
            }
            if(ans > finalAns) finalAns = ans; 
            if(ans == s.size()) break; 
        }

        return finalAns; 
    }
};


// T.C. = O(n) + O((n * (n-1))/2) = O(n^2) 
// S.C. = O(n) 

// Here, n = the total number of elements which are present inside the input vector named "nums" 