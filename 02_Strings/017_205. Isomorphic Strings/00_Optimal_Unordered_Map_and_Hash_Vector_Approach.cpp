// LeetCode (205. Isomorphic Strings): 
// https://leetcode.com/problems/isomorphic-strings/ 


#include<string> 
#include<vector> 
#include<unordered_map> 
using namespace std;


class Solution {
public:

    bool isIsomorphic(string s, string t) {

        int n = s.length(); 

        unordered_map<char, char> mp; 
        vector<bool> isMapped(128, false); 

        for(int i=0; i < n; i++){
            
            unordered_map<char, char>::iterator it = mp.find(s[i]); 

            if(it == mp.end()){
                if(  !isMapped[t[i]] ){
                    mp[s[i]] = t[i]; 
                    isMapped[t[i]] = true; 
                }
                else{
                    return false; 
                }
            }
            else if(it != mp.end()){
                if( mp[s[i]] == t[i] ){
                    continue;
                }
                else{
                    return false;
                }
            }
        }

        return true; 

    }
};


// T.C. = O(n) 
// S.C. = O(128) + O(128) = O(1) + O(1) = O(1) 

// Here, n = the length of the input string named "s" = the length of the input string named "t" 