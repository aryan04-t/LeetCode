// LeetCode (74. Search a 2D Matrix): 
// https://leetcode.com/problems/search-a-2d-matrix/ 


#include<vector> 
using namespace std; 


class Solution {
public:

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int n  = matrix.size();
        int m = matrix[0].size();

        int start = 0;
        int end = (n*m) - 1; 

        while(start <= end){

            int mid = start + (end-start) / 2; 
            int row = mid / m; 
            int col = mid % m;

            if(matrix[row][col] == target){
                return true;
            }
            else if(target < matrix[row][col]){
                end = mid - 1;
            }
            else if(target > matrix[row][col]){
                start = mid + 1;
            }

        }

        return false; 
    }
};


// T.C. = O(log(n*m)) 
// S.C. = O(1) 

// Here, n = total number of rows which are present inside the 2-D input vector named "matrix", and m = total number of columns which are present inside one row of "matrix" 