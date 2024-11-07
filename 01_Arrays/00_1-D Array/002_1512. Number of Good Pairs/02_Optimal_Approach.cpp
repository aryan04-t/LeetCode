// LeetCode (1512. Number of Good Pairs): 
// https://leetcode.com/problems/number-of-good-pairs/ 


#include<vector> 
#include<unordered_map> 
using namespace std;


class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        
        unordered_map<int, int> mp;

        int count = 0;

        for(auto val : nums){
            count += mp[val];
            mp[val]++;
        }

        return count; 

    }
};


// T.C. = O(n) 
// S.C. = O(m) 

// Here, n = total number of elements which are present inside the input vector named "nums", and m = total number of unique elements which are present inside the input vector named "nums" 