// LeetCode (28. Find the Index of the First Occurrence in a String): 
// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/ 


#include<string> 
using namespace std; 


class Solution {
public:

    int strStr(string haystack, string needle) {

        int found = haystack.find(needle); 
        if(found == string::npos){
            return -1; 
        } 
        return found; 

    }
};


// T.C. = O(n*m) 
// S.C. = O(1) 

// Here, n = the length of input string named "haystack", and m = the length of input string named "needle" 