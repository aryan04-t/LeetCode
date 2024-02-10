// LeetCode (151. Reverse Words in a String): 
// https://leetcode.com/problems/reverse-words-in-a-string/ 


#include<string>
#include<stack>
#include<sstream> 
using namespace std;


class Solution {
public:

    string reverseWords(string s) {
        
        stringstream sso;
        sso << s;

        stack<string> st;

        string word;
        while(sso >> word){
            st.push(word);
        }

        string ans;
        while(!st.empty()){
            ans += st.top();
            st.pop();
            ans.push_back(' ');
        }

        ans.pop_back();
        return ans;

    }
};


// T.C. = O(n) 
// S.C. = O(n) -> (This is space complexity is caused due to stack, and I am not considering "ans" string's space complexity here, although here the S.C. will stil stay O(n) even if I consider it, but still I am not considering it, and I am writing it here just for the record) 

// Here, n = the length of input string "s" 