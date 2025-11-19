// LeetCode (2154. Keep Multiplying Found Values by Two): 
// https://leetcode.com/problems/keep-multiplying-found-values-by-two/ 


#include<vector> 
#include<unordered_set> 
using namespace std; 


class Solution {
public:

    int findFinalValue(vector<int>& nums, int original) {

        unordered_set<int> s;
        for(int val : nums) s.insert(val); 

        while(s.find(original) != s.end()){
            original *= 2; 
        }

        return original; 
    }
};


// T.C. = O(n) + O(n) = O(2n) = O(n) 
// S.C. = O(n) 

// Here, n = the total number of elements which are present inside the input vector named "nums" 