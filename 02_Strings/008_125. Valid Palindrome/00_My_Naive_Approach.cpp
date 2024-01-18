// LeetCode (125. Valid Palindrome): 
// https://leetcode.com/problems/valid-palindrome/ 


#include<string> 
using namespace std;


class Solution {
public:

    char toLower(char &c){ 
        
        if((c >= 48 && c <= 57) || (c >= 97 && c <= 122)){
            return c;
        }
        
        char ch = c - 'A' + 'a';

        return ch;
    }

    bool isPalindrome(string s) {
        
        string output = "";
        int n = s.length();

        for(int i=0; i < n; i++){
            if(s[i] >= 48 && s[i] <= 57){
                output.push_back(s[i]);
            }
            if(s[i] >= 65 && s[i] <= 90){
                output.push_back(s[i]);
            }
            if(s[i] >= 97 && s[i] <= 122){
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