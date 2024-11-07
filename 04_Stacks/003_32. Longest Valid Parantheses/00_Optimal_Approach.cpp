// LeetCode (32. Longest Valid Parentheses): 
// https://leetcode.com/problems/longest-valid-parentheses/


#include<string> 
#include<stack> 
using namespace std; 


class Solution {
public:
    int longestValidParentheses(string s) {
        
        int stringLen = s.length();
        stack<int> st;
        st.push(-1);

        int maxLen = 0;

        for(int i=0; i < stringLen; i++){

            if(s[i] == '('){
                st.push(i);
            }
            else{
                st.pop();
                if(st.empty()){
                    st.push(i);
                }
                else{
                    int len = i - st.top();
                    maxLen = max(maxLen, len);
                }
            }

        }

        return maxLen;
    }
};


// T.C. = O(n) -> (Due to for loop which iterates over the whole input string once) 
// S.C. = O(n/2) = O(n) -> (Due to space occupied by stack in worst case scenario) 

// Here, n = length of input string named "s"