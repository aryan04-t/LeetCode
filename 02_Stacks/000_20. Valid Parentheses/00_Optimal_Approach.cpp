// LeetCode (20. Valid Parentheses): 
// https://leetcode.com/problems/valid-parentheses/ 


#include<string>
#include<stack>
using namespace std; 


class Solution {
public:
    bool isValid(string s) {

        int stringLen = s.length();

        if( (stringLen % 2) == 1 ) return false;

        stack<char> st;

        for(int i=0; i < stringLen; i++){
            if(s[i] == '{' || s[i] == '[' || s[i] == '('){
                st.push(s[i]);
            }
            else{
                if(!st.empty()){
                    if(st.top() == '{' && s[i] == '}'){
                        st.pop();
                    }
                    else if(st.top() == '[' && s[i] == ']'){
                        st.pop();
                    }
                    else if(st.top() == '(' && s[i] == ')'){
                        st.pop();
                    }
                    else{
                        return false;
                    }
                }
                else{
                    return false;
                }
            }
        }

        return (st.empty()) ? true : false;

    }
};


// T.C.: O(n) 
// S.C.: O(n/2) = O(n) 

// Here, n = length of input string named "s" 