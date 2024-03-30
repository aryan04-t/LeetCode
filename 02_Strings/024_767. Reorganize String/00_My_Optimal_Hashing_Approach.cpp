// LeetCode (767. Reorganize String): 
// https://leetcode.com/problems/reorganize-string/ 


#include<string> 
#include<vector> 
#include<algorithm> 
using namespace std; 


class Solution {
public:

    string reorganizeString(string s) {
        
        int n = s.length(); 
        vector<int> charFreq(26, 0); 
        int maxFreq = 0; 
        
        for(int i=0; i < n; i++){
            charFreq[s[i] - 'a']++; 
            maxFreq = max( maxFreq, charFreq[s[i] - 'a'] ); 
        }

        if(n & 1){
            if( maxFreq > ((n / 2) + 1) ){
                return "";
            }
        }
        else{
            if(maxFreq > n/2){
                return ""; 
            }
        }

        string ans(n, ' '); 
        int done = 0;

        int even = 0;
        int odd = 1; 

        while(done != n){
            
            maxFreq = 0; 
            char currChar;  
            
            for(int i=0; i < 26; i++){
                int currFreq = charFreq[i]; 
                if(currFreq > maxFreq){
                    maxFreq = currFreq;
                    currChar = char(i + 'a'); 
                }
            }

            while(even < n && maxFreq != 0){

                ans[even] = currChar;
                maxFreq--; 

                even += 2;
                done++;
            }


            while(odd < n && maxFreq != 0){

                ans[odd] = currChar;
                maxFreq--; 

                odd += 2;
                done++; 
            }

            charFreq[currChar - 'a'] = 0;
        }

        return ans; 
    }
};


// T.C. = O(n) + O(n) = O(2n) = O(n) 
// S.C. = O(26) + O(n) = O(1) + O(n) = O(n) 

// Here, n = the length of input string named "s" 