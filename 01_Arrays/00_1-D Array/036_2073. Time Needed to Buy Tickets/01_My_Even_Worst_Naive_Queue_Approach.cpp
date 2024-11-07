// LeetCode (2073. Time Needed to Buy Tickets): 
// https://leetcode.com/problems/time-needed-to-buy-tickets/ 


#include<vector> 
#include<queue> 
using namespace std; 


class Solution {
public:

    int timeRequiredToBuy(vector<int>& tickets, int k) {
        
        int n = tickets.size(); 

        queue<pair<int, int>> q; 
        for(int i=0; i < n; i++){
            q.push({tickets[i], i}); 
        }

        int time = 0; 

        while(!q.empty()){
            
            pair<int, int> currPair = q.front(); 
            int currNum = currPair.first; 
            int currIndex = currPair.second; 

            q.pop(); 
            
            if(currNum != 0){
                currNum -= 1; 
                time++; 
                if(currNum != 0) q.push({currNum, currIndex}); 
            }

            if(currNum == 0 && currIndex == k) break;
        }

        return time;
    }
};


// T.C. = O(tickets[k] * n) 
// S.C. = O(n) 

// Here, n = the total number of integers which are present inside the input vector named "nums" 