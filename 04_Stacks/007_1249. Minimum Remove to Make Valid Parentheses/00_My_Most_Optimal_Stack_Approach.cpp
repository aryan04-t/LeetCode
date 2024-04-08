// LeetCode (1249. Minimum Remove to Make Valid Parentheses): 
// https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/ 


#include<iostream> 
#include<string> 
#include<stack> 
using namespace std; 


class Solution {
public:
    string minRemoveToMakeValid(string s) {
        
        std::ios_base::sync_with_stdio(0);
        cin.tie(0);
        
        stack<int> st;
        int n = s.length(); 

        for(int i=0; i < n; i++){
            
            if(s[i] == '(') st.push(i); 

            if(st.empty()){
                if(s[i] == ')') s[i] = '$'; 
            }
            else{
                if(s[i] == ')') st.pop(); 
            }
        }

        while(!st.empty()){
            s[st.top()] = '$'; 
            st.pop(); 
        }

        string ans = "";

        for(char c : s){
            if(c != '$') ans.push_back(c); 
        }

        return ans;
    }
};


// T.C. = O(n) + O(n) + O(n) = O(3n) = O(n) 
// S.C. = O(n) 

// Here, n = the length of the input string "s" 