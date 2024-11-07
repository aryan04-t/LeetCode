// LeetCode (2114. Maximum Number of Words Found in Sentences): 
// https://leetcode.com/problems/maximum-number-of-words-found-in-sentences/ 


#include<vector> 
#include<string> 
#include<limits.h> 
using namespace std; 


class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {

        int n = sentences.size();        
        int maxi = INT_MIN;

        for(int i=0; i < n; i++){
            
            int sentenceLen = sentences[i].size();
            int wordCount = 0;

            for(int j=0; j < sentenceLen; j++){
                if(sentences[i][j] == ' '){
                    wordCount++;
                }
            }

            wordCount++;
            maxi = max(wordCount, maxi);
            
        }

        return maxi; 

    }
};


// T.C. = O(n*m) 
// S.C. = O(1) 

// Here, n = total number of sentences which are present inside the input vector named "sentences" 
// and m = average length of sentences which are present inside the input vector named "sentences" 