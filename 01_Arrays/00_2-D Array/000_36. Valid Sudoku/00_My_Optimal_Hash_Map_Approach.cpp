// LeetCode(36. Valid Sudoku): 
// https://leetcode.com/problems/valid-sudoku/ 


#include<vector> 
#include<unordered_map> 
#include<utility> 
using namespace std; 


class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        
        int n = board.size();
        unordered_map<char, int> mp;


        // Checking Row Wise Validness of Sudoku Board 
        for(int i=0; i < n; i++){
            
            for(int j=0; j < n; j++){
                mp[board[i][j]]++;
            }

            for(pair<char, int> val : mp){
                if(val.first != '.' && val.second > 1){
                    return false;
                }
            }

            mp.clear();

        }

        
        // Checking Column Wise Validness of Suduko Board 
        for(int i=0; i < n; i++){
            
            for(int j=0; j < n; j++){
                mp[board[j][i]]++;
            }

            for(pair<char, int> val : mp){
                if(val.first != '.' && val.second > 1){
                    return false;
                }
            }

            mp.clear();

        }


        // Checking Validness of Sub-Boxes of the Grid 
        for(int i=0; i < 3; i++){
            
            for(int j=0; j < 3; j++){

                for(int row = 3*i; row < 3*(i+1); row++){
                    for(int col = 3*j; col < 3*(j+1); col++){
                        mp[board[row][col]]++;
                    }
                }

                for(pair<char, int> val : mp){
                    if(val.first != '.' && val.second > 1){
                        return false;
                    }
                }
                            
                mp.clear();

            }

        }


        return true;


    }
};


// T.C. = O(n^2) + O(n^2) + O(n^2) = O(n^2) 
// S.C. = O(n) 

// Here, n = length of Sudoku board's one side, it simply means n = size of input vector named "board" 