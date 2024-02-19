// LeetCode (28. Find the Index of the First Occurrence in a String): 
// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/ 


#include<string> 
using namespace std; 


class Solution {
public:

    int strStr(string haystack, string needle) {
        
        int n = haystack.length();
        int m = needle.length();

        int ans = -1;

        for(int i=0; i < n - m + 1; i++){
            
            int j = i;
            int k = 0;
            bool needlePresent = true;
            
            while(k < m){
                if(haystack[j] != needle[k]){
                    needlePresent = false;
                    break;
                }
                j++; 
                k++; 
            }

            if(needlePresent){
                ans = i;
            }
            
            if(ans != -1){
                break;
            }

        }

        return ans;

    }
};


// T.C. = O(n-m+1) * O(m) = O(n*m) - O(m^2) + O(m) = O(n*m) 
// S.C. = O(1) 

// Here, n = the length of input string named "haystack", and m = the length of input string named "needle" 