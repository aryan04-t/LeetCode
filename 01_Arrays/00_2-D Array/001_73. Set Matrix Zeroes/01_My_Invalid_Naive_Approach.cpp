// LeetCode (73. Set Matrix Zeroes): 
// https://leetcode.com/problems/set-matrix-zeroes/ 


// My Invalid Naive Approach: 

// LeetCode says to solve this question in-place, but I just wanted to check whether I can solve this question or not by using extra space 


#include<vector> 
using namespace std;


class Solution {
public:

    void setZeroes(vector<vector<int>>& matrix) {
        
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> newMatrix;

        for(int row = 0; row < m; row++){
            for(int col = 0; col < n; col++){
                newMatrix.push_back(vector<int>());
                newMatrix[row].push_back(matrix[row][col]);
            }
        }

        for(int row = 0; row < m; row++){
            for(int col = 0; col < n; col++){
                if(matrix[row][col] == 0){
                    for(int i=0; i < n; i++){
                        newMatrix[row][i] = 0;
                    }
                    for(int i=0; i < m; i++){
                        newMatrix[i][col] = 0;
                    }
                }
            }
        }

        for(int row = 0; row < m; row++){
            for(int col = 0; col < n; col++){
                matrix[row][col] = newMatrix[row][col];
            }
        }
        
    }
};


// T.C. = O(m*n) + O(m*n*(n+m)) + O(m*n) = O(2*m*n) + O(n^2*m + m^2*n) = O(max(n^2*m, m^2*n)) 
// S.C. = O(m*n) 

// Here, m = total number of 1-D vectors which are present inside the input 2-D vector named "matrix", and n = total number of elements which are present inside the 1st 1-D vector 