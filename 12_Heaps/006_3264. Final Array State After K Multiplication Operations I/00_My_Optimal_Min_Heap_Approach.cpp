// LeetCode (3264. Final Array State After K Multiplication Operations I): 
// https://leetcode.com/problems/final-array-state-after-k-multiplication-operations-i 


#include<vector> 
#include<queue> 
using namespace std; 


class Solution {
public:

    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {

        int n = nums.size(); 

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap; 

        for (int i=0; i < n; i++) {
            minHeap.push({nums[i], i}); 
        }

        while (k--) {
            pair<int, int> p = minHeap.top(); 
            minHeap.pop(); 
            p.first = p.first * multiplier; 
            minHeap.push(p); 
        }

        while (!minHeap.empty()) {
            pair<int, int> p = minHeap.top(); 
            minHeap.pop(); 
            nums[p.second] = p.first; 
        }

        return nums; 
    }
};


// T.C. = O(n*log(n)) + O(k*(log(n) + log(n))) + O(n*log(n)) = O(max(n*log(n), k*log(n))) 
// S.C. = O(n) 

// Here, n = the length of input 1-D vector named "nums" 