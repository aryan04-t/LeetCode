// LeetCode (2390. Removing Stars From a String): 
// https://leetcode.com/problems/removing-stars-from-a-string 


#include<string> 
#include<stack> 
using namespace std; 


class Solution {
public: 

    void buildAnsString (stack<char> &st, string &ans) {
        
        if (st.empty()) return; 

        char ch = st.top(); 
        st.pop(); 

        buildAnsString(st, ans);
    
        ans += ch; 
    }

    string removeStars(string s) {
        
        stack<char> st; 

        for (char ch : s) {
            if (ch != '*') st.push(ch); 
            else st.pop(); 
        }

        string ans = ""; 

        buildAnsString(st, ans); 

        return ans; 
    }
}; 


// T.C. = O(n) + O(n) = O(2n) = O(n) 
// S.C. = O(n) + O(n) + O(n) = O(3n) = O(n) -> Extra O(n) s.c. is caused by function call stack 

// Here, n = the length of input string named "s" 


/*

# Both 1st and 2nd code have same T.C. and S.C., but 1st Iterative ans string building approach has [Runtime: 4ms, Memory Usage: 29.7MB], and 2nd Recursive ans string building approach has [Runtime: 1040ms, Memory Usage: 58.1MB] 

* Why 2nd Code is Bad: 
    - Recursive calls introduce unnecessary overhead and extra memory usage for the call stack.
    - Scattered memory access disrupts CPU cache efficiency, leading to slower performance.
    - Adds complexity for a simple task, making it less practical in real-world scenarios.

* Why 1st Code is Good: 
    - Iterative approach avoids overhead and uses memory efficiently.
    - Sequential memory access aligns well with CPU caching for faster execution.
    - Simpler, more direct implementation with better real-world performance. 

*/