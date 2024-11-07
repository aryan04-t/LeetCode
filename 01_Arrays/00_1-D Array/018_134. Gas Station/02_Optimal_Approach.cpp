// LeetCode (134. Gas Station): 
// https://leetcode.com/problems/gas-station/ 


#include<vector> 
using namespace std; 


class Solution {
public:

    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int n = gas.size();
        
        int currentGas = 0;
        int gasDeficit = 0;
        int ans = 0;

        for(int i=0; i < n; i++){
            
            currentGas += gas[i] - cost[i];
            
            if(currentGas < 0){
                gasDeficit -= currentGas;
                ans = i+1;
                currentGas = 0;
            }

        }

        if(currentGas >= gasDeficit){
            return ans;
        }
        
        return -1;

    }
};


// T.C. = O(n) 
// S.C. = O(1) 

// Here, n = total number of elements which are present inside the input vector named "gas" = total number of elements which are present inside the input vector named "cost" 