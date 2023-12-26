// LeetCode (1047. Remove All Adjacent Duplicates In String):
// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/ 


#include<string> 
using namespace std; 

class Solution {
public:
    string removeDuplicates(string s) {

        int i=0;

        for(int j=0; j < s.length(); j++, i++){
            s[i] = s[j];
            if( (i > 0) && (s[i] == s[i-1]) ){
                i -= 2;
            }
        }        

        return s.substr(0, i);
    }
};


// T.C. = O(n) + O(i) = O(n) 
// -> (traversing the whole string) + (t.c. of func. substr) 

// S.C. = O(1) 
// -> No extra space proportional to the size of input string "s" is getting used 

// Here, n = length of input string named "s", and i = length of substring 