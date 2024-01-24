// LeetCode (73. Set Matrix Zeroes): 
// https://leetcode.com/problems/set-matrix-zeroes/ 


#include<vector> 
using namespace std;


class Solution {
public:
    
    void setZeroes(vector<vector<int>>& matrix) {

        int m = matrix.size();
        int n = matrix[0].size();

        int zeroCommaZeroColHash = 1;

        for(int row = 0; row < m; row++){
            for(int col = 0; col < n; col++){
                if(matrix[row][col] == 0){
                    if(col == 0){
                        zeroCommaZeroColHash = 0;
                        matrix[row][0] = 0;
                    }
                    else{
                        matrix[0][col] = 0;
                        matrix[row][0] = 0;
                    }
                }
            }
        }

        for(int row = 1; row < m; row++){
            if(matrix[row][0] == 0){
                for(int i = 1; i < n; i++){
                    matrix[row][i] = 0;
                }
            }
        }

        for(int col = 1; col < n; col++){
            if(matrix[0][col] == 0){
                for(int i = 1; i < m; i++){
                    matrix[i][col] = 0;
                }
            }
        }

        if(matrix[0][0] == 0){
            for(int col = 1; col < n; col++){
                matrix[0][col] = 0;
            }
        }

        if(zeroCommaZeroColHash == 0){
            for(int row = 0; row < m; row++){
                matrix[row][0] = 0;
            }
        }

    }
};


// T.C. = O(m*n) + O((m-1)*(n-1)) + O((n-1)*(m-1)) + O(n) + O(m) = O(m*n) 
// S.C. = O(1) 

// Here, m = total number of 1-D vectors which are present inside the input 2-D vector named "matrix", and n = total number of elements which are present inside the 1st 1-D vector 