// LeetCode (2390. Removing Stars From a String): 
// https://leetcode.com/problems/removing-stars-from-a-string 


#include<string> 
#include<stack> 
#include<algorithm> 
using namespace std; 


class Solution {
public: 

    string removeStars(string s) {
        
        stack<char> st; 

        for (char ch : s) {
            if (ch != '*') st.push(ch); 
            else st.pop(); 
        }

        string ans = ""; 

        while (!st.empty()) {
            char ch = st.top();
            st.pop(); 
            ans += ch; 
        }

        reverse(ans.begin(), ans.end()); 

        return ans; 
    }
}; 


// T.C. = O(n) + O(n) + O(n/2) = O(5n/2) = O(n) 
// S.C. = O(n) + O(n) = O(2n) = O(n)

// Here, n = the length of input string named "s" 