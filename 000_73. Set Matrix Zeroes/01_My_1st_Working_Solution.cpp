// LeetCode (Set Matrix Zeroes): 
// https://leetcode.com/problems/set-matrix-zeroes/ 

#include<iostream>
#include<vector>
using namespace std;

#define n v.size()

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        vector<int> v;

        int maxRows = matrix.size();
        int maxCols = matrix[0].size();

        for(int row=0; row < maxRows; row++){
            for(int col=0; col < maxCols; col++){
                if(matrix[row][col] == 0){
                    v.push_back(row);
                    v.push_back(col);
                }
            }
        }

        if(n == 2*(maxCols*maxRows)){
            return;
        }

        for(int i=0; i < n; i = i+2){
            for(int j=0; j < maxCols; j++){
                matrix[v[i]][j] = 0;
            }
            for(int j=0; j < maxRows; j++){
                matrix[j][v[i+1]] = 0;
            }
        }
    }

};

// TC: O(n*m)                                              // Where n = number of rows and m = number of columns 

// SC: Omega(1)    Theta(min(number of zero elements, maxRow * maxCol))    O(2*(m*n)) means O(m*n) 