// LeetCode (73. Set Matrix Zeroes): 
// https://leetcode.com/problems/set-matrix-zeroes/ 


// My Failed Naive Approach 


#include<vector> 
using namespace std;


class Solution {
public:

    void setZeroes(vector<vector<int>>& matrix) {
        
        int m = matrix.size();
        int n = matrix[0].size();

        for(int row = 0; row < m; row++){
            for(int col = 0; col < n; col++){
                if(matrix[row][col] == 0){
                    for(int i=0; i < n; i++){
                        matrix[row][i] = 0;
                    }
                    for(int i=0; i < m; i++){
                        matrix[i][col] = 0;
                    }
                }
            }
        }

    }
};


// T.C. = O(m * n  * (n+m)) = O(n^2*m + m^2*n) = O(max(n^2*m, m^2*n)) 
// S.C. = O(1) 

// Here, m = total number of 1-D vectors which are present inside the input 2-D vector named "matrix", and n = total number of elements which are present inside the 1st 1-D vector 