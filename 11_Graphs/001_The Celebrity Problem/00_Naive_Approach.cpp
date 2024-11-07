// GeeksForGeeks (The Celebrity Problem): 
// https://www.geeksforgeeks.org/problems/the-celebrity-problem/1 


#include<vector> 
using namespace std; 


class Solution {
public:

    int celebrity(vector<vector<int>> &M, int n){
        
        int celebrityWho = -1; 
        
        for(int i=0; i < n; i++){
            
            bool iKnowNoOne = true; 
            for(int j=0; j < n; j++){
                if(M[i][j] != 0){
                    iKnowNoOne = false;
                    break;
                }
            }
            if(!iKnowNoOne) continue; 
            
            bool everyoneKnowsMe = true; 
            for(int j=0; j < n; j++){
                if(i == j) continue; 
                if(M[j][i] == 0){
                    everyoneKnowsMe = false; 
                    break;
                }
            }
            
            if(iKnowNoOne && everyoneKnowsMe){
                celebrityWho = i;
                break;
            }
        }
        
        return celebrityWho; 
    }
};


// T.C. = O(n * (n + n)) = O(n * 2n) = O(n^2) 
// S.C. = O(1) 

// Here, n = the total number of people who are present in the party = the value of input variable named "n" 