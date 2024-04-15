// LeetCode (3114. Latest Time You Can Obtain After Replacing Characters): 
// https://leetcode.com/problems/latest-time-you-can-obtain-after-replacing-characters/ 


#include<string> 
using namespace std; 


class Solution {
public:

    string findLatestTime(string s) {
        
        if(s[0] == '?'){
            if(s[1] == '?'){
                s[0] = '1'; 
            }
            else if(s[1] > '1'){
                s[0] = '0'; 
            }
            else{
                s[0] = '1'; 
            }
        }
        if(s[1] == '?'){
            if(s[0] == '0'){
                s[1] = '9'; 
            }
            else{
                s[1] = '1'; 
            } 
        }
        
        if(s[3] == '?') s[3] = '5'; 
        if(s[4] == '?') s[4] = '9'; 

        return s;
    }
};


// T.C. = O(n) = O(5) = O(1) 
// S.C. = O(1) 

// Here, n = the length of input string named "s" = 5 