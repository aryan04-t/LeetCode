// LeetCode (917. Reverse Only Letters): 
// https://leetcode.com/problems/reverse-only-letters/ 


#include<string> 
#include<cctype> 
#include<algorithm> 
using namespace std; 


class Solution {
public:

    string reverseOnlyLetters(string s) {
        
        int n = s.length(); 

        int i = 0;
        int j = n - 1;

        while(i < j){
            if( isalpha(s[i]) && isalpha(s[j]) ){
                swap(s[i], s[j]);
                i++;
                j--;
            }
            else if( !isalpha(s[i]) ){
                i++;
            }
            // else if( !isalpha(s[j]) ){
            else{
                j--; 
            }
        }

        return s; 

    }
};


// T.C. = O(n) 
// S.C. = O(1) 

// Here, n = the length of input string named "s" 