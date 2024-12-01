// LeetCode (1346. Check If N and Its Double Exist): 
// https://leetcode.com/problems/check-if-n-and-its-double-exist 


#include<vector> 
using namespace std; 


class Solution {
public: 

    bool binarySearch (vector<int> &arr, int j) {

        int start = 0; 
        int end = arr.size() - 1; 
        int target = 2 * arr[j]; 

        while (start <= end) {
            int i = start + (end - start)/2; 
            if (i == j) start = i + 1; 
            else if (arr[i] == target) return true; 
            else if (target > arr[i]) start = i + 1; 
            else if (target < arr[i]) end = i - 1; 
        }

        return false; 
    }

    bool checkIfExist(vector<int>& arr) {

        int n = arr.size(); 
        sort(arr.begin(), arr.end()); 

        for (int j=0; j < n; j++) { 
            bool ans = binarySearch(arr, j); 
            if (ans) return ans; 
        } 

        return false; 
    }
}; 


// T.C. = O(n*log(n)) + O(n*log(n)) = O(2*n*log(n)) = O(n*log(n)) 
// S.C. = O(log(n)) -> Worst case s.c. of c++ intro-sort 

// Here, n = the length of 1-D input vector named "arr" 