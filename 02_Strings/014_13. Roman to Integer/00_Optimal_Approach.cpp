// LeetCode (13. Roman to Integer): 
// https://leetcode.com/problems/roman-to-integer/ 


#include<string> 
#include<unordered_map> 
using namespace std; 


class Solution {
public: 

    int romanToInt(string s) {
        
        int n = s.length();

        unordered_map<char, int> mp; 

        mp['I'] = 1; 
        mp['V'] = 5; 
        mp['X'] = 10; 
        mp['L'] = 50; 
        mp['C'] = 100; 
        mp['D'] = 500; 
        mp['M'] = 1000; 

        int numVal = 0; 

        for(int i=0; i < n-1; i++){
            if(mp[s[i]] < mp[s[i+1]]){
                numVal -= mp[s[i]];
            }
            else{
                numVal += mp[s[i]];
            }
        }

        numVal += mp[s[n-1]];

        return numVal;

    }
};


// T.C. = O(n) 
// S.C. = O(1) 

// Here, n = length of intput string named "s" 