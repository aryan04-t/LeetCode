// LeetCode (3146. Permutation Difference between Two Strings): 
// https://leetcode.com/problems/permutation-difference-between-two-strings/ 


#include<string> 
#include<vector> 
using namespace std; 


class Solution {
public:

    int findPermutationDifference(string s, string t) {
        
        vector<int> sHash(26, 0); 
        vector<int> tHash(26, 0);
        
        int n = s.length();
        
        for(int i=0; i < n; i++) sHash[s[i] - 'a'] = i;
        for(int i=0; i < n; i++) tHash[t[i] - 'a'] = i; 
        
        int ans = 0;
        for(char ch : s){
            ans += abs(sHash[ch-'a'] - tHash[ch-'a']);
        }
        
        return ans;
    }
};


// T.C. = O(n) + O(n) + O(n) = O(3n) = O(n) 
// S.C. = O(26) + O(26) = O(1) 

// Here, n = the length of input string named "s" = the length of input string named "t" 