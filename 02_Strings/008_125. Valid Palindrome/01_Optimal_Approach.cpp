// LeetCode (125. Valid Palindrome): 
// https://leetcode.com/problems/valid-palindrome/ 


#include<string> 
using namespace std;


class Solution {
public:

    bool isAplhaNumeric(char c){

        if(c >= '0' && c <= '9'){
            return true;
        }
        if(c >= 'A' && c <= 'Z'){
            return true;
        }
        if(c >= 'a' && c <= 'z'){
            return true;
        }

        return false;
    }

    char toLower(char c){ 
        if((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z')){
            return c;
        }
        char ch = c - 'A' + 'a';
        return ch;
    }

    bool isPalindrome(string s) {
        
        int start = 0;
        int end = s.length() - 1;

        while(start < end){
            
            if(!isAplhaNumeric(s[start])){
                start++;
                continue;
            }
            
            if(!isAplhaNumeric(s[end])){
                end--;
                continue;
            }
            
            if(toLower(s[start]) != toLower(s[end])) return false;
            
            start++;
            end--;

        }

        return true;
    }
};


// T.C. = O(n/2) = O(n) 
// S.C. = O(1) 

// Here, n = the length of input string named "s" 