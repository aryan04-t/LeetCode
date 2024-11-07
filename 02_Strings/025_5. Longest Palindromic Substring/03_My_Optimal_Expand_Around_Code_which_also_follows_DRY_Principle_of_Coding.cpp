// LeetCode (5. Longest Palindromic Substring): 
// https://leetcode.com/problems/longest-palindromic-substring/ 


#include<string> 
using namespace std; 


class Solution {
public: 

    void expandAroundAndCheckPalindrome(const string &s, int j, int k, int &maxLen, string &ans){

        int n = s.length(); 

        while(j >= 0 && k < n){
                
            if(s[j] == s[k]){

                int currLen = k-j+1;
                
                if(currLen > maxLen){
                    maxLen = currLen;
                    ans = s.substr(j, currLen);
                }

                j--;
                k++; 
            }
            else{
                break;
            }
        }
    }

    string longestPalindrome(string s) {

        int n = s.length(); 
        
        int maxLen = 0; 
        string ans; 

        for(int i=0; i < n; i++){
            expandAroundAndCheckPalindrome(s, i, i, maxLen, ans);
            expandAroundAndCheckPalindrome(s, i, i+1, maxLen, ans);
        }

        return ans;
    }
};


// T.C. = O(n^2) 
// S.C. = O(n) -> (This space complexity is caused due to the "ans" string) 

// Here, n = the length of the input string named "s" 