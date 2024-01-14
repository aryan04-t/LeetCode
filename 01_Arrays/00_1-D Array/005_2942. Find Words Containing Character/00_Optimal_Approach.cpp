// LeetCode (2942. Find Words Containing Character): 
// https://leetcode.com/problems/find-words-containing-character/ 


#include<vector>
#include<string>
using namespace std;


class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        
        int n = words.size();
        vector<int> ans;

        for(int i=0; i < n; i++){
            for(int j=0; j < words[i].length(); j++){
                if(words[i][j] == x){
                    ans.push_back(i);
                    break;
                }
            }
        }

        return ans;
    }
};


// T.C. = O(n*m) 
// S.C. = O(n) 

// Here, n = number of elements which are present in input vector named "words", and m = average length of strings inside the input vector named "words" 