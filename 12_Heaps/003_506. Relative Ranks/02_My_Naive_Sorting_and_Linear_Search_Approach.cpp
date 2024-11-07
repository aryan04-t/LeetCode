// LeetCode (506. Relative Ranks): 
// https://leetcode.com/problems/relative-ranks/ 


#include<vector> 
#include<string> 
#include<algorithm> 
using namespace std; 


class Solution {
public:

    int findIndex(int val, vector<int> &score){

        int n = score.size(); 

        for(int i=0; i < n; i++){
            if(score[i] == val) return i;
        }

        return -1;
    }

    vector<string> findRelativeRanks(vector<int>& score) {
        
        int n = score.size(); 

        vector<int> copyVector(n, 0); 
        for(int i=0; i < n; i++) copyVector[i] = score[i]; 

        sort(copyVector.begin(), copyVector.end(), greater<int>()); 

        vector<string> ans(n, ""); 
        int rank = 1; 

        for(int val : copyVector){
            int i = findIndex(val, score); 
            if(rank == 1) ans[i] = "Gold Medal"; 
            else if(rank == 2) ans[i] = "Silver Medal"; 
            else if(rank == 3) ans[i] = "Bronze Medal"; 
            else ans[i] = to_string(rank); 
            rank++;
        }

        return ans; 
    }
};


// T.C. = O(n) + O(n) + O(n * log(n)) + O(n) + O((n * (n+1))/2) = O(3n) + O(n * log(n)) + O(n^2) = O(n^2) 
// S.C. = O(n) + O(log(n)) + O(n) = O(n) 

// Here, n = the total number of integers which are present inside the input vector named "score" 