// LeetCode (3718. Smallest Missing Multiple of K) 
// https://leetcode.com/problems/smallest-missing-multiple-of-k 


#include<vector>
#include<queue>
using namespace std;


class Solution {
public:

    int missingMultiple(vector<int>& nums, int k) {
        
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (int val : nums) minHeap.push(val);

        int missingMultiple = k;
        
        while (!minHeap.empty()) {
            int val = minHeap.top(); 
            minHeap.pop();
            if (val == missingMultiple) {
                missingMultiple += k;
            }
        }

        return missingMultiple;
    }
};


// T.C. = O(n*log(n)) + O(n*log(n)) = (2*n*log(n)) = O(n*log(n)) 
// S.C. = O(n) 

// Here, n = the length of input vector named "nums" 