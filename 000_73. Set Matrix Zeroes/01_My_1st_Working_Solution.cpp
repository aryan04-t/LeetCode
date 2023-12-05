// LeetCode (Set Matrix Zeroes): 
// https://leetcode.com/problems/set-matrix-zeroes/ 


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


// TC: O(n*m) + O(((n*m)-1)*(n+m)) = O(n^2 + 2nm + m^2 - n - m) = O(max(n^2,m^2)) 
// Where n = number of rows and m = number of columns 


/*

// SC: 

Best Case:     Omega(1) 
Average Case:  Theta(min(2*number of zero elements, 2*(n*m))) = Theta(min(number of zero elements, n*m)) 
Worst Case:    O(2*(n*m)) = O(n*m) 

*/