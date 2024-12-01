// LeetCode (2257. Count Unguarded Cells in the Grid): 
// https://leetcode.com/problems/count-unguarded-cells-in-the-grid 


// This is raw code, because it violates DRY (Don't Repeat Yourself) principle of coding 


#include<vector> 
using namespace std; 


class Solution {
public:

    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        
        vector<vector<int>> cells(m, vector<int>(n, 0)); 

        for (const vector<int> &coordinates: guards) {
            int rowCord = coordinates[0]; 
            int colCord = coordinates[1]; 
            cells[rowCord][colCord] = -1; 
        }

        for (const vector<int> &coordinates: walls) {
            int rowCord = coordinates[0]; 
            int colCord = coordinates[1]; 
            cells[rowCord][colCord] = -2; 
        }

        for (int i=0; i < m; i++) {
            for (int j=0; j < n; j++) {
                if (cells[i][j] == -1) {
                    int k = i; 
                    int l = j+1; 
                    while (l < n) {
                        if (cells[k][l] < 0) break; 
                        else cells[k][l]++; 
                        l++; 
                    }
                    k = i+1;
                    l = j; 
                    while (k < m) {
                        if (cells[k][l] < 0) break; 
                        else cells[k][l]++; 
                        k++; 
                    }
                    k = i; 
                    l = j-1;
                    while (l >= 0) {
                        if (cells[k][l] < 0) break; 
                        else cells[k][l]++; 
                        l--; 
                    }
                    k = i-1; 
                    l = j; 
                    while (k >= 0) {
                        if (cells[k][l] < 0) break; 
                        else cells[k][l]++; 
                        k--; 
                    }
                }
            }
        }

        int unguardedCells = 0; 

        for (int i=0; i < m; i++) {
            for (int j=0; j < n; j++) {
                if (cells[i][j] == 0) unguardedCells++; 
            }
        }

        return unguardedCells; 
    }
};


// T.C. = O(g) + O(w) + O(m*n + g*(m+n)) + O(m*n) = O(g) + O(w) + O(m*n + m*n) + O(m*n) = O(g) + O(w) + O(3*m*n) = O(m*n) 
// S.C. = O(m*n) 

// Here, g = the length of 2-D input vector named "guards", w = the length of 2-D input vector named "walls" 
// m = the total number of rows in grid, and n = the total number of columns in each row 