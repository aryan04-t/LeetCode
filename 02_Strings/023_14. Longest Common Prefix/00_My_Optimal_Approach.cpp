// LeetCode (14. Longest Common Prefix): 
// https://leetcode.com/problems/longest-common-prefix/ 


#include<vector> 
#include<string> 
#include<limits.h> 
using namespace std; 


class Solution {
public:

    string longestCommonPrefix(vector<string>& strs) {
        
        int n = strs.size(); 
        int minLen = INT_MAX; 

        for(int i=0; i < n; i++){
            int len = strs[i].size(); 
            minLen = min(len, minLen); 
        }

        string ans = ""; 

        for(int i=0; i < minLen; i++){

            char c = strs[0][i]; 
            bool isPartOfPrefix = true;
            
            for(int j=1; j < n; j++){
                if(strs[j][i] != c){
                    isPartOfPrefix = false; 
                    break;
                }
            }

            if(isPartOfPrefix){
                ans.push_back(c);
            }
            else{
                break; 
            }
        }

        return ans;

    }
};


// T.C = O(n) + O(k * n) = O(k * n) 
// S.C. = O(k) 

// Here, n = the total number of strings which are present inside the input vector named "strs", and k = the length of the smallest string which is present in the input vector "strs" 