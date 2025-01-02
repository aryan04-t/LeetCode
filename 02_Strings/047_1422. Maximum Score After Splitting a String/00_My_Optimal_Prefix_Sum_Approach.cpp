// LeetCode (1422. Maximum Score After Splitting a String): 
// https://leetcode.com/problems/maximum-score-after-splitting-a-string 


#include<vector> 
#include<string> 
using namespace std; 


class Solution {
public:

    int maxScore(string s) {
        
        int n = s.length(); 

        vector<int> zeroesFromLeft(n, 0); 

        int count = 0; 
        for (int i=0; i < n; i++) {
            if (s[i] == '0') count++; 
            zeroesFromLeft[i] = count; 
        }

        vector<int> onesFromRight(n, 0); 

        count = 0; 
        for (int i=n-1; i >= 0; i--) {
            if (s[i] == '1') count++; 
            onesFromRight[i] = count; 
        }

        int maxScore = 0; 
        for (int i=0; i < n-1; i++) {
            int score = zeroesFromLeft[i] + onesFromRight[i+1]; 
            if (score > maxScore) maxScore = score; 
        }

        return maxScore; 
    }
};


// T.C. = O(3n) = O(n) 
// S.C. = O(2n) = O(n) 

// Here, n = the length of input string named "s" 