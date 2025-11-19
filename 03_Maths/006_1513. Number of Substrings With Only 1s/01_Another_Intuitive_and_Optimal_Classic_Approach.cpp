// LeetCode (1513. Number of Substrings With Only 1s): 
// https://leetcode.com/problems/number-of-substrings-with-only-1s 


#include<string>
using namespace std;


class Solution {
public:
    int numSub(string s) {

        long long totalOneSubstrs = 0;
        long long consecutiveOnes = 0;

        int n = s.length();
        
        for (int i=0; i < n; i++) {
            
            char ch = s[i];
            if (ch == '1') {
                consecutiveOnes++;
                totalOneSubstrs += consecutiveOnes;
            }
            
            if (ch == '0') consecutiveOnes = 0;
        }

        long long M = (1e9 + 7);

        return static_cast<int>(totalOneSubstrs % M);
    }
};


/*
    # Intuition: 
      - Instead of counting the full streak and applying (k*(k+1))/2 at the end, we incrementally add substrs as the streak grows
      - When streak length becomes k, it contributes exactly k new substrs ending at the current position
      - For example: streak lengths 1, 2, 3 contribute 1, 2, 3 substrs respectively → total = 1+2+3 = (3*4)/2
      - This way we're building the same sum incrementally: adding k at each step naturally produces the sum formula
*/


// T.C. = O(n) 
// S.C. = O(1) 

// Here, n = the length of input string named "s" 