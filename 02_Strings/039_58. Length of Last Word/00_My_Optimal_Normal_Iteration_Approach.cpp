// LeetCode (58. Length of Last Word): 
// https://leetcode.com/problems/length-of-last-word/ 


#include<string> 
using namespace std; 

class Solution {
public:
    int lengthOfLastWord(string s) {
        
        int len = 0;
        int n = s.length(); 
        int i = n - 1; 
        
        while(s[i] == ' ') i--; 
        while(i != -1 && s[i] != ' '){
            len++;
            i--; 
        }

        return len; 
    }
};


// T.C. = O(n) 
// S.C. = O(1) 

// Here, n = the length of input string named "s" 