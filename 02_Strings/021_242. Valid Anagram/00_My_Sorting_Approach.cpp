// LeetCode (242. Valid Anagram): 
// https://leetcode.com/problems/valid-anagram/ 


#include<string> 
#include<algorithm> 
using namespace std; 


class Solution {
public:

    bool isAnagram(string s, string t) {

        int n = s.length(); 
        int m = t.length(); 

        if(n != m) return false; 

        sort(s.begin(), s.end()); 
        sort(t.begin(), t.end()); 

        for(int i=0; i < n; i++){
            if(s[i] != t[i]) return false; 
        }

        return true; 

    }
};


// T.C. = O(n * log(n)) 
// S.C. = O(log(n)) 

// Here, n = the length of the input string named "s" / "t" = m 