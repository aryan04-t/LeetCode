#include<string>
#include<vector> 
#include<queue>
using namespace std; 


class Solution {
public:
    int firstUniqChar(string s) {
        
        int n = s.length();

        vector<int> charFreqCount(26, 0);
        queue<int> q;

        for(int i=0; i < n; i++){
            charFreqCount[s[i] - 'a']++;
            if(charFreqCount[s[i] - 'a'] == 1){
                q.push(i);
            }
        }

        while(!q.empty()){
            if(charFreqCount[s[q.front()] - 'a'] > 1){
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