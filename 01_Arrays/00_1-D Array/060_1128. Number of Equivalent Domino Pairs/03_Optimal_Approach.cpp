// LeetCode (1128. Number of Equivalent Domino Pairs): 
// https://leetcode.com/problems/number-of-equivalent-domino-pairs 


#include<vector>
#include<unordered_map>
using namespace std;


class Solution {
public:

    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        
        int n = dominoes.size(); 
        int totalEqPairs = 0;

        vector<int> vecHash(100, 0);

        for (int i=0; i < n; i++) {
            const vector<int> &v = dominoes[i]; 
            int hash = v[0] > v[1] ? v[1] * 10 + v[0] : v[0] * 10 + v[1]; 
            totalEqPairs += vecHash[hash]; 
            vecHash[hash]++;
        }

        return totalEqPairs; 
    }
};


// T.C. = O(n) 
// S.C. = O(100) = O(1) 

// Here, n = the length of input vector "dominoes" 