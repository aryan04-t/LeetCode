// LeetCode (2798. Number of Employees Who Met the Target): 
// https://leetcode.com/problems/number-of-employees-who-met-the-target/ 


#include<vector> 
using namespace std; 


class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
        
        int n = hours.size();
        int count = 0;

        for(int i=0; i < n; i++){
            if(hours[i] >= target){
                count++;
            }
        }

        return count;
    }
};


// T.C. = O(n) 
// S.C. = O(1) 

// Here, n = number of elements present inside the input vector named "hours" 