// LeetCode (3694. Distinct Points Reachable After Substring Removal): 
// https://leetcode.com/problems/distinct-points-reachable-after-substring-removal 


#include<string>
#include<vector>
#include<functional>
#include<unordered_set>
#include<unordered_map>
using namespace std;


class PairHash {
public:
    size_t operator() (const pair<int, int> &p) const {
        
        hash<int> IntHash;
        
        size_t pairHash = IntHash(p.first) ^ IntHash(p.second << 2); 
        // XOR and Shift operators are used to spread bits 
        // Creating a unique spreaded hash prevents collision 

        return pairHash;
    }
};


class Solution {
public:

    int distinctPoints(string s, int k) {
        
        int n = s.length();

        unordered_map<char, vector<int>> dirMap = {
            { 'U', {0, 1} },
            { 'D', {0, -1} },
            { 'L', {-1, 0} },
            { 'R', {1, 0} }
        };
        
        unordered_set<pair<int, int>, PairHash> st;

        int i = 0;
        int totalPaths = n - k + 1;

        while (i < totalPaths) {
            
            pair<int, int> coords = {0, 0};
            
            for (int j=0; j < n; j++) {

                if (j >= i && j < i+k) continue;

                char ch = s[j];
                coords.first += dirMap[ch][0];
                coords.second += dirMap[ch][1];
            }

            st.insert(coords);
            
            i++;
        }

        return int(st.size());
    }
};


// T.C. = O((n - k + 1) * n) = O(n^2) 
// S.C. = O(n) 

// Here, n = the length of input string named "s" 