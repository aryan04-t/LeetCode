// LeetCode (3075. Maximize Happiness of Selected Children): 
// https://leetcode.com/problems/maximize-happiness-of-selected-children/ 


#include<vector> 
#include<algorithm> 
using namespace std; 


class Solution {
public:

    long long maximumHappinessSum(vector<int>& happiness, int k) {
        
        int n = happiness.size(); 
        sort(happiness.begin(), happiness.end(), greater<int>()); 

        long long totalMaxHappiness = 0; 
        int i = 0; 
        int happinessLost = 0; 

        while(k--){
            
            int currPersonHappiness = happiness[i] - happinessLost; 
            
            if(currPersonHappiness > 0) totalMaxHappiness += currPersonHappiness; 
            else break; 
            
            happinessLost++; 
            i++;
        }

        return totalMaxHappiness; 
    }
};


// T.C. = O(n * log(n)) + O(k) = O(n * log(n)) 
// S.C. = O(log(n)) 

// Here, n = the total number of elements which are present inside the input vector named "happiness" 