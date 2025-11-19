// LeetCode (3234. Count the Number of Substrings With Dominant Ones): 
// https://leetcode.com/problems/count-the-number-of-substrings-with-dominant-ones 


// This naive approach of mine gives TLE, I expected this after seeing the constraints 
// But the intuition of optimal approach of this question goes over my head for now - I will look back at this question when I will reach this questions rating level - for now just stamping in my naive approach as a record 


#include<string>
using namespace std;


class Solution {
public:
    int numberOfSubstrings(string s) {
        
        int n = s.length();
        int dominantOneSubstrs = 0;

        for (int i=0; i < n; i++) {
            
            long long totalZeroes = 0;
            long long totalOnes = 0;
            
            for (int j=i; j < n; j++) {
                
                char currChar = s[j];
                if (currChar == '0') totalZeroes++;
                else if (currChar == '1') totalOnes++;

                long long totalZeroesSq = totalZeroes * totalZeroes;
                if (totalOnes >= totalZeroesSq) {
                    dominantOneSubstrs++;
                }
            }
        }

        return dominantOneSubstrs;
    }
};


// T.C. = O((n*(n+1))/2) = O(n^2) 
// S.C. = O(1) 

// Here, n = the length of input string named "s" 