// LeetCode (33. Search in Rotated Sorted Array): 
// https://leetcode.com/problems/search-in-rotated-sorted-array/ 


#include<vector> 
using namespace std; 


class Solution {
public:

    int findPivotIndex(vector<int> &v){

        int n = v.size(); 

        int start = 0; 
        int end = n - 1; 

        while(start <= end){

            int mid = start + (end - start)/2; 

            if( (mid + 1) < n && v[mid] > v[mid+1]) return mid; 
            if( (mid - 1) >= 0 && v[mid-1] > v[mid]) return mid - 1;

            if(v[start] <= v[mid]) start = mid + 1;
            else if(v[start] > v[mid]) end = mid - 1; 
        }

        return -1; 
    }

    int binarySearch(vector<int> &v, int target, int start, int end){

        while(start <= end){

            int mid = start + (end - start)/2; 

            if(v[mid] == target) return mid; 
            else if(target < v[mid]) end = mid - 1;
            else if(target > v[mid]) start = mid + 1; 
        }

        return -1; 
    }

    int search(vector<int>& nums, int target) {

        int n = nums.size(); 
        int pivotIndex = findPivotIndex(nums); 

        if(pivotIndex != -1){
            int ans1 = binarySearch(nums, target, 0, pivotIndex); 
            int ans2 = binarySearch(nums, target, pivotIndex + 1, n-1); 

            if(ans1 == -1 && ans2 != -1) return ans2; 
            else if(ans1 != -1 && ans2 == -1) return ans1; 
            else if(ans1 == -1 && ans2 == -1) return -1; 
        }
        
        return binarySearch(nums, target, 0, n-1); 
    }
};


// T.C. = O(log(n)) + O(log(n)) = O(2*log(n)) = O(log(n)) 
// S.C. = O(1) 

// Here, n = the total number of elements which are present inside the input vector named "nums" 