// LeetCode (345. Reverse Vowels of a String): 
// https://leetcode.com/problems/reverse-vowels-of-a-string/ 


#include<string> 
#include<cctype> 
#include<utility> 
using namespace std; 


class Solution {
public:

    bool isVowel(char ch){

        ch = tolower(ch);

        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
            return true; 
        }

        return false; 

    }

    string reverseVowels(string s) {

        int n = s.length(); 

        int i = 0; 
        int j = n-1; 

        while(i < j){
            if( isVowel(s[i]) && isVowel(s[j]) ){
                swap(s[i], s[j]);
                i++;
                j--;
            }
            else if( !isVowel(s[i]) ){
                i++;
            }
            // else if( !isVowel(s[j]) ){
            else{
                j--;
            }
        }

        return s;

    }
};


// T.C. = O(n) 
// S.C. = O(1) 

// Here, n = the total length of input string named "s" 