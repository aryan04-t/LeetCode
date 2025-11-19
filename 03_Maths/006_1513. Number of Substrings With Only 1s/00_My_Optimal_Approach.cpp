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
            if (ch == '1') consecutiveOnes++;
            
            char nextChar = (i+1 == n) ? '0' : s[i+1];
            if (nextChar == '0') {
                long long oneSubstrs = (consecutiveOnes * (consecutiveOnes + 1))/2;
                totalOneSubstrs += oneSubstrs;
                consecutiveOnes = 0;
            }
        }

        long long M = (1e9 + 7);

        return static_cast<int>(totalOneSubstrs % M);
    }
};


/*
    # Intuition: 
      - Count consecutive ones in each streak, then calculate substrs when the streak ends
      - A streak of length k can form -> k substrs of length 1, (k-1) of length 2, (k-2) of length 3, ... 1 substr of length k
      - Total = k + (k-1) + (k-2) + ... + 1 = k*(k+1)/2 (sum of first k natural numbers)
      - Process each streak independently and sum up all contributions
*/


// T.C. = O(n) 
// S.C. = O(1) 

// Here, n = the length of input string named "s" 