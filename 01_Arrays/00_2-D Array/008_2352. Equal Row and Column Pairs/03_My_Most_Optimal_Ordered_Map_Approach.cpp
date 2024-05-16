// LeetCode (2352. Equal Row and Column Pairs): 
// https://leetcode.com/problems/equal-row-and-column-pairs/ 


#include<vector> 
#include<map> 
using namespace std; 


class Solution {
public:

    int equalPairs(vector<vector<int>>& grid) {

        int n = grid.size(); 
        map<vector<int>, int> mp; 
        for(int i=0; i < n; i++) mp[grid[i]]++; 

        int count = 0; 

        for(int j=0; j < n; j++){
            vector<int> temp(n, 0); 
            for(int i=0; i < n; i++){
                temp[i] = grid[i][j]; 
            }
            count += mp[temp]; 
        }

        return count; 
    }
};


// T.C. = O(n*n*log(n)) + O(n * (n + n*log(n))) = O(n^2 * log(n)) 
// S.C. = O(n^2) 

// Here, n = the total number of 1-D vectors which are present inside the given input 2-D vector = total number of columns which are present inside each 1-D vector of the given input input 2-D vector 