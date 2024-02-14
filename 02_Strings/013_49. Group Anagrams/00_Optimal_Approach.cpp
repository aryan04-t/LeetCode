// LeetCode (49. Group Anagrams): 
// https://leetcode.com/problems/group-anagrams/ 


#include<vector> 
#include<string> 
#include<unordered_map> 
using namespace std;


class Solution {
public:
    
    string getSignature(const string& s){

        vector<int> count(26, 0);

        for(char c : s){
            count[c - 'a']++;
        }

        string signature;

        for(int i=0; i < 26; i++){ 
            signature.push_back(char(i + 'a')); 
            signature.push_back(char(count[i] + '0')); 
        } 

        return signature;

    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        vector<vector<string>> result;
        unordered_map<string, vector<string>> groups; 

        for(const string& s : strs){
            groups[getSignature(s)].push_back(s);
        }

        for(const pair<string, vector<string>>& oneGroup : groups){

            result.push_back(oneGroup.second);

        }

        return result;

    }

};


// T.C. = 
// S.C. = 