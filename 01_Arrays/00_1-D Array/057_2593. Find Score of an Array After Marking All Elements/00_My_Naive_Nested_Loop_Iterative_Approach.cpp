// LeetCode (2593. Find Score of an Array After Marking All Elements): 
// https://leetcode.com/problems/find-score-of-an-array-after-marking-all-elements 


#include<vector> 
using namespace std; 


class Solution {
public:

    long long findScore(vector<int>& nums) {
        
        long long score = 0; 
        int n = nums.size(); 
        vector<bool> markedElements(n, false); 

        for (int i=0; i < n; i++) {
            int mini = INT_MAX; 
            int miniIndex = -1; 
            for (int j=0; j < n; j++) { 
                if (!markedElements[j] && nums[j] < mini) { 
                    miniIndex = j; 
                    mini = nums[j]; 
                }
            }
            if (miniIndex == -1) break; 
            else {
                score += mini; 
                markedElements[miniIndex] = true; 
                if (miniIndex-1 >= 0) markedElements[miniIndex-1] = true;
                if (miniIndex+1 < n) markedElements[miniIndex+1] = true;
            }
        }

        return score; 
    }
}; 


// T.C. = O((n/2) * n) = O(n^2) 
// S.C. = O(n) 

// Here, n = the length of 1-D input vector named "nums" 