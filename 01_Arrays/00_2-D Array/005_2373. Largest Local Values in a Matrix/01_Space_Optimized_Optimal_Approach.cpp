// LeetCode (2373. Largest Local Values in a Matrix): 
// https://leetcode.com/problems/largest-local-values-in-a-matrix/ 


#include<vector> 
using namespace std; 


class Solution {
public:

    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {

        int n = grid.size(); 

        vector<vector<int>> ans(n-2, vector<int>(n-2, 0)); 
        int index = 0; 
        
        for(int i=0; i < n-2; i++){
            for(int j=0; j < n-2; j++){
                int maxi = -1; 
                for(int k=i; k < i+3; k++){
                    for(int l=j; l < j+3; l++){
                        maxi = max(maxi, grid[k][l]); 
                    }
                }
                int row = index / (n-2);
                int col = index % (n-2); 
                grid[row][col] = maxi; 
                index++;
            }
        }

        grid.pop_back();
        grid.pop_back();

        for(int i=0; i < n; i++){
            grid[i].pop_back();
            grid[i].pop_back();
        }   

        return grid; 
    }
};


// T.C. = O((n-2) * (n-2) * 3 * 3) + O(n) = O(9 * (n-2)^2) + O(n) = O(n^2) 
// S.C. = O(1) 

// Here, n = the total number of rows which are present inside the input vector named "grid" = the total number of columns which are present in each row of input vector named "grid" 