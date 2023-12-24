// LeetCode (Final Value of Variable After Performing Operations): 
// https://leetcode.com/problems/final-value-of-variable-after-performing-operations/ 


// Optimal Approach using Range Based For Loop 


#include<vector>
#include<string>
using namespace std;


class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        
        int X = 0;

        for(auto i: operations){
            if(i == "X--" || i == "--X"){
                X--;
            }
            else{
                X++;
            }
        }

        return X;

    }
};


// T.C. = O(n) 
// S.C. = O(1) 

// Here, n = number of elements present in input vector named "operations" 