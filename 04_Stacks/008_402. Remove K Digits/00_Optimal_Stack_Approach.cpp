// LeetCode (402. Remove K Digits): 
// https://leetcode.com/problems/remove-k-digits/ 


#include<string> 
#include<stack> 
using namespace std; 


class Solution {
public:

    string removeKdigits(string num, int k) {
        
        int n = num.length(); 
        if(n == k) return "0";

        stack<char> st; 

        for(char digit : num){
            while(k > 0 && !st.empty() && st.top() > digit){
                st.pop();
                k--; 
            }
            st.push(digit); 
        }

        while(k > 0 && !st.empty()){
            st.pop(); 
            k--; 
        }

        string ans = ""; 
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop(); 
        }

        reverse(ans.begin(), ans.end());

        int i = 0;
        int m = ans.length(); 
        while(i < m && ans[i] == '0') i++; 

        return (i == m) ? "0" : ans.substr(i, m-i); 

        /*
            Instead of processing the string on your own for 
            removing the leading zeroes, you can also use the 
            inbuilt function called "find_first_not_of()" 

            --> This function will give you the index of where 
            the first non-occurence of its passed argument occurs, 
            and if it doesn't exist in the string then string::npos
            is returned 

            size_t pos = ans.find_first_not_of('0'); 
            return (pos == string::npos) ? "0" : ans.substr(pos); 

            // This above substr function single parameter constructor 
            just takes a single input of index from where fetching of 
            substring has to start, and then it returns a substring from 
            there to the "end of string" 
        */
    }
};


// T.C. = O(n) + O(k) + O(n-k) + O((n-k)/2) + O(n-k) = O(n) 
// S.C. = O(n) + O(n-k) = O(n) 

// Here, n = the length of the input string named "num", and k is the value of input integer named "k" 