// LeetCode (2559. Count Vowel Strings in Ranges): 
// https://leetcode.com/problems/count-vowel-strings-in-ranges 


#include<vector> 
#include<string> 
#include<unordered_set> 
using namespace std; 


class Solution {
public:

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        
        int n = words.size(); 
        int m = queries.size(); 

        vector<int> vowelStringsCount(n, 0); 
        unordered_set<char> vowelSet({'a', 'e', 'i', 'o', 'u'}); 

        int count = 0; 
        int i = 0; 

        for (const string &word : words) {
            int l = word.length(); 
            bool firstAndLastCharIsVowel = (
                (vowelSet.find(word[0]) != vowelSet.end()) 
                && 
                (vowelSet.find(word[l-1]) != vowelSet.end())
            ); 
            if (firstAndLastCharIsVowel) count++; 
            vowelStringsCount[i] = count; 
            i++; 
        }

        vector<int> ans(m, 0); 
        i = 0; 

        for (const vector<int> &q : queries) {
            int prevIndexFromStart = q[0] - 1;
            int count1 = (prevIndexFromStart == -1) ? 0 : vowelStringsCount[prevIndexFromStart]; 
            int count2 = vowelStringsCount[q[1]]; 
            ans[i] = count2 - count1; 
            i++; 
        }

        return ans;
    }
};


// T.C. = O(n) + O(m) = O(n + m) 
// S.C. = O(n) + O(5) + O(m) = O(n + m) 

// Here, n = the length of 1-D string input vector named "words", and m = the length of 2-D input vector named "queries" 