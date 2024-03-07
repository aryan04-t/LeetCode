// LeetCode (3. Longest Substring Without Repeating Characters): 
// https://leetcode.com/problems/longest-substring-without-repeating-characters/ 


#include<string> 
#include<unordered_map> 
#include<algorithm>  
using namespace std; 


class Solution {
public:

    int lengthOfLongestSubstring(string s) {

        int n = s.length(); 
        int longestLen = 0;

        for(int i=0; i < n; i++){

            int len = 0;
            unordered_map<char, bool> mp;    

            for(int j=i; j < n; j++){

                if(!mp[s[j]]){
                    len++; 
                    mp[s[j]] = true; 
                }
                else{
                    break;
                }

            }

            longestLen = max(longestLen, len);

        }

        return longestLen;

    }
};


// T.C. = O((n * (n+1)) / 2) = O(n^2) 
// S.C. = O(n) 

// Here, n = the length of input string named "s" 