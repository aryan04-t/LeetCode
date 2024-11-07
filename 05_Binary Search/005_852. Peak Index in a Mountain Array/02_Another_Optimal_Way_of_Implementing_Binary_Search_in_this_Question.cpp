// LeetCode (852. Peak Index in a Mountain Array): 
// https://leetcode.com/problems/intersection-of-two-linked-lists/ 


#include<vector> 
using namespace std; 


class Solution {
public:

    int peakIndexInMountainArray(vector<int>& arr) {
        
        int n = arr.size(); 

        int start = 0;
        int end = n-1; 

        while(start < end){
            
            int mid = start + (end - start)/2; 

            if(arr[mid] < arr[mid+1]) start = mid + 1;  
            else if(arr[mid] > arr[mid+1]) end = mid;
        }

        return start; 
    }
};


// T.C. = O(log(n) to the base 2) 
// S.C. = O(1) 

// Here, n = the total number of elements which are present inside the input vector named "arr" 