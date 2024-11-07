// LeetCode (73. Set Matrix Zeroes): 
// https://leetcode.com/problems/set-matrix-zeroes/ 


#include<vector> 
using namespace std;


class Solution {
public:
    
    void setZeroes(vector<vector<int>>& matrix) {

        int m = matrix.size();
        int n = matrix[0].size();

        vector<bool> hashColWillBeZero(n, false); 
        vector<bool> hashRowWillBeZero(m, false); 

        for(int row = 0; row < m; row++){
            for(int col = 0; col < n; col++){
                if(matrix[row][col] == 0){
                    hashColWillBeZero[col] = true;
                    hashRowWillBeZero[row] = true;
                }
            }
        }

        for(int row = 0; row < m; row++){
            if(hashRowWillBeZero[row]){
                for(int i=0; i < n; i++){
                    matrix[row][i] = 0;
                }
            }
            
        }
        
        for(int col = 0; col < n; col++){
            if(hashColWillBeZero[col]){
                for(int i=0; i < m; i++){
                    matrix[i][col] = 0;
                }
            }    
        }
    }
};


// T.C. = O(m*n) + O(m*n) + O(n*m) = O(3*m*n) = O(n*m) 
// S.C. = O(n + m) 

// Here, m = total number of 1-D vectors which are present inside the input 2-D vector named "matrix", and n = total number of elements which are present inside the 1st 1-D vector 