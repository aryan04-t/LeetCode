// LeetCode (1915. Number of Wonderful Substrings): 
// https://leetcode.com/problems/number-of-wonderful-substrings/ 


#include<string> 
#include<vector> 
using namespace std; 


class Solution {
public:

    void checkWonderfulSubstrings(string &s, int i, int j, long long &ans){

        int m = s.length(); 

        vector<int> charFreqHash(10, 0); 

        while(i <= j){
            charFreqHash[s[i] - 'a']++; 
            i++; 
        }

        int oddFreqCount = 0; 

        for(int i=0; i < 10; i++){
            if(charFreqHash[i] & 1) oddFreqCount++; 
        }

        if(oddFreqCount <= 1) ans++; 
    }

    long long wonderfulSubstrings(string word) {

        long long ans = 0; 
        int n = word.length(); 

        for(int i=0; i < n; i++){
            for(int j=i; j < n; j++){
                checkWonderfulSubstrings(word, i, j, ans); 
            }
        }

        return ans; 
    }
};


// T.C. = O(n^3) 
// S.C. = O(1) 

// Here, n = the length of the input string named "word" 