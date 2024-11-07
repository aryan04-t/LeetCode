// LeetCode (506. Relative Ranks): 
// https://leetcode.com/problems/relative-ranks/ 


#include<vector> 
#include<queue> 
#include<string> 
using namespace std; 


class Solution {
public:

    vector<string> findRelativeRanks(vector<int>& score) {
        
        int n = score.size(); 

        priority_queue<pair<int, int>> maxHeap; 
        
        for(int i=0; i < n; i++){
            maxHeap.push({score[i], i}); 
        } 

        vector<string> ans(n, ""); 

        int rank = 1;
        while(!maxHeap.empty()){ 

            pair<int, int> p = maxHeap.top(); 
            maxHeap.pop(); 

            if(rank == 1) ans[p.second] = "Gold Medal"; 
            else if(rank == 2) ans[p.second] = "Silver Medal"; 
            else if(rank == 3) ans[p.second] = "Bronze Medal"; 
            else ans[p.second] = to_string(rank); 

            rank++; 
        }

        return ans; 
    }
};


// T.C. = O(n * log(n)) + O(n) + O(n * log(n)) = O(n * log(n)) 
// S.C. = O(n) + O(n) = O(2n) = O(n) 

// Here, n = the total number of integers which are present inside the input vector named "score" 