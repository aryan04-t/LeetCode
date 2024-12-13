// LeetCode (2593. Find Score of an Array After Marking All Elements): 
// https://leetcode.com/problems/find-score-of-an-array-after-marking-all-elements 


#include<vector> 
#include<algorithm> 
#include<utility> 
using namespace std; 


class Solution {
public:

    long long findScore(vector<int>& nums) {
        
        long long score = 0; 
        int n = nums.size(); 

        vector<bool> markedElements(n, false); 
        vector<pair<int, int>> numsValueIndexPairVec; 

        for (int i=0; i < n; i++) {
            numsValueIndexPairVec.push_back({nums[i], i}); 
        }

        sort(numsValueIndexPairVec.begin(), numsValueIndexPairVec.end()); 

        for (int i=0; i < n; i++) {
            const pair<int, int> &p = numsValueIndexPairVec[i]; 
            if (markedElements[p.second]) continue; 
            else {
                score += p.first; 
                markedElements[p.second] = true; 
                if ((p.second - 1) >= 0) markedElements[p.second - 1] = true; 
                if ((p.second + 1) < n) markedElements[p.second + 1] = true; 
            }
        }

        return score; 
    }
}; 


// T.C. = O(n) + O(n*log(n)) + O(n) = O(n*log(n)) 
// S.C. = O(n) + O(n) + O(log(n)) = O(n) 

// Here, n = the length of 1-D input vector named "nums" 