// LeetCode (125. Valid Palindrome): 
// https://leetcode.com/problems/valid-palindrome/ 


#include<string> 
#include<cctype>                // tolower() and isalnum() 
using namespace std;


class Solution {
public:

    bool isPalindrome(string s) {
        
        int start = 0;
        int end = s.length() - 1;

        while(start < end){
            
            if(!isalnum(s[start])){
                start++;
                continue;
            }
            
            if(!isalnum(s[end])){
                end--;
                continue;
            }
            
            if(tolower(s[start]) != tolower(s[end])) return false;
            
            start++;
            end--;

        }

        return true;
    }
};


// T.C. = O(n/2) = O(n) 
// S.C. = O(1) 

// Here, n = the length of input string named "s" 