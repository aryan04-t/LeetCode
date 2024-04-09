// LeetCode (2073. Time Needed to Buy Tickets): 
// https://leetcode.com/problems/time-needed-to-buy-tickets/ 


#include<vector> 
using namespace std; 


class Solution {
public:

    int timeRequiredToBuy(vector<int>& tickets, int k) {
        
        int n = tickets.size(); 
        int totalTime = 0;

        for(int i=0; i < n; i++){
            if(i <= k){
                totalTime += min(tickets[i], tickets[k]); 
            }
            else{
                totalTime += min(tickets[i], tickets[k] - 1); 
            }
        }

        return totalTime;
    }
};


// T.C. = O(n) 
// S.C. = O(1) 

// Here, n = the total number of integers which are present inside the input vector named "nums" 