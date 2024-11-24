// LeetCode (1975. Maximum Matrix Sum): 
// https://leetcode.com/problems/maximum-matrix-sum 


#include<vector> 
#include<cstdlib> 
using namespace std; 


class Solution {
public:

    long long maxMatrixSum(vector<vector<int>>& matrix) {
        
        int n = matrix.size(); 

        long long absSum = 0;
        int negNums = 0, mostMinAbsVal = INT_MAX; 

        for (int i=0; i < n; i++) {
            for (int j=0; j < n; j++) {
                int currNum = matrix[i][j]; 
                int absCurrNum = abs(currNum); 
                if (currNum < 0) negNums++; 
                if (absCurrNum < mostMinAbsVal) mostMinAbsVal = absCurrNum;
                absSum += absCurrNum; 
            }
        }

        if (negNums & 1) return absSum - (2*mostMinAbsVal);

        return absSum; 
    }
};


// T.C. = O(n^2) 
// S.C. = O(1)

// Here, n = total number of 1-D vectors which are present inside the 2-D input vector named "matrix" = total number of integers which are present inside each 1-D vector 