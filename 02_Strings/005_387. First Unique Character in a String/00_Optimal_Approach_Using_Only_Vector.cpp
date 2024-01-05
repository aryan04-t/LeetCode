// LeetCode (387. First Unique Character in a String): 
// https://leetcode.com/problems/first-unique-character-in-a-string/ 


#include<string>
#include<vector> 
using namespace std; 


class Solution {
public:
    int firstUniqChar(string s) {
        
        int n = s.length();

        vector<int> charFreqCount(26, 0);
        
        for(char ch : s){
            charFreqCount[ch - 'a']++; 
        }

        for(int i = 0; i < n; i++){
            if(charFreqCount[s[i] - 'a'] == 1){
                return i;
            }
        }

        return -1; 
    }
}; 


// T.C. = O(n) + O(n) = O(2n) = O(n) 
// S.C. = O(1) 

// Here, n = length of input string named "s" 