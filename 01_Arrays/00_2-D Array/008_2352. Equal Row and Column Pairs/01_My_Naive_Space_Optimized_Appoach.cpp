// LeetCode (2352. Equal Row and Column Pairs): 
// https://leetcode.com/problems/equal-row-and-column-pairs/ 


#include<vector> 
using namespace std; 


class Solution {
public:

    int isPresentHowManyTimes(const vector<int> &row, const vector<vector<int>> &grid){

        int n = row.size(); 
        int count = 0; 

        for(int j=0; j < n; j++){
            bool same = true; 
            for(int i=0; i < n; i++){
                if(grid[i][j] != row[i]){
                    same = false; 
                    break; 
                }
            }
            if(same) count++; 
        }

        return count;
    }

    int equalPairs(vector<vector<int>>& grid) {

        int n = grid.size(); 
        int count = 0; 

        for(int i=0; i < n; i++){
            count += isPresentHowManyTimes(grid[i], grid); 
        }

        return count;
    }
};


// T.C. = O(n^3) 
// S.C. = O(1) 

// Here, n = the total number of rows which are present inside the 2-D input vector named "grid" = the total number of columns which are present inside each row of 2-D input vector named "grid"