// LeetCode (1128. Number of Equivalent Domino Pairs): 
// https://leetcode.com/problems/number-of-equivalent-domino-pairs 


// Gives TLE Error 


#include<vector>
using namespace std;


class Solution {
public:

    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        
        int n = dominoes.size(); 
        int totalEqPairs = 0;

        for (int i=0; i < n-1; i++) {
            for (int j=i+1; j < n; j++) {
                const vector<int> &d1 = dominoes[i]; 
                const vector<int> &d2 = dominoes[j]; 
                if (
                    (d1[0] == d2[0] && d1[1] == d2[1]) || 
                    (d1[0] == d2[1] && d1[1] == d2[0]) 
                ) {
                    totalEqPairs++;
                }
            }
        }

        return totalEqPairs; 
    }
};


// T.C. = O((n*(n-1))/2) = O(n^2) 
// S.C. = O(1) 

// Here, n = the length of input vector "dominoes" 