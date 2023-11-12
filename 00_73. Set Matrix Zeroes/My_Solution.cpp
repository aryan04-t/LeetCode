#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        vector<int> v;
        
        int maxRow = matrix.size();
        int maxCol = matrix[0].size();

        for(int row=0; row < maxRow; row++){
            for(int col=0; col < maxCol; col++){
                if(matrix[row][col]==0){
                    v.push_back(row);
                    v.push_back(col);
                }
            }
        }

        if(v.size() == 2*(maxRow * maxCol)){
            return;
        }

        for(int i=0; i < v.size(); i = i+2){
            for(int j=0; j < maxCol; j++){
                matrix[v[i]][j] = 0;
            }
            for(int k=0; k < maxRow; k++){
                matrix[k][v[i+1]] = 0;
            }
        }
    }
};

// TC: O(n*m)                                              // Where n = number of rows and m = number of columns 
// SC: Omega(1)   Theta(1)   O(2*(m*n)) means O(m*n) 