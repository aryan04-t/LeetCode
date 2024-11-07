// LeetCode (3120. Count the Number of Special Characters I): 
// https://leetcode.com/problems/count-the-number-of-special-characters-i/ 


#include<string> 
#include<cctype> 
using namespace std; 


class Solution {
public:

    int numberOfSpecialChars(string word) {

        int lowerChar = 0;
        int upperChar = 0; 

        int n = word.length(); 

        for(char ch : word){
            if(islower(ch)) lowerChar |= 1 << int(ch - 'a'); 
            else if(isupper(ch)) upperChar |=  1 << int(ch - 'A'); 
        }

        int specialChar = 0; 
        for(int i=0; i < 26; i++){
            if( (lowerChar & (1 << i)) && (upperChar & (1 << i)) ) specialChar++; 
        }

        return specialChar; 
    }
};


// T.C. = O(n) + O(26) = O(n) 
// S.C. = O(1) 

// Here, n = the length of input string named "word" 