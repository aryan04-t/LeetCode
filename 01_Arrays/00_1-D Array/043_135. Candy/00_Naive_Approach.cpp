// LeetCode (135. Candy): 
// https://leetcode.com/problems/candy/ 


#include<vector> 
#include<algorithm> 
using namespace std; 


class Solution {
public: 

    int candy(vector<int>& ratings) {
        
        int n = ratings.size(); 

        vector<int> leftSide(n, 1); 
        vector<int> rightSide(n, 1); 

        for(int i=1; i < n; i++){
            if(ratings[i] > ratings[i-1]){
                leftSide[i] = leftSide[i-1] + 1; 
            }
        }

        for(int i=n-2; i >= 0; i--){
            if(ratings[i] > ratings[i+1]){
                rightSide[i] = rightSide[i+1] + 1; 
            }
        }

        int totalCandies = 0; 
        for(int i=0; i < n; i++){
            totalCandies += max(leftSide[i], rightSide[i]); 
        }

        return totalCandies; 
    }
};


// T.C. = O(n) + O(n) + O(n) = O(3n) = O(n) 
// S.C. = O(n) + O(n) = O(2n) = O(n) 

// Here, n = the total number of elements which are present inside the input vector named "nums" 