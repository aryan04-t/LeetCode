// LeetCode (3121. Count the Number of Special Characters II): 
// https://leetcode.com/problems/count-the-number-of-special-characters-ii/ 


#include<vector> 
#include<string> 
#include<cctype>
using namespace std; 

class Solution {
public:

    int numberOfSpecialChars(string word) {

        vector<int> lowerCase(26, -1);
        vector<int> upperCase(26, -1);

        int n = word.length(); 

        for(int i=0; i < n; i++){
            if(islower(word[i])) lowerCase[word[i] - 'a'] = i; 
            else if(isupper(word[i])){
                if(upperCase[word[i] - 'A'] == -1){
                    upperCase[word[i] - 'A'] = i; 
                }
            } 
        }

        int specialChar = 0; 
        for(int i=0; i < 26; i++){
            if(lowerCase[i] != -1 && lowerCase[i] < upperCase[i]){
                specialChar++;
            }
        }

        return specialChar; 
    }
};


// T.C. = O(n) + O(26) = O(n) 
// S.C. = O(26) + O(26) = O(1) 

// Here, n = the length of the input string named "word" 