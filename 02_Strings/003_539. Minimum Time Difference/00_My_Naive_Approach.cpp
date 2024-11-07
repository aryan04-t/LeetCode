// LeetCode (539. Minimum Time Difference): 
// https://leetcode.com/problems/minimum-time-difference/ 


#include<iostream>
#include<vector>
#include<string>
using namespace std;


class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        
        vector<int> total_mins;

        for(int i=0; i < timePoints.size(); i++){
            int minutes = (60 * stoi( timePoints[i].substr(0,2) ) + stoi( timePoints[i].substr(3,2) ));
            total_mins.push_back(minutes);
        }

        int mini = INT_MAX;

        for(int i=0; i < total_mins.size(); i++){
            for(int j=i+1; j < total_mins.size(); j++){
                if(total_mins[i] > total_mins[j]){
                    int diff = total_mins[i] - total_mins[j];
                    if(diff > 720){
                        diff = 1440 - diff;
                    }
                    mini = min(diff, mini);
                }
                else{
                    int diff = total_mins[j] - total_mins[i];
                    if(diff > 720){
                        diff = 1440 - diff;
                    }
                    mini = min(diff, mini);
                }
            }
        }

        return mini;
    }
};


// T.C. = O(n) + O(n^2) = O(n^2) 
// -> (traversing whole vector to convert time into minutes, and storing it in other vector) + (t.c. of nested loops to compare every pair of time points and calculate the time difference between them for finding the minimum time difference) 

// S.C. = O(n) 
// -> Creating one more vector proportional to the size of input vector 

// Here, n = size of input vector named "timePoints" 