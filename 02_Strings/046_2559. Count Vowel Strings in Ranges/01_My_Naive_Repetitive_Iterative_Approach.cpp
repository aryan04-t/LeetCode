// LeetCode (2559. Count Vowel Strings in Ranges): 
// https://leetcode.com/problems/count-vowel-strings-in-ranges 


#include<vector> 
#include<string> 
#include<unordered_set> 
using namespace std; 


class Solution {
public:

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        
        int m = queries.size(); 

        unordered_set<char> vowelSet({'a', 'e', 'i', 'o', 'u'}); 

        vector<int> ans(m, 0); 
        int i = 0; 

        for (const vector<int> &q : queries) {
            int start = q[0]; 
            int end = q[1]; 
            int count = 0; 
            while (start <= end) {
                const string &word = words[start]; 
                int l = word.length(); 
                bool firstAndLastCharIsVowel = (
                    (vowelSet.find(word[0]) != vowelSet.end()) 
                    && 
                    (vowelSet.find(word[l-1]) != vowelSet.end()) 
                );
                if (firstAndLastCharIsVowel) count++; 
                start++; 
            }
            ans[i] = count; 
            i++; 
        }

        return ans;
    }
}; 


// T.C. = O(m*n) 
// S.C. = O(5) + O(m) = O(m) 

// Here, n = the length of 1-D string input vector named "words", and m = the length of 2-D input vector named "queries" 