// LeetCode (2182. Construct String With Repeat Limit): 
// https://leetcode.com/problems/construct-string-with-repeat-limit 


#include<vector> 
#include<string> 
#include<queue> 
#include<utility> 
using namespace std; 


class Solution {
public: 

    string repeatLimitedString(string s, int repeatLimit) {
        
        int n = s.length(); 
        vector<int> charFreqHash(26, 0); 

        for (char ch : s) {
            charFreqHash[ch - 'a']++; 
        }

        priority_queue<pair<int, int>> maxHeap; 
        string repeatLimitedString = ""; 

        for (int i=0; i < 26; i++) {
            if (charFreqHash[i] != 0) {
                maxHeap.push({i, charFreqHash[i]}); 
            }
        }

        while (!maxHeap.empty()) {
            
            pair<int, int> p1 = maxHeap.top(); 
            maxHeap.pop(); 
            
            int j1 = 0; 
            while (p1.second > 0 && j1 != repeatLimit) {
                repeatLimitedString += char(p1.first + 'a'); 
                p1.second--; 
                j1++; 
            }

            if (p1.second == 0) continue; 
            else { 
                if (maxHeap.empty()) break; 
                else { 
                    pair<int, int> p2 = maxHeap.top(); 
                    maxHeap.pop(); 
                    
                    repeatLimitedString += char(p2.first + 'a'); 
                    p2.second--; 

                    if (p2.second > 0) maxHeap.push(p2); 
                } 
                maxHeap.push(p1); 
            } 
        }

        return repeatLimitedString; 
    }
}; 


// T.C. = O(n) + O(26*log(26)) + O(k*log(26)) + O(n) = O(2n) + O(k) + O(26) = O(n+k) 
// S.C. = O(26) + O(26) + O(n) = O(n) 

// Here, n = the length of input string named "s", and k = summation of (charFreqHash[i]/repeatLimit) where i is in the range [0, 25] 