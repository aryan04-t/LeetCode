// LeetCode (1128. Number of Equivalent Domino Pairs): 
// https://leetcode.com/problems/number-of-equivalent-domino-pairs 


#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;


class PairHash {
public: 

    size_t operator()(const pair<int, int>& p) const {
        size_t hash = (17 * p.first) + (p.second * 31); 
        return hash;
    }
};

class Solution {
public:

    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        
        int n = dominoes.size();
        
        unordered_map<pair<int, int>, int, PairHash> mp;

        for (int i=0; i < n; i++) {
            vector<int> d1 = dominoes[i];
            pair<int, int> p = {d1[0], d1[1]};
            if (d1[0] > d1[1]) p = {d1[1], d1[0]};
            mp[p]++;
        }

        int totalEqPairs = 0; 

        for (const pair<pair<int, int>, int> &p : mp) {
            totalEqPairs += ((p.second)*(p.second-1))/2;
        }

        return totalEqPairs; 
    }
};


// T.C. = O(n) + O(n) = O(2n) = O(n) 
// S.C. = O(2n) = O(n) 

// Here, n = the length of input vector "dominoes"