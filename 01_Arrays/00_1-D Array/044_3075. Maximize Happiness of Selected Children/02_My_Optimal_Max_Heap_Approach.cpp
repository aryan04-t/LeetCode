// LeetCode (3075. Maximize Happiness of Selected Children): 
// https://leetcode.com/problems/maximize-happiness-of-selected-children/ 


#include<vector> 
#include<queue> 
using namespace std; 


class Solution {
public:

    long long maximumHappinessSum(vector<int>& happiness, int k) {

        int n = happiness.size(); 

        priority_queue<int> maxHeap; 
        for(int val : happiness) maxHeap.push(val); 

        long long totalMaxHappiness = 0;
        int happinessLost = 0; 

        while(k--){
            
            int currPersonHappiness = maxHeap.top() - happinessLost; 
            
            if(currPersonHappiness > 0) totalMaxHappiness += (long long)currPersonHappiness; 
            else break; 

            happinessLost++; 
            maxHeap.pop(); 
        }

        return totalMaxHappiness; 
    }
};


// T.C. = O(n * log(n)) + O(k * log(n)) = O(n * log(n)) 
// S.C. = O(n) 

// Here, n = the total number of elements which are present inside the input vector named "happiness" 