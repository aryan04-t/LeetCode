// LeetCode (2073. Time Needed to Buy Tickets): 
// https://leetcode.com/problems/time-needed-to-buy-tickets/ 


#include<vector> 
using namespace std; 


class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        
        int n = tickets.size(); 

        int i = 0; 
        int time = 0; 

        while(tickets[k] != 0){
            if(tickets[i % n] != 0){
                tickets[i % n] -= 1; 
                time++; 
            }
            i++;
        }

        return time;
    }
};


// T.C. = O(tickets[k] * n) 
// S.C. = O(1) 

// Here, n = the total number of integers which are present inside the input vector named "nums" 