// LeetCode (Palindromic Substrings): 
// https://leetcode.com/problems/palindromic-substrings/description/ 


#include<iostream>
#include<string>
using namespace std;


class Solution {
public:
    bool checkPalindrome(string s){
        int i = 0;
        int j = s.length() - 1;

        while(i <= j){
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }

        return true;
    }

    int countSubstrings(string s) {
        
        int count = 0;

        for(int i=0; i < s.length(); i++){
            for(int j=1; j <= s.length()-i; j++){
                count = count + checkPalindrome(s.substr(i,j));
            }
        }

        return count;
    }
};


// T.C.: 

// S.C.: O(1) 

// Here, n = length of input string named 's' 