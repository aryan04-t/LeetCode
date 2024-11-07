// LeetCode (49. Group Anagrams): 
// https://leetcode.com/problems/group-anagrams/ 


#include<vector> 
#include<string> 
#include<unordered_map> 
using namespace std;


class Solution {
public:

    string getSignature(const string &s){

        int m = s.length(); 
        vector<int> charFreq(26, 0); 

        for(int i=0; i < m; i++){
            charFreq[s[i] - 'a']++;
        }

        string sign; 

        for(int i=0; i < 26; i++){
            if(charFreq[i] != 0){
                sign.push_back( char(i + 'a') ); 
                sign += to_string(charFreq[i]);
            }
        }

        return sign; 
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> mp; 

        for(string &s : strs){
            mp[getSignature(s)].push_back(s); 
        }

        vector<vector<string>> ans; 

        for(const pair<string, vector<string>> &p : mp){
            ans.push_back(p.second); 
        }

        return ans; 
    }
}; 


// T.C. = O(n*k) + O(l) = O(n*k) 
// S.C. = O(26) + O(n*k) + O(n*k) = O(n*k) 

// Here, n = the total number of strings which are present inside the input vector named "strs", and k = the average length of all the strings which are present inside the input vector named "strs", and l = the total number of unique anagram signatures which are created 