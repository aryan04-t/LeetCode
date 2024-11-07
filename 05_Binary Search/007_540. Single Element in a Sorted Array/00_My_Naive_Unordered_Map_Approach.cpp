// LeetCode (540. Single Element in a Sorted Array): 
// https://leetcode.com/problems/single-element-in-a-sorted-array/ 


#include<vector> 
#include<unordered_map> 
using namespace std; 


class Solution {
public:

    int singleNonDuplicate(vector<int>& nums) {

        unordered_map<int, int> mp; 
        for(int val : nums) mp[val]++; 

        for(auto p : mp){
            if(p.second == 1) return p.first; 
        }

        return -1; 
    }
};


// T.C. = O(n) + O((n+1)/2) = O(n) 
// S.C. = O((n+1)/2) = O(n) 

// Here, n = the total number of elements which are present inside the input vector named "nums" 