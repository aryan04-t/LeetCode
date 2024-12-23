// LeetCode (387. First Unique Character in a String): 
// https://leetcode.com/problems/first-unique-character-in-a-string/ 


#include<string> 
#include<unordered_map> 
using namespace std; 


class Solution {
public:
    int firstUniqChar(string s) {
        
        unordered_map<char, int> mp;

        int n = s.length();

        for(int i=0; i < n; i++){
            mp[s[i]]++;
        }

        for(int i=0; i < n; i++){
            if(mp[s[i]] == 1){
                return i;
            }
        }

        return -1;
    }
};


// T.C. = O(n) + O(n) = O(2n) = O(n) 
// S.C. = O(1) 

// Here, n = length of input string named "s" 