// LeetCode (14. Longest Common Prefix): 
// https://leetcode.com/problems/longest-common-prefix/ 


#include<vector> 
#include<string> 
#include<algorithm> 
using namespace std; 


class Solution {
public:

    string longestCommonPrefix(vector<string>& strs) {

        sort(strs.begin(), strs.end()); 

        int n = strs.size(); 
        int minLen = strs[0].size(); 
        string ans = ""; 

        for(int i=0; i < minLen; i++){
            if(strs[0][i] == strs[n-1][i]){
                ans.push_back(strs[0][i]); 
            }
            else{
                break; 
            }
        }

        return ans; 

    }
};


// T.C. = O(n * log(n) * m) + O(k) = O(n * log(n) * m) 
// S.C. = O(log(n)) + O(k) 

// Here, n = the total number of strings which are present inside the input vector named "strs", m = the average length of the strings which are present in the input vector "strs", and k = the length of the smallest string which is present in the input vector "strs" 