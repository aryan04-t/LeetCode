// LeetCode (3142. Check if Grid Satisfies Conditions): 
// https://leetcode.com/problems/check-if-grid-satisfies-conditions/ 


#include<vector> 
using namespace std; 


class Solution {
public:
    
    bool satisfiesConditions(vector<vector<int>>& grid) {
    
        bool satisfies = true;
        
        int n = grid.size(); 
        int m = grid[0].size(); 
        
        for(int i=0; i < n; i++){
            for(int j=0; j < m; j++){
                if(i+1 < n && grid[i][j] != grid[i+1][j]){
                    satisfies = false;
                    break;
                }
                if(j+1 < m && grid[i][j] == grid[i][j+1]){
                    satisfies = false;
                    break;    
                }
            }
            if(!satisfies) break; 
        }
        
        if(!satisfies) return false;         
        return true;
    }
};


// T.C. = O(n * m) 
// S.C. = O(1) 

// Here, n = the total number of rows which are present inside the input vector named "grid",
// and m = the total number of columns which are present in each row of input vector named "grid" 