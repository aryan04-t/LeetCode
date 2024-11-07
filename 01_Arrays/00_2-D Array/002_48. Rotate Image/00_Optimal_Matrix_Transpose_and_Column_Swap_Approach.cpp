// LeetCode (48. Rotate Image): 
// https://leetcode.com/problems/rotate-image/ 


#include<vector> 
using namespace std; 


class Solution {
public:

    void rotate(vector<vector<int>>& matrix) {
        
        int n = matrix.size();

        for(int i=0; i < n-1; i++){
            for(int j=i+1; j < n; j++){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }

        for(int i=0; i < n; i++){
            for(int j=0; j < n/2; j++){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[i][n-1-j];
                matrix[i][n-1-j] = temp;
            }
        }

    }
};


// T.C. = O(n^2) + O(n^2) = O(n^2) 
// S.C. = O(1) 

// Here, n =  the number of 1-D vectors which are present inside the 2-D input vector named "matrix" = the number of integers which are present inside one 1-D vector 
// Or, n = the number of rows which are present inside the 2-D input vector named "matrix" = the number of columns which are present inside one row 