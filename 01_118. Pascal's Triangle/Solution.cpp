// LeetCode (Pascal's Triangle): 
// https://leetcode.com/problems/pascals-triangle/  

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {

        vector<vector<int>> ans;

        for(int i=0; i < numRows; i++){
            vector<int> temp(i+1);

            for(int j=0; j < i+1; j++){
                if(j == 0 || j == i){
                    temp[j] = 1;
                }
                else{
                    temp[j] = ans[i-1][j-1] + ans[i-1][j];
                }
            }

            ans.push_back(temp);
            temp.clear();
        }

        return ans;
    }
};

// TC: O(1+2+3+....+numRows) = O((numRows.(numRows+1))/2) = O(numRows^2) = O(n^2)                  // Here n = numRows 
// SC: Same goes here and SC also = O(n^2) 