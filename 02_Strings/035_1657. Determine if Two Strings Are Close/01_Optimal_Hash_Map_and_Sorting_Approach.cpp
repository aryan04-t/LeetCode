// LeetCode (1657. Determine if Two Strings Are Close): 
// https://leetcode.com/problems/determine-if-two-strings-are-close/ 


#include<string> 
#include<vector> 
#include<algorithm>  
using namespace std; 


class Solution {
public:

    bool closeStrings(string word1, string word2) {

        int n = word1.length(); 
        int m = word2.length(); 

        if(n != m) return false; 

        vector<int> word1CharFreqHash(26, 0); 
        vector<int> word2CharFreqHash(26, 0); 
        for(char ch : word1) word1CharFreqHash[ch - 'a']++; 
        for(char ch : word2) word2CharFreqHash[ch - 'a']++; 

        for(int i=0; i < 26; i++){
            if(word1CharFreqHash[i] == 0 && word2CharFreqHash[i] != 0) return false; 
            if(word1CharFreqHash[i] != 0 && word2CharFreqHash[i] == 0) return false; 
        }

        sort(word1CharFreqHash.begin(), word1CharFreqHash.end()); 
        sort(word2CharFreqHash.begin(), word2CharFreqHash.end()); 

        for(int i=0; i < 26; i++){
            if(word1CharFreqHash[i] != word2CharFreqHash[i]) return false; 
        } 

        return true; 
    }
};


// T.C. = O(26) + O(26) + O(n) + O(m) + O(26) + O(26 * log(26)) + O(26 * log(26)) + O(26) = O(2n) + O(4 * 26) + O(2 * 26 * log(26)) = O(n) -> (Because n always == m when the loops are running, because the base case would never let the input reach loops if n != m) 
// S.C. = O(26) + O(26) + log(26) = O(2 * 26) + log(26) = O(1) 

// Here, n = the length of input string named "word1", and m = the length of input string named "word2" 