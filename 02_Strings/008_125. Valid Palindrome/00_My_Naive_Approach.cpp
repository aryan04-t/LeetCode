// LeetCode (125. Valid Palindrome): 
// https://leetcode.com/problems/valid-palindrome/ 


#include<string> 
using namespace std;


class Solution {
public:

    char toLower(char &c){ 
        
        if((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z')){
            return c;
        }
        
        char ch = c - 'A' + 'a';

        return ch;
    }

    bool isPalindrome(string s) {
        
        string output = "";
        int n = s.length();

        for(int i=0; i < n; i++){
            if(s[i] >= '0' && s[i] <= '9'){
                output.push_back(s[i]);
            }
            if(s[i] >= 'A' && s[i] <= 'Z'){
                output.push_back(s[i]);
            }
            if(s[i] >= 'a' && s[i] <= 'z'){
                output.push_back(s[i]);
            }
        }

        int start = 0;
        int end = output.length() - 1;

        while(start < end){
            if(toLower(output[start]) != toLower(output[end])){
                return false;
            } 
            start++;
            end--;
        }

        return true;
    }
};


// T.C. = O(n) + O(n/2) = O(n) 
// S.C. = O(n) 

// Here, n = the length of input string named "s" 