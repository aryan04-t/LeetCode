// LeetCode (387. First Unique Character in a String): 
// https://leetcode.com/problems/first-unique-character-in-a-string/ 


#include<string> 
#include<unordered_map> 
#include<queue> 
using namespace std; 


class Solution {
public:
    int firstUniqChar(string s) {
        
        int n = s.length();

        unordered_map<char, int> mp;
        
        queue<int> q;

        for(int i = 0; i < n; i++){
            mp[s[i]]++;
            if(mp[s[i]] == 1){
                q.push(i);
            }
        }

        while(!q.empty()){
            if(mp[s[q.front()]] > 1){
                q.pop();
            }
            else{ 
                return q.front();
            }
        }

        return -1; 
    }
};


// T.C. = O(n) + O(n) = O(2n) = O(n) 
// S.C. = O(1) + O(n) = O(n) 

// Here, n = length of input string named "s" 