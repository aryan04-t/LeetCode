// LeetCode (345. Reverse Vowels of a String): 
// https://leetcode.com/problems/reverse-vowels-of-a-string/ 


#include<vector> 
#include<string> 
#include<utility> 
using namespace std; 


class Solution {
public:

    bool isVowel(const char &ch){

        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
            return true; 
        } 

        if(ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U'){
            return true; 
        }

        return false; 

    }

    string reverseVowels(string s) {

        int n = s.length();

        vector<pair<char, int>> vowels;

        for(int i=0; i < n; i++){
            if(isVowel(s[i])){
                vowels.push_back({s[i], i});
            }
        }

        int m = vowels.size();

        int i = 0; 
        int j = m-1; 

        while(i < j){
            
            char temp = vowels[i].first; 
            vowels[i].first = vowels[j].first; 
            vowels[j].first = temp;
        
            i++;
            j--;
            
        }

        for(const pair<char, int> &val : vowels){
            s[val.second] = val.first; 
        }

        return s;

    }

};


// T.C. = O(n) + O(m/2) + O(m) = O(n) 
// S.C. = O(m) 

// Here, n = the length of input string named "s", and m = the total number of vowels which are present inside the input string named "s" 