// LeetCode (2779. Maximum Beauty of an Array After Applying Operation): 
// https://leetcode.com/problems/maximum-beauty-of-an-array-after-applying-operation 


#include<string> 
using namespace std; 


class Solution {
public:

    string interpret(string command) {
        
        int i = 0; 
        int n = command.length(); 
        
        string ans = ""; 

        while (i < n) {
            char currChar = command[i]; 
            if (currChar == 'G') {
                ans += 'G'; 
                i++; 
            }
            else if (currChar == '(') {
                char nextChar = command[i+1]; 
                if (nextChar == ')') {
                    ans += 'o'; 
                    i += 2;
                }
                else {
                    ans += "al"; 
                    i += 4; 
                }
            } 
        }

        return ans; 
    }
};


// T.C. = O(n) 
// S.C. = O(n) 

// Here, n = the total length of input string named "command" 