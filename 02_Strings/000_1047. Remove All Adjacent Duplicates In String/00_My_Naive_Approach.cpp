// LeetCode (1047. Remove All Adjacent Duplicates In String):
// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/ 


#include<string> 
using namespace std; 

class Solution {
public:
    string removeDuplicates(string s) {

        int s_len = s.length();

        for(int i=0; i < s_len-1; i++){
            if(s[i] == s[i+1]){
                s.erase(i, 2);
                s_len = s.length();
                i = -1;
            }
        }

        return s;   
    }
};

 
// T.C. = O(n/2) * ( O(n) + O(1) ) = O(n^2) 
// -> (worst case for loop iterations) + ( (erase t.c.) + (length func. t.c.) ) 

// S.C. = O(1) 

// Here, n = length of input string named "s" 