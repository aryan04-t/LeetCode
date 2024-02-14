// LeetCode (345. Reverse Vowels of a String): 
// https://leetcode.com/problems/reverse-vowels-of-a-string/ 


#include<vector> 
#include<string> 
#include<utility> 
using namespace std; 


class Solution {
public:

    bool isVowel(const char& c){

        if(c == 'a' || c == 'e' || c == 'i' || c =='o' || c == 'u'){
            return true;
        }

        if(c == 'A' || c == 'E' || c == 'I' || c =='O' || c == 'U'){
            return true;
        }

        return false;

    }

    string reverseVowels(string s) {
        
        vector<pair<char, int>> vowels; 

        int n = s.length();

        for(int i=0; i < n; i++){
            if(isVowel(s[i])){
                vowels.push_back({s[i], i});
            }
        }

        int m = vowels.size();
        int start = 0;
        int end = m-1;

        while(start < end){

            char temp = vowels[start].first;
            vowels[start].first = vowels[end].first;
            vowels[end].first = temp;

            start++;
            end--;

        }

        for(int i=0; i < m; i++){
            s[vowels[i].second] = vowels[i].first;
        }

        return s;
        
    }
};


// T.C. = O(n) + O(m/2) + O(m) = O(n) 
// S.C. = O(m) 

// Here, n = the length of input string named "s", and m = total number of vowels which are present inside the input string "s"