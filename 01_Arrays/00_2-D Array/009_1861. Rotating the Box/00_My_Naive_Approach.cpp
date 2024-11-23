// LeetCode (1861. Rotating the Box): 
// https://leetcode.com/problems/rotating-the-box 


#include<vector> 
using namespace std; 


class Solution {
public:

    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        
        int m = box.size(); 
        int n = box[0].size(); 

        vector<vector<char>> ans(n, vector<char>(m, '.')); 

        int ii = 0; 
        int jj = m-1; 

        for (int i=0; i < m; i++) {
            
            int stones = 0; 
            
            for (int j=0; j < n; j++) {
                if (box[i][j] == '#') stones++; 
                else if (box[i][j] == '*') {
                    ii = j;
                    ans[ii--][jj] = '*'; 
                    while (stones) {
                        ans[ii][jj] = '#'; 
                        stones--;
                        ii--; 
                    }
                }
            }

            if (stones) {
                ii = n-1; 
                while (stones) {
                    ans[ii][jj] = '#'; 
                    stones--; 
                    ii--; 
                } 
            }

            ii = 0; 
            jj--; 
        }

        return ans; 
    }
};


// T.C. = O(n*m) + O(m*(2n)) = O(m*n) 
// S.C. = O(n*m) 

// Here, m = total number of 1-D vectors which are present inside the input 2-D vector named "box", n = the total number of characters which are present inside each 1-D vector 