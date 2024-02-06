// LeetCode (1512. Number of Good Pairs): 
// https://leetcode.com/problems/number-of-good-pairs/ 


#include<vector> 
#include<unordered_map> 
using namespace std;


class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        
        unordered_map<int,int> mp;
        
        int ans = 0;
        
        for(int i : nums){
            ans += mp[i];
            mp[i]++;
        }

        return ans;
    }
};


// T.C. = O(n) 
// S.C. = O(n) 

// Here, n = number of elements present inside the input vector named "nums" 