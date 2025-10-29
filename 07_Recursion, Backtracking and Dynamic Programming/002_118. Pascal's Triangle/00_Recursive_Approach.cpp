// LeetCode (118. Pascal's Triangle): 
// https://leetcode.com/problems/pascals-triangle/ 


#include<vector>
using namespace std;


class Solution {
public:

    vector<vector<int>> generate(int numRows) {
        
        if(numRows == 1){
            return {{1}};
        }

        vector<vector<int>> ans = generate(numRows-1);

        ans.push_back(vector<int>());

        for(int col=0; col < numRows; col++){
            if(col == 0 || col == numRows-1){
                ans[numRows-1].push_back(1);
            }
            else{
                int currAns = ans[numRows-2][col-1] + ans[numRows-2][col];
                ans[numRows-1].push_back(currAns);
            }
        }

        return ans;

    }
};


// T.C. = O((n*(n+1))/2) = O(n^2) 
// S.C. = O((n*(n+1))/2) + O(n) = O(n^2) 
// --> Above extra O(n) space complexity is caused by function call stack 

// Here, n = the value of input number named "numRows" 