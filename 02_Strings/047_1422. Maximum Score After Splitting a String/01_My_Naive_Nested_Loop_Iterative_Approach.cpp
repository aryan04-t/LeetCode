// LeetCode (1422. Maximum Score After Splitting a String): 
// https://leetcode.com/problems/maximum-score-after-splitting-a-string 


#include<vector> 
#include<string> 
using namespace std; 


class Solution {
public:

    int maxScore(string s) {
        
        int n = s.length(); 
        int maxScore = 0; 

        for (int i=0; i < n-1; i++) {

            int zeroesOnLeftSide = 0; 
            int j = 0; 
            while (j <= i) {
                if (s[j] == '0') zeroesOnLeftSide++; 
                j++; 
            }

            int onesOnRightSide = 0; 
            while (j < n) {
                if (s[j] == '1') onesOnRightSide++; 
                j++; 
            }
            
            int score = zeroesOnLeftSide + onesOnRightSide; 
            if (score > maxScore) maxScore = score; 
        }

        return maxScore; 
    }
};


// T.C. = O((n-1)*n) = O(n^2) 
// S.C. = O(1) 

// Here, n = the length of input string named "s" 