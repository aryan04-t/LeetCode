// LeetCode (3683. Earliest Time to Finish One Task): 
// https://leetcode.com/problems/earliest-time-to-finish-one-task 


#include<vector>
#include<algorithm> 
using namespace std;


class Solution {
public:
    int earliestTime(vector<vector<int>>& tasks) {
        
        // Using stl implemented min_element function with a lambda function to add custom logic to the min element finding logic 
        
        vector<vector<int>>::iterator it = min_element(
            tasks.begin(), 
            tasks.end(), 
            [](const vector<int> &task1, const vector<int> &task2) {
                int task1EndTime = task1[0] + task1[1];
                int task2EndTime = task2[0] + task2[1];
                return task1EndTime < task2EndTime;
            }
        );

        vector<int> ans = *it;
        int earliestEndingTask = ans[0] + ans[1];

        return earliestEndingTask;
    }
};


// T.C. = O(n) 
// S.C. = O(1) 

// Here, n = the length of input vector named "tasks" 