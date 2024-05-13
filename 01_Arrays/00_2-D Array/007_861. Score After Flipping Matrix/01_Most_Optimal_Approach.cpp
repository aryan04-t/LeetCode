// LeetCode (861. Score After Flipping Matrix): 
// https://leetcode.com/problems/score-after-flipping-matrix/ 


#include<vector> 
#include<cmath> 
using namespace std; 


class Solution {
public:

    int matrixScore(vector<vector<int>>& grid) {

        int n = grid.size(); 
        int m = grid[0].size(); 

        int ans = n * (1 << (m-1)); 

        for(int j=1; j < m; j++){
            int setBits = 0; 
            for(int i=0; i < n; i++){
                if(grid[i][j] == grid[i][0]) setBits++; 
            }
            if( setBits < int(ceil(n/2.0)) ){
                ans += (n - setBits) * (1 << (m - 1 - j)); 
            } 
            else{
                ans += setBits * (1 << (m - 1 - j));
            }
            /*
            // Above written if-else logic can also be written in a much more neat and clean way like this: 
            int val = 1 << (m - 1 - j); 
            ans += max(setBits, n - setBits) * val;
            */
        }

        return ans; 
    }
};


// T.C. = O((m-1) * n) = O(n*m) 
// S.C. = O(1) 

// Here, n = the total number of rows which are present inside the input vector named "grid", 
// and m = the total number of columns which are present inside each 1-D vector which are present inside input vector named "grid" 