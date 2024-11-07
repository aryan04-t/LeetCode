// LeetCode (2133. Check if Every Row and Column Contains All Numbers): 
// https://leetcode.com/problems/check-if-every-row-and-column-contains-all-numbers/ 


#include<vector> 
using namespace std; 


class Solution {
public:

    bool checkValid(vector<vector<int>>& matrix) {
        
        int n = matrix.size();

        for(int i=0; i < n; i++){
            
            vector<bool> hashNum(n+1, false);

            for(int j=0; j < n; j++){
                hashNum[matrix[i][j]] = true;
            }
            
            for(int k=1; k < n+1; k++){
                if(!hashNum[k]){
                    return false;
                }
            }

        }

        for(int i=0; i < n; i++){
            
            vector<bool> hashNum(n+1, false);

            for(int j=0; j < n; j++){
                hashNum[matrix[j][i]] = true;
            }
            
            for(int k=1; k < n+1; k++){
                if(!hashNum[k]){
                    return false;
                }
            }

        }

        return true;

    }
};


// T.C. = O(n^2) 
// S.C. = O(n) 

// Here, n = total number of 1-D vectors which are present inside the 2-D input vector named "matrix" = total number of integers which are present inside one 1-D vector 
// Or, n = total number of rows which are present inside the 2-D input vector named "matrix" = total number of columns which are present inside one row 