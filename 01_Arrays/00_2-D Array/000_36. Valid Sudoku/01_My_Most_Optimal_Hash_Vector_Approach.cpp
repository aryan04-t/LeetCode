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
        vector<int> hashVector(n+1, 0); 


        // Checking Row Wise Validness of Sudoku Board 
        for(int i=0; i < n; i++){
            
            for(int j=0; j < n; j++){
                if(board[i][j] != '.'){
                    hashVector[board[i][j] - '0']++;
                }
            }

            for(int val : hashVector){
                if(val > 1) return false; 
            }

            for(int j=0; j <= n; j++){
                hashVector[j] = 0;
            }

        }

        
        // Checking Column Wise Validness of Suduko Board 
        for(int i=0; i < n; i++){
            
            for(int j=0; j < n; j++){
                if(board[j][i] != '.'){
                    hashVector[board[j][i] - '0']++;
                }
            }

            for(int val : hashVector){
                if(val > 1) return false;
            }

            for(int j=0; j <= n; j++){
                hashVector[j] = 0;
            }

        }


        // Checking Validness of Sub-Boxes of the Grid 
        for(int i=0; i < 3; i++){
            
            for(int j=0; j < 3; j++){

                for(int row = 3*i; row < 3*(i+1); row++){
                    for(int col = 3*j; col < 3*(j+1); col++){
                        if(board[row][col] != '.'){
                            hashVector[board[row][col] - '0']++;
                        }
                    }
                }

                for(int val : hashVector){
                    if(val > 1) return false;
                }

                for(int j=0; j <= n; j++){
                    hashVector[j] = 0;
                }

            }

        }


        return true;


    }
};


// T.C. = O(n^2) + O(n^2) + O(n^2) = O(n^2) 
// S.C. = O(n) 

// Here, n = length of Sudoku board's one side, it simply means n = size of input vector named "board" 



/*


# "Hash Map" and "Hash Vector" both approaches have same time complexity then why I have labelled "Hash Vector" as "Most Optimal Approach":  


@ Although "Hash Map" and "Hash Vector" both the approaches have same time complexity, but in real world when you're calculating algorithm's runtime in milliseconds, then the "Hash Vector" approach will always out perform "Hash Map" approach both "time" and "memory" wise, because obviously "vector" is light data structure as compared to "unordered_map", and also obviously the access to elements in "Vector" is faster than "Hash Map". 


--> That's why I have labeled this approach as "Most Optimal Approach". 


*/