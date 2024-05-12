// LeetCode (3146. Permutation Difference between Two Strings): 
// https://leetcode.com/problems/permutation-difference-between-two-strings/ 


#include<string> 
#include<vector> 
using namespace std; 


class Solution {
public:

    int findPermutationDifference(string s, string t) {
        
        vector<int> sHash(26, 0); 
        
        int n = s.length();        
        for(int i=0; i < n; i++) sHash[s[i] - 'a'] = i;

        int ans = 0;
        for(int i=0; i < n; i++){
            ans += abs(i - sHash[t[i]-'a']);
        }
        
        return ans;
    }
};


// T.C. = O(n) + O(n) = O(2n) = O(n) 
// S.C. = O(26) = O(1) 

// Here, n = the length of input string named "s" = the length of input string named "t" 