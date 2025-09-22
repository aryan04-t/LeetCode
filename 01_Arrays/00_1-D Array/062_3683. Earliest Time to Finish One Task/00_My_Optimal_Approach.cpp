// LeetCode (3683. Earliest Time to Finish One Task): 
// https://leetcode.com/problems/earliest-time-to-finish-one-task 


#include<vector>
#include<climits>
#include<algorithm> 
using namespace std;


class Solution {
public:
    int earliestTime(vector<vector<int>>& tasks) {
        int mini = INT_MAX;
        for (const vector<int> &task : tasks) {
            int completeTime = task[0] + task[1];
            mini = min(mini, completeTime);
        }
        return mini;
    }
};


// T.C. = O(n) 
// S.C. = O(1) 

// Here, n = the length of input vector named "tasks" 