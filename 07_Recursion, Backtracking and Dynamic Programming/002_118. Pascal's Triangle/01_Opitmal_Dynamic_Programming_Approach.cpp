// LeetCode (118. Pascal's Triangle): 
// https://leetcode.com/problems/pascals-triangle/ 


#include<vector>
using namespace std;


class Solution {
public:

    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> ans;
        ans.push_back({1});

        vector<int> prevRow;

        for(int row=1; row < numRows; row++){
            
            vector<int> currRow;

            for(int col=0; col < row+1; col++){
                if(col == 0 || col == row){
                    currRow.push_back(1);
                }
                else{
                    int currAns = prevRow[col-1] + prevRow[col];
                    currRow.push_back(currAns); 
                }
            }

            ans.push_back(currRow);
            prevRow = currRow;
        }

        return ans;

    }
};


// T.C. = O((n*(n+1))/2) = O(n^2) 
// S.C. = O((n*(n+1))/2) + O(n) + O(n) = O(n^2) 

// Here, n = the value of input number named "numRows" 