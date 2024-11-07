// LeetCode (647. Palindromic Substrings): 
// https://leetcode.com/problems/palindromic-substrings/ 


#include<string>
using namespace std;


class Solution {
public:
    bool checkPalindrome(string s){
        int i = 0;
        int j = s.length() - 1;

        while(i <= j){
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }

        return true;
    }

    int countSubstrings(string s) {
        
        int count = 0;

        for(int i=0; i < s.length(); i++){
            for(int j=1; j <= s.length()-i; j++){
                count = count + checkPalindrome(s.substr(i,j));
            }
        }

        return count;
    }
};


// T.C. = O(n^3/2) = O(n^3) 
// -> O(n^2) t.c. because of nested loops which iterate on the input string named 's' and * O(n/2) is the worst case time complexity of checkPalindrome() function. 
// --> and here in the time complexity of checkPalindrome() function the time complexity is dependent on length of substring, but in worst case length of substring equals to length of input string, that's why it's t.c. is O(n/2) 

// S.C. = O(1) 

// Here, n = length of input string named 's' 