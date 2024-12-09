// LeetCode (2554. Maximum Number of Integers to Choose From a Range I): 
// https://leetcode.com/problems/maximum-number-of-integers-to-choose-from-a-range-i 


#include<vector> 
#include<unordered_set> 
using namespace std; 


class Solution {
public:

    int maxCount(vector<int>& banned, int n, int maxSum) {

        unordered_set<int> s(banned.begin(), banned.end()); 

        int i = 1, sum = 0, numCount = 0; 

        while (i <= n) {
            if (sum >= maxSum) break; 
            if (s.find(i) == s.end()) {
                sum += i; 
                numCount++; 
            }
            i++; 
        }

        if (sum > maxSum) numCount--; 

        return numCount; 
    }
}; 


// T.C. = O(m) + O(n) 
// S.C. = O(m) 

// Here, m = the length of 1-D input vector named "banned", and n = the value of input variable named "n" 