// LeetCode (1346. Check If N and Its Double Exist): 
// https://leetcode.com/problems/check-if-n-and-its-double-exist 


#include<vector> 
using namespace std; 


class Solution {
public:

    bool checkIfExist(vector<int>& arr) {

        int n = arr.size(); 

        for (int i=0; i < n; i++) {
            for (int j=0; j < n; j++) {
                if (i == j) continue; 
                if (arr[i] == 2*arr[j]) return true; 
            }
        }

        return false; 
    }
};


// T.C. = O(n^2) 
// S.C. = O(1) 

// Here, n = the length of 1-D input vector named "arr" 