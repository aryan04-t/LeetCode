// LeetCode (1657. Determine if Two Strings Are Close): 
// https://leetcode.com/problems/determine-if-two-strings-are-close/ 


#include<string> 
#include<vector> 
#include<unordered_map> 
using namespace std; 


class Solution {
public:

    bool closeStrings(string word1, string word2) {

        int n = word1.length(); 
        int m = word2.length(); 

        if(n != m) return false; 

        vector<int> word1CharFreqHash(26, 0); 
        vector<int> word2CharFreqHash(26, 0); 
        for(int i=0; i < n; i++) word1CharFreqHash[word1[i] - 'a']++; 
        for(int i=0; i < n; i++) word2CharFreqHash[word2[i] - 'a']++; 

        unordered_map<int, int> mp1;
        unordered_map<int, int> mp2;
        for(int i=0; i < 26; i++) mp1[word1CharFreqHash[i]]++; 
        for(int i=0; i < 26; i++) mp2[word2CharFreqHash[i]]++; 

        for(const pair<int, int> &p : mp1){ 
            if(mp2.find(p.first) != mp2.end()){ 
                if(mp2[p.first] != p.second) return false; 
            }
            else return false; 
        }

        for(int i=0; i < 26; i++){
            if(word1CharFreqHash[i] == 0 && word2CharFreqHash[i] != 0) return false; 
            if(word1CharFreqHash[i] != 0 && word2CharFreqHash[i] == 0) return false; 
        }

        return true; 
    }
};


// T.C. = O(26) + O(26) + O(n) + O(m) + O(26) + O(26) + O(26) + O(26) = O(2n) + O(6 * 26) = O(n) -> -> (Because n always == m when the loops are running, because the base case would never let the input reach loops if n != m) 
// S.C. = O(26) + O(26) + O(26) + O(26) = O(4 * 26) = O(1) 

// Here, n = the length of input string named "word1", and m = the length of input string named "word2" 