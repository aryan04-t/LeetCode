// LeetCode (134. Gas Station): 
// https://leetcode.com/problems/gas-station/ 


#include<vector> 
using namespace std; 


class Solution {
public:

    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int n = gas.size();

        for(int i=0; i < n; i++){
            
            int currentGas = 0;
            int condition = n;
            
            for(int j=i; j < condition; j++){
                
                currentGas += gas[j]; 
                currentGas -= cost[j]; 

                if(currentGas < 0){
                    break;
                }

                if(j == n-1){
                    j = -1;
                    condition = i;
                }

            }

            if(currentGas >= 0){
                return i;
            }
        }
        
        return -1;

    }
};


// T.C. = O(n^2) 
// S.C. = O(1) 

// Here, n = total number of elements which are present inside the input vector named "gas" = total number of elements which are present inside the input vector named "cost" 