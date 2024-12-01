// LeetCode (2257. Count Unguarded Cells in the Grid): 
// https://leetcode.com/problems/count-unguarded-cells-in-the-grid 


#include<vector> 
using namespace std; 


class Solution {
public:

    void plotGuardsOrWallsInMatrix(
        vector<vector<int>> &cells, 
        const vector<vector<int>> &toBePlottedEntity, 
        int val 
    ) {
        for (const vector<int> &coordinates : toBePlottedEntity) {
            int rowCord = coordinates[0]; 
            int colCord = coordinates[1]; 
            cells[rowCord][colCord] = val; 
        }
    } 

    void traverseInAll4Directions(
        vector<vector<int>> &cells, 
        const vector<pair<int, int>> &directions, 
        int startX, 
        int startY 
    ) {
        
        int m = cells.size(); 
        int n = cells[0].size(); 

        for (const auto &[dx, dy] : directions) {
            int x = startX + dx; 
            int y = startY + dy; 
            while ((x >= 0 && x < m) && (y >= 0 && y < n)) {
                if (cells[x][y] < 0) break; 
                else cells[x][y]++; 
                x += dx; 
                y += dy; 
            }
        }
    }

    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        
        vector<vector<int>> cells(m, vector<int>(n, 0)); 

        plotGuardsOrWallsInMatrix(cells, guards, -1); 
        plotGuardsOrWallsInMatrix(cells, walls, -2); 

        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; 

        for (const vector<int> &guard : guards) {
            int x = guard[0]; 
            int y = guard[1]; 
            traverseInAll4Directions(cells, directions, x, y); 
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


// T.C. = O(g) + O(w) + O(g*(m+n)) + O(m*n) = O(g) + O(w) + O(m*n) + O(m*n) = O(g) + O(w) + O(2*m*n) = O(m*n) 
// S.C. = O(m*n) 

// Here, g = the length of 2-D input vector named "guards", w = the length of 2-D input vector named "walls" 
// m = the total number of rows in grid, and n = the total number of columns in each row 