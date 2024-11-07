// LeetCode (917. Reverse Only Letters): 
// https://leetcode.com/problems/reverse-only-letters/ 


#include<string> 
using namespace std; 


class Solution {
public:

    bool isLower(const char &c){
        if(c >= 'a' && c <='z') return true;
        return false; 
    }

    bool isUpper(const char &c){
        if(c >= 'A' && c <='Z') return true;
        return false; 
    }

    string reverseOnlyLetters(string s) {
        
        int n = s.length(); 

        int i = 0;
        int j = n - 1;

        while(i < j){
            
            while( i < j && !(isLower(s[i]) || isUpper(s[i])) ) i++; 
            while( i < j  && !(isLower(s[j]) || isUpper(s[j])) ) j--; 

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

// Here, n = the length of input string named "s" 