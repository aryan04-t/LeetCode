// LeetCode (647. Palindromic Substrings): 
// https://leetcode.com/problems/palindromic-substrings/description/ 


#include<string>
using namespace std;


class Solution {
public:

    int countSubstrings(string s) {
        
        int count = 0;

        int k = 0;

        // Finding Odd Length Palindromic Substrings 
        while(k < s.length()){
            int i = k;
            int j = k;
            while(i >= 0 && j < s.length()){
                if(s[i] == s[j]){
                    count++;
                }
                else{
                    break;
                }
                i--;
                j++;
            }
            k++;
        }

        k = 0;

        // Finding Even Length Palindromic Substrings 
        while(k < s.length()){
            int i = k;
            int j = k+1;
            while(i >= 0 && j < s.length()){
                if(s[i] == s[j]){
                    count++;
                }
                else{
                    break;
                }
                i--;
                j++;
            }
            k++;
        }

        return count;
    }
};


// T.C. = O(n * (n/2)) + O(n * (n/2)) = O(n^2) 

// S.C. = O(1) 

// Here, n = length of input string named 's' 