// LeetCode (5. Longest Palindromic Substring): 
// https://leetcode.com/problems/longest-palindromic-substring/ 


#include<string> 
using namespace std; 


class Solution {
public: 

    string longestPalindrome(string s) {

        int n = s.length(); 
        
        int maxLen = 0; 
        string ans; 

        for(int i=0; i < n; i++){
            
            int j = i; 
            int k = i; 

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
                
            j = i;
            k = i+1; 

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

        return ans;

    }
};


// T.C. = O(n^2) 
// S.C. = O(n) -> (This space complexity is caused due to the "ans" string) 

// Here, n = the length of the input string named "s" 