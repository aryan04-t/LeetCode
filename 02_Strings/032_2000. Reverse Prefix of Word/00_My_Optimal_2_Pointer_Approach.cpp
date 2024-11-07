// LeetCode (2000. Reverse Prefix of Word): 
// https://leetcode.com/problems/reverse-prefix-of-word/ 


#include<string> 
using namespace std; 


class Solution {
public:

    void reverse(int start, int end, string &s){
        while(start < end){
            swap(s[start], s[end]);
            start++; 
            end--; 
        }
    }

    string reversePrefix(string word, char ch) {

        int n = word.length(); 

        int i=0; 
        while(i < n){
            if(word[i] == ch) break; 
            i++; 
        }

        if(i == n) i = 0; 

        reverse(0, i, word); 
        return word; 
    }
}; 


// T.C. = O(n) + O(n/2) = O(n) 
// S.C. = O(1) 

// Here, n = the length of input string named "word" 