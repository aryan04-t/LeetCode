// LeetCode (242. Valid Anagram): 
// https://leetcode.com/problems/valid-anagram/ 


#include<string> 
#include<vector> 
using namespace std; 


class Solution {
public:

    bool isAnagram(string s, string t) {
        
        int n = s.length(); 
        int m = t.length(); 

        if(n != m) return false; 

        vector<int> charFreq(26, 0); 

        for(int i=0; i < n; i++){
            charFreq[s[i] - 'a']++;
        }

        for(int i=0; i < m; i++){
            charFreq[t[i] - 'a']--; 
        }

        for(int i=0; i < 26; i++){
            if(charFreq[i] != 0) return false; 
        }

        return true; 

    }
};


// T.C. = O(n) + O(n) + O(26) = O(2n) + O(26) = O(n) 
// S.C. = O(26) = O(1) 

// Here, n = the length of input string named "s", and m = the length of input string named "t" 