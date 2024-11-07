// LeetCode (5. Longest Palindromic Substring): 
// https://leetcode.com/problems/longest-palindromic-substring/ 


#include<string> 
using namespace std; 


class Solution {
public:

    bool checkPalindrome(const string &s){

        int start = 0;
        int end = s.length()-1; 

        while(start < end){
            if(s[start] != s[end]) return false; 
            start++; 
            end--; 
        }

        return true; 
    }

    string longestPalindrome(string s) {

        int n = s.length(); 
        
        int maxLen = 0; 
        string ans; 

        for(int i=0; i < n; i++){
            for(int j=i; j < n; j++){
                
                string currStr = s.substr(i, j-i+1); 

                if(checkPalindrome(currStr)){
                    
                    int currLen = currStr.length();
                    
                    if(currLen > maxLen){
                        maxLen = currLen;
                        ans = currStr;
                    }
                }
            }
        }

        return ans;

    }
};


// T.C. = O(n^3) 
// S.C. = O(n) -> (This space complexity is caused due to the "ans" string) 

// Here, n = the length of the input string named "s" 