// LeetCode (1128. Number of Equivalent Domino Pairs): 
// https://leetcode.com/problems/number-of-equivalent-domino-pairs 


#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;


class VectorHash {
public: 

    size_t operator()(const vector<int>& v) const {
        size_t hash = 17;
        for (int i : v) {
            hash = hash * 31 + i;
        }
        return hash;
    }
};

class Solution {
public:

    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        
        int n = dominoes.size(); 
        
        unordered_map<vector<int>, int, VectorHash> mp;

        for (int i=0; i < n; i++) {
            vector<int> d1 = dominoes[i]; 
            sort(d1.begin(), d1.end()); 
            mp[d1]++;
        }

        int totalEqPairs = 0; 

        for (const pair<vector<int>, int> &p : mp) {
            totalEqPairs += ((p.second)*(p.second-1))/2;
        }

        return totalEqPairs; 
    }
};


// T.C. = O(n) + O(n) = O(2n) = O(n) 
// S.C. = O(2n) = O(n) 

// Here, n = the length of input vector "dominoes"