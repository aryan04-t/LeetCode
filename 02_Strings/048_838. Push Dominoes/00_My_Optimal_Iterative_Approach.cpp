// LeetCode (838. Push Dominoes): 
// https://leetcode.com/problems/push-dominoes 


#include<string> 
using namespace std; 


class Solution {
public:

    void populateChar(string &dominoes, int start, int end, char ch) {
        while (start <= end) {
            dominoes[start] = ch;
            start++;
        }
    }

    string pushDominoes(string dominoes) {
        
        int lastRIndex = -1;
        int lastLIndex = -1;

        int n = dominoes.size(); 

        for (int i=0; i < n; i++) {
            if (dominoes[i] == 'L') {
                if (lastRIndex > lastLIndex) {
                    int diff = i - lastRIndex - 1;
                    if (diff > 1) {
                        int dist = int(diff/2);
                        bool isDiffEven = diff % 2 == 0 ? true : false;
                        int rStart = lastRIndex + 1;
                        int rEnd = lastRIndex + dist;
                        int lStart = lastRIndex + dist + (isDiffEven ? 1 : 2); 
                        int lEnd = lastRIndex + diff;
                        populateChar(dominoes, rStart, rEnd, 'R');
                        populateChar(dominoes, lStart, lEnd, 'L');
                    }
                }
                else {
                    populateChar(dominoes, lastLIndex + 1, i-1, 'L'); 
                }
                lastLIndex = i; 
            }
            else if (dominoes[i] == 'R') {
                if (lastRIndex > lastLIndex) {
                    populateChar(dominoes, lastRIndex + 1, i-1, 'R'); 
                }
                lastRIndex = i; 
            }
        }

        if (lastRIndex > lastLIndex) {
            populateChar(dominoes, lastRIndex + 1, n-1, 'R'); 
        }

        return dominoes;
    }
};


// T.C. = O(2n) = O(n) 
// S.C. = O(1) 

// Here, n = the length of input string named "dominoes"