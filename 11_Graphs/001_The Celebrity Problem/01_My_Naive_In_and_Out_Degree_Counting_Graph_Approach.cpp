// GeeksForGeeks (The Celebrity Problem): 
// https://www.geeksforgeeks.org/problems/the-celebrity-problem/1 


#include<vector> 
using namespace std; 


class Solution {
public:

    int celebrity(vector<vector<int>> &M, int n){
        
        vector<int> inDegree(n); 
        vector<int> outDegree(n); 
        
        for(int i=0; i < n; i++){
            for(int j=0; j < n; j++){
                if(M[i][j] == 1){
                    outDegree[i]++; 
                    inDegree[j]++; 
                }
            }
        }
        
        for(int i=0; i < n; i++){
            if(inDegree[i] == n-1 && outDegree[i] == 0){
                return i;
            }
        }
        
        return -1; 
    }
};


// T.C. = O(n^2) + O(n) = O(n^2) 
// S.C. = O(n) + O(n) = O(2n) = O(n) 

// Here, n = the total number of people who are present in the party = the value of input variable named "n" 