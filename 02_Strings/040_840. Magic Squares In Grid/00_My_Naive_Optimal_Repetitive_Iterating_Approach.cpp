// LeetCode (840. Magic Squares In Grid): 
// https://leetcode.com/problems/magic-squares-in-grid/ 


#include<vector> 
using namespace std; 


class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        
        int rows = grid.size(); 
        int cols = grid[0].size(); 

        int magicSqrCount = 0;

        for(int i=0; i+2 < rows; i++){
            for(int j=0; j+2 < cols; j++){
                
                int rowEnd = i+3; 
                int colEnd = j+3; 

                int allSum = 0; 
                bool isMagicSqr = true; 

                vector<int> seenMap(10, false); 

                for(int rowStart = i; rowStart < rowEnd; rowStart++){
                    int sum = 0; 
                    bool invalidSqr = false; 
                    for(int colStart = j; colStart < colEnd; colStart++){
                        int currNum = grid[rowStart][colStart]; 
                        if(currNum > 9 || currNum < 1){
                            invalidSqr = true; 
                            break; 
                        }
                        else if(seenMap[currNum]){
                            invalidSqr = true; 
                            break; 
                        }
                        sum += currNum; 
                        seenMap[currNum] = true; 
                    }

                    if(invalidSqr){
                        isMagicSqr = false; 
                        break;
                    }

                    if(rowStart == i) allSum = sum; 
                    else if(sum != allSum){
                        isMagicSqr = false; 
                        break;
                    } 
                }

                if(!isMagicSqr) continue; 

                for(int colStart = j; colStart < colEnd; colStart++){
                    int sum = 0; 
                    for(int rowStart = i; rowStart < rowEnd; rowStart++){
                        sum += grid[rowStart][colStart]; 
                    }
                    if(sum != allSum){
                        isMagicSqr = false; 
                        break; 
                    } 
                } 
                
                if(!isMagicSqr) continue; 

                int rowCoordinate = i, colCoordinate = j, sum = 0; 
                for(int k=0; k < 3; k++){
                    sum += grid[rowCoordinate][colCoordinate]; 
                    rowCoordinate++; 
                    colCoordinate++; 
                } 
                if(sum != allSum) continue; 

                rowCoordinate = i+2, colCoordinate = j, sum = 0; 
                for(int k=0; k < 3; k++){ 
                    sum += grid[rowCoordinate][colCoordinate]; 
                    rowCoordinate--; 
                    colCoordinate++; 
                }
                if(sum != allSum) continue; 

                if(isMagicSqr){
                    magicSqrCount++; 
                } 
            }
        }

        return magicSqrCount; 
    }
};


// T.C. = O((n-2) * (m-2) * (9 + 9 + 3 + 3)) = O(n^2) 
// S.C. = O(1) 

// Here, n = the total number of rows which are present inside the gird, and m = the total number of columns which are present inside the grid 



/*

    # Insights: 

    - Time and space complexity wise this approach is optimal, but runtime can be improved more and this code is verbose, it is violating DRY principle of coding I feel and I can make this code more compact without breaking its intutiveness and readability, and that's why I am also calling this approach of mine as "Naive" along with "Optimal"

    - I also calling this approach "Repetitive Iterating", cuz I feel a lot of elements are getting process again and again, and I can solve the problem using sliding window by processing each element only once, let's see I will be able to do it or not

*/