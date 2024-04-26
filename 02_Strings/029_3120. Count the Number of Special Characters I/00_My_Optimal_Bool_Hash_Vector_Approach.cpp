// LeetCode (3120. Count the Number of Special Characters I): 
// https://leetcode.com/problems/count-the-number-of-special-characters-i/ 


#include<vector>
#include<string> 
#include<cctype> 
using namespace std; 


class Solution {
public:

    int numberOfSpecialChars(string word) {

        vector<bool> lowerChar(26, false); 
        vector<bool> upperChar(26, false); 

        int n = word.length(); 

        for(char ch : word){
            if(islower(ch)) lowerChar[ch-'a'] = true; 
            else if(isupper(ch)) upperChar[ch-'A'] = true; 
        }

        int specialChar = 0; 
        for(int i=0; i < 26; i++){
            if(lowerChar[i] && upperChar[i]) specialChar++;
        }

        return specialChar; 
    }
};


// T.C. = O(n) + O(26) = O(n) 
// S.C. = O(26) + O(26) = O(1) 

// Here, n = the length of input string named "word" 