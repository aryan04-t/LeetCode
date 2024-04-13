// LeetCode (1544. Make The String Great): 
// https://leetcode.com/problems/make-the-string-great/ 


#include<string> 
#include<stack> 
#include<cstdlib> 
using namespace std; 


class Solution {
public:

    string makeGood(string s) {

        int n = s.length(); 
        if(n == 1) return s; 

        stack<char> st; 

        for(int i=0; i < n; i++){
            if(!st.empty() && abs(st.top() - s[i]) == 32){
                st.pop(); 
            }
            else{
                st.push(s[i]); 
            }
        }

        string ans = ""; 

        while(!st.empty()){
            ans.push_back(st.top()); 
            st.pop(); 
        }

        reverse(ans.begin(), ans.end()); 

        return ans; 
    }
};


// T.C. = O(n) + O(n) + O(n/2) = O(n) 
// S.C. = O(n) + O(n) = O(n) 

// Here, n = the length of the input string named "s" 