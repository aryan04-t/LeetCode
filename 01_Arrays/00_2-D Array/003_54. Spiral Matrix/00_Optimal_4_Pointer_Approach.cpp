// LeetCode (54. Spiral Matrix): 
// https://leetcode.com/problems/spiral-matrix/ 


#include<vector>
using namespace std; 


class Solution {
public:

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();

        int top = 0; 
        int bottom = n-1; 
        int left = 0; 
        int right = m-1; 

        vector<int> ans;

        while(left <= right && top <= bottom){
            
            for(int i=left; i <= right; i++){
                ans.push_back(matrix[top][i]); 
            }
            top++;

            for(int i=top; i <= bottom; i++){
                ans.push_back(matrix[i][right]); 
            }
            right--;

            if(top <= bottom){
                for(int i=right; i >= left; i--){
                    ans.push_back(matrix[bottom][i]); 
                }
                bottom--;
            }

            if(left <= right){
                for(int i=bottom; i >= top; i--){
                    ans.push_back(matrix[i][left]); 
                }
                left++;
            }

        }

        return ans;

    }
};


// T.C. = O(n*m) 
// S.C. = O(1) 

// Here, n = total number of rows which are present inside the 2-D input vector "matrix", and m = total number of columns which are present inside one row of "matrix" 