// LeetCode (2593. Find Score of an Array After Marking All Elements): 
// https://leetcode.com/problems/find-score-of-an-array-after-marking-all-elements 


#include<vector> 
#include<queue> 
#include<utility> 
#include<functional> 
using namespace std; 


class Solution {
public: 

    long long findScore(vector<int>& nums) {
        
        long long score = 0; 
        int n = nums.size(); 

        vector<bool> markedElements(n, false); 
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap; 

        for (int i=0; i < n; i++) {
            minHeap.push({nums[i], i}); 
        }

        while (!minHeap.empty()) {
            const pair<int, int> p = minHeap.top(); 
            minHeap.pop(); 
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


// T.C. = O(n*log(n)) + O(n*log(n)) = O(2*n*log(n)) = O(n*log(n)) 
// S.C. = O(n) + O(n) = O(2n) = O(n) 

// Here, n = the length of 1-D input vector named "nums" 