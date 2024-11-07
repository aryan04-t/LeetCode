// LeetCode (3016. Minimum Number of Pushes to Type Word II): 
// https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-ii/ 


#include<string> 
#include<vector> 
#include<unordered_map> 
using namespace std; 


class Solution {
public:
    int minimumPushes(string word) {
        
        vector<int> charFreq(26, 0); 
        for(char ch :  word){
            charFreq[ch - 'a']++; 
        }

        int pushCount = 1; 
        int canHaveCurrPushCount = 8; 
        unordered_map<char, int> pushCountMap; 

        while(true){
            
            int maxFreq = 0;
            int maxFreqIndex = -1; 
            
            for(int i=0; i < 26; i++){
                int currFreq = charFreq[i]; 
                if(currFreq > maxFreq){
                    maxFreq = currFreq; 
                    maxFreqIndex = i; 
                }
            }
            
            if(maxFreqIndex == -1) break; 
            
            charFreq[maxFreqIndex] = 0; 
            pushCountMap[char(maxFreqIndex + 'a')] = pushCount; 
            canHaveCurrPushCount--;

            if(canHaveCurrPushCount == 0){
                pushCount++; 
                canHaveCurrPushCount = 8; 
            }
        }

        int totalPushes = 0; 
        for(char ch : word){
            totalPushes += pushCountMap[ch]; 
        }

        return totalPushes; 
    }
};


// T.C. = O(n) 
// S.C. = O(n) 

// Here, n = the length of input string named "word" 