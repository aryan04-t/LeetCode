// LeetCode (852. Peak Index in a Mountain Array): 
// https://leetcode.com/problems/intersection-of-two-linked-lists/ 


#include<vector> 
using namespace std; 


class Solution {
public:

    int peakIndexInMountainArray(vector<int>& arr) {
        
        int n = arr.size(); 

        for(int i=1; i < n-1; i++){
            if(arr[i-1] < arr[i] && arr[i] > arr[i+1]){
                return i; 
            }
        }

        return -1;
    }
};


// T.C. = O(n) 
// S.C. = O(1) 

// Here, n = the total number of elements which are present inside the input vector named "arr" 