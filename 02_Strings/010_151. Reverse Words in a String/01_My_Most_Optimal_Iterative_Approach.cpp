// LeetCode (151. Reverse Words in a String): 
// https://leetcode.com/problems/reverse-words-in-a-string/ 


#include<string> 
using namespace std;


class Solution {
public:

    string reverseWords(string s) {
        
        int n = s.size();
        string ans;

        for(int i=n-1; i >=0; i--){
            if(s[i] == ' ') continue;
            else{
                int len = 0;
                int j = i;
                while(j >= 0 && s[j] != ' '){
                    len++;
                    j--;
                }
                string word = s.substr(j+1, len);
                ans += word;
                ans.push_back(' ');
                i = j;
            }
        }

        ans.pop_back();
        return ans;

    }
};


// T.C. = O(n) 
// S.C. = O(1) -> (I am not considering "ans" string's space complexity here) 

// Here, n = the length of input string "s" 