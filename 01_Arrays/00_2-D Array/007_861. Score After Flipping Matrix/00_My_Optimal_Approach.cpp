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

        for(int i=0; i < n; i++){
            if(grid[i][0] == 0){
                for(int j=0; j < m; j++){
                    if(grid[i][j] == 0) grid[i][j] = 1;
                    else if(grid[i][j] == 1) grid[i][j] = 0;
                }
            }
        }

        for(int j=1; j < m; j++){
            int setBits = 0; 
            for(int i=0; i < n; i++){
                if(grid[i][j] == 1) setBits++; 
            }
            if(setBits < int(ceil(n/2.0))){
                for(int i=0; i < n; i++){
                    if(grid[i][j] == 0) grid[i][j] = 1;
                    else if(grid[i][j] == 1) grid[i][j] = 0;
                }
            }
        }

        int ans = 0;

        for(int i=0; i < n; i++){
            int num = 0;
            int pow = 1;
            for(int j=m-1; j >= 0; j--){
                num += pow * grid[i][j]; 
                pow *= 2; 
            }
            /*
            // Instead of using above logic, we could also use this logic to get the value of binary numbers  
            int num = 0; 
            for(int j=0; j < m; j++){
                num = num*2 + grid[i][j]; 
            } 
            */
            ans += num;
        }

        return ans; 
    }
};


// T.C. = O(n*m) + O((m-1)*(n + n)) + O(n*m) = O(n*m) 
// S.C. = O(1) 

// Here, n = the total number of rows which are present inside the input vector named "grid", 
// and m = the total number of columns which are present inside each 1-D vector which are present inside input vector named "grid" 