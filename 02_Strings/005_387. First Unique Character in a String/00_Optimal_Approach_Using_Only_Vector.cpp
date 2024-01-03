#include<iostream> 
#include<vector> 
using namespace std; 


class Solution {
public:
    int firstUniqChar(string s) {
        
        int n = s.length();

        vector<int> charFreqCount(26, 0);
        
        for(char ch : s){
            charFreqCount[ch - 'a']++; 
        }

        for(int i = 0; i < n; i++){
            if(charFreqCount[s[i] - 'a'] == 1){
                return i;
            }
        }

        return -1; 
    }
}; 


// T.C. = O(n) + O(n) = O(2n) = O(n) 
// S.C. = O(1) 

// Here, n = number of elements present inside the input vector named "nums" 