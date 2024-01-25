// LeetCode (118. Pascal's Triangle): 
// https://leetcode.com/problems/pascals-triangle/ 


#include<vector>
using namespace std;


class Solution {
public:

    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> ans;

        for(int row=0; row < numRows; row++){
            
            ans.push_back(vector<int>());

            for(int col=0; col < row+1; col++){
                if(col == 0 || col == row){
                    ans[row].push_back(1);
                }
                else{
                    int currentAns = ans[row-1][col-1] + ans[row-1][col];
                    ans[row].push_back(currentAns); 
                }
            }
        
        }

        return ans;

    }
};


// T.C. = O((n*(n+1))/2) = O(n^2) 
// S.C. = O((n*(n+1))/2) = O(n^2) 

// Here, n = the value of input number named "numRows" 