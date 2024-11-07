// LeetCode (1544. Make The String Great): 
// https://leetcode.com/problems/make-the-string-great/ 


#include<string> 
#include<cctype> 
using namespace std; 


class Solution {
public:

    string makeGood(string s) {
        
        int n = s.length(); 
        bool done = false;

        while(!done){

            int i=0; 
            n = s.length(); 
            bool reIterate = false;

            while(i < n-1){

                if(islower(s[i]) && isupper(s[i+1]) && s[i] == tolower(s[i+1])){
                    s.erase(i, 2);
                    reIterate = true; 
                }
                else if(isupper(s[i]) && islower(s[i+1]) && s[i] == toupper(s[i+1])){
                    s.erase(i, 2); 
                    reIterate = true; 
                }

                if(reIterate){
                    break; 
                }

                i++; 
            }

            if(s.length() == 0) done = true; 
            if(i == n-1) done = true;
        }

        return s; 
    }
};


// T.C. = O(n^2) 
// S.C. = O(1) 

// Here, n = the length of input string named "s" 