// LeetCode (242. Valid Anagram): 
// https://leetcode.com/problems/valid-anagram/ 


#include<string> 
#include<unordered_map> 
using namespace std; 


class Solution {
public:

    bool isAnagram(string s, string t) {
        
        int n = s.length(); 
        int m = t.length(); 

        if(n != m) return false; 

        unordered_map<char, int> mp; 

        for(int i=0; i < n; i++){
            mp[s[i]]++;
        }

        for(int i=0; i < m; i++){
            mp[t[i]]--; 
        }

        for(const pair<char, int> &p : mp){
            if(p.second != 0) return false; 
        }

        return true; 

    }
};


// T.C. = O(n) + O(n) + O(26) = O(2n) + O(26) = O(n) 
// S.C. = O(26) = O(1) 

// Here, n = the length of input string named "s", and m = the length of input string named "t" 