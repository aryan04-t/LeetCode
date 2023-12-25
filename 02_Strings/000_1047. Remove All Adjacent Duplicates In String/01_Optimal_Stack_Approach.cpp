// LeetCode (Remove All Adjacent Duplicates In String):
// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/ 


#include<string> 
using namespace std; 

class Solution {
public:
    string removeDuplicates(string s) {

        string ans;
        int i=0;

        while(i < s.length()){
            if(ans.empty()){
                ans.push_back(s[i]);
            }
            else{
                if(ans[ans.length()-1] == s[i]){
                    ans.pop_back();
                }
                else{
                    ans.push_back(s[i]);
                }
            }
            i++;
        }

        return ans;
    }
};


// T.C. = O(n) 
// -> While loop is traversing the whole input string named "s" 

// S.C. = O(n) 
// -> If all the adjacent elements are non-duplicates, then all of them will get pushed to "ans" stack 

// Here, n = length of input string named "s" 