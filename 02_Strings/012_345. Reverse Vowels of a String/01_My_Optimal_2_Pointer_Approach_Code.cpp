// LeetCode (345. Reverse Vowels of a String): 
// https://leetcode.com/problems/reverse-vowels-of-a-string/ 


#include<string> 
using namespace std; 


class Solution {
public:

    bool isVowel(const char &ch){

        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
            return true; 
        } 

        if(ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U'){
            return true; 
        }

        return false; 

    }

    string reverseVowels(string s) {

        int n = s.length(); 

        int i = 0; 
        int j = n-1; 

        while(i < j){
            while( i < j && !isVowel(s[i]) ) i++;
            while( i < j && !isVowel(s[j]) ) j--;

            char temp = s[i];
            s[i] = s[j];
            s[j] = temp;

            i++;
            j--;
        }

        return s;

    }
};


// T.C. = O(n) 
// S.C. = O(1) 

// Here, n = the total length of input string named "s" 