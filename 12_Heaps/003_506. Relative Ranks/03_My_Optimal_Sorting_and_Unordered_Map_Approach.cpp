// LeetCode (506. Relative Ranks): 
// https://leetcode.com/problems/relative-ranks/ 


#include<vector> 
#include<string> 
#include<unordered_map> 
#include<algorithm> 
using namespace std; 


class Solution {
public:

    vector<string> findRelativeRanks(vector<int>& score) {
        
        int n = score.size(); 

        unordered_map<int, int> mp; 
        for(int i=0; i < n; i++) mp[score[i]] = i; 

        sort(score.begin(), score.end(), greater<int>()); 

        vector<string> ans(n, ""); 
        int rank = 1; 

        for(int val : score){
            int i = mp[val]; 
            if(rank == 1) ans[i] = "Gold Medal"; 
            else if(rank == 2) ans[i] = "Silver Medal"; 
            else if(rank == 3) ans[i] = "Bronze Medal"; 
            else ans[i] = to_string(rank); 
            rank++;
        }

        return ans; 
    }
};


// T.C. = O(n) + O(n * log(n)) + O(n) + O(n) = O(3n) + O(n * log(n)) = O(n * log(n)) 
// S.C. = O(n) + O(log(n)) + O(n) = O(n) 

// Here, n = the total number of integers which are present inside the input vector named "score" 