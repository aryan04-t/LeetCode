// LeetCode (74. Search a 2D Matrix): 
// https://leetcode.com/problems/search-a-2d-matrix/ 


#include<vector> 
using namespace std; 


class Solution {
public:

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int n = matrix.size();
        int m = matrix[0].size();

        for(int i=0; i < n; i++){

            if(target == matrix[i][0] || target == matrix[i][m-1]){
                return true;
            }
            else if(target > matrix[i][0] && target < matrix[i][m-1]){
                
                int start = 0;
                int end = m-1;
                int mid;

                while(start <= end){
                    
                    mid = start + (end-start)/2;
                    
                    if(matrix[i][mid] == target){
                        return true;
                    }
                    else if(target < matrix[i][mid]){
                        end = mid-1;
                    }
                    else if(target > matrix[i][mid]){
                        start = mid+1;
                    }

                }
                
                break;

            }
            else{
                continue;
            }
            
        }

        return false;

    }
};


// T.C. = O(n) + O(log(m) to the base 2) = O(max(n, (log(m) to the base 2)) 
// S.C. = O(1) 

// Here, n = total number of 1-D vectors which are present inside the 2-D input vector named "matrix", and m = total number of integers which are present inside one 1-D vector of "matrix" 
// Or we can say that, n = total number of rows which are present in the 2-D input vector named "matrix", and m = total number of columns which are present inside one row of "matrix" 