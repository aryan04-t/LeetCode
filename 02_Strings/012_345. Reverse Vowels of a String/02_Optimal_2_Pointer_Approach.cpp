// LeetCode (345. Reverse Vowels of a String): 
// https://leetcode.com/problems/reverse-vowels-of-a-string/ 


#include<vector> 
#include<string> 
#include<utility> 
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

        string ans = s; 
        int n = s.length();

        int i = 0; 
        int j = n-1; 

        while(i < j){
            
            while( i < j && !isVowel(ans[i]) ){
                i++;
            }

            while( i < j && !isVowel(ans[j]) ){
                j--;
            }

            if( i < j && isVowel(ans[i]) && isVowel(ans[j]) ){
                
                char temp = ans[i];
                ans[i] = ans[j];
                ans[j] = temp;

                i++;
                j--;

            }

        }

        return ans;

    }
};


// T.C. = O(n) 
// S.C. = O(n) 

// Here, n = the total length of input string named "s" 