// LeetCode (205. Isomorphic Strings): 
// https://leetcode.com/problems/isomorphic-strings/ 


#include<vector> 
#include<unordered_map> 
using namespace std;


class Solution {
public:

    bool isIsomorphic(string s, string t) {
        
        int n = s.length();
        
        unordered_map<char, char> mp;
        vector<bool> charHasBeenMapped(128, false);

        for(int i=0; i < n; i++){

            if(mp.find(s[i]) == mp.end()){

                if(!charHasBeenMapped[t[i]]){
                    mp[s[i]] = t[i];
                    charHasBeenMapped[t[i]] = true;
                }
                else{
                    return false;
                }

            }
            else{

                if(mp[s[i]] != t[i]){
                    return false;
                }
                
            }
        }

        return true;

    }
};


// T.C. = O(n) 
// S.C. = O(n) + O(128) = O(n) + O(1) = O(n) 

// Here, n = the length of input string "s" = the length of input string "t" 