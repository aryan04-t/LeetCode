// LeetCode (2352. Equal Row and Column Pairs): 
// https://leetcode.com/problems/equal-row-and-column-pairs/ 


#include<vector> 
using namespace std; 


class Solution {
public:

    int isPresentHowManyTimes(const vector<int> &row, const vector<vector<int>> &colToRow){

        int n = row.size(); 
        int count = 0; 

        for(int i=0; i < n; i++){
            bool same = true; 
            for(int j=0; j < n; j++){
                if(colToRow[i][j] != row[j]){
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
        vector<vector<int>> colToRows(n, vector<int>(n, 0)); 

        for(int j=0; j < n; j++){
            for(int i=0; i < n; i++){
                colToRows[j][i] = grid[i][j]; 
            }
        }

        int count = 0; 

        for(int i=0; i < n; i++){
            count += isPresentHowManyTimes(grid[i], colToRows); 
        }

        return count;
    }
};


// T.C. = O(n^2) + O(n^3) = O(n^3) 
// S.C. = O(n^2) 

// Here, n = the total number of rows which are present inside the 2-D input vector named "grid" = the total number of columns which are present inside each row of 2-D input vector named "grid"