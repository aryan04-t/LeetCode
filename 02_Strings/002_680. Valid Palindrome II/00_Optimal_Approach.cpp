// LeetCode (680. Valid Palindrome II):
// https://leetcode.com/problems/valid-palindrome-ii/ 


#include<string>
using namespace std;

class Solution {
public:

    bool checkPalindrome(string& s, int i, int j){

        while(i <= j){
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }

        return true;
    }

    bool validPalindrome(string s) {
        
        int i = 0; 
        int j = s.length()-1; 

        while(i <= j){
            if(s[i] == s[j]){
                i++;
                j--;
            }
            else{
                return checkPalindrome(s, i, j-1) || checkPalindrome(s, i+1, j);
            }
        }

        return true;
    }
}; 


// T.C. = O(n) 
// S.C. = O(1) 

// Here, n = length of input string named "s" 