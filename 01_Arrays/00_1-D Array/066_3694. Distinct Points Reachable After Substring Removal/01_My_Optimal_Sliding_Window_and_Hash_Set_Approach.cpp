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

        pair<int, int> coords = {0, 0};

        for (int i=k; i < n; i++) {
            char ch = s[i];
            coords.first += dirMap[ch][0];
            coords.second += dirMap[ch][1]; 
        }

        unordered_set<pair<int, int>, PairHash> st;
        st.insert(coords);

        for (int i=0; i < n - k; i++) {

            char ch1 = s[i];
            coords.first += dirMap[ch1][0];
            coords.second += dirMap[ch1][1];
            
            char ch2 = s[i+k];
            coords.first -= dirMap[ch2][0];
            coords.second -= dirMap[ch2][1];

            st.insert(coords);
        }

        return int(st.size());
    }
};


// T.C. = O(n-k) + O(n-k) = O(n) 
// S.C. = O(n) 

// Here, n = the length of input string named "s" 