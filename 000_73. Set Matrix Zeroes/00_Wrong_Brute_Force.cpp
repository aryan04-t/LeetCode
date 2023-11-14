// LeetCode (Set Matrix Zeroes): 
// https://leetcode.com/problems/set-matrix-zeroes/ 

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        int maxRows = matrix.size();
        int maxCols = matrix[0].size();

        for(int row=0; row < maxRows; row++){
            for(int col=0; col < maxCols; col++){
                if(matrix[row][col] == 0){
                    for(int i=0; i < maxCols; i++){
                        matrix[row][i] = 0;
                    }
                    for(int j=0; j < maxRows; j++){
                        matrix[j][col] = 0;
                    }
                }
            }
        }
    }
    
};

// Above solution is totally wrong, although this is the 1st solution which I came up with when I saw the question for the 1st time. 

// In above solution chain reaction of zeroes takes place, and even the indices which should not be zero, they also become zero. 