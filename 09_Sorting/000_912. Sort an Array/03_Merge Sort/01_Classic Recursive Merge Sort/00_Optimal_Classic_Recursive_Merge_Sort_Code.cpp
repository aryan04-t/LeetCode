// LeetCode (912. Sort an Array): 
// https://leetcode.com/problems/sort-an-array/ 


#include<vector>
using namespace std;


// Classic Recursive Merge Sort 

class Solution {
public:

    void mergeArrays(vector<int> &v, int start, int end){

        int mid = start + (end - start)/2; 

        int n = mid - start + 1; 
        int m = end - mid; 

        vector<int> v1; 
        vector<int> v2;

        for(int i=start; i < mid+1; i++) v1.push_back(v[i]);
        for(int i=mid+1; i < end+1; i++) v2.push_back(v[i]);

        int i = 0; 
        int j = 0;
        int k = start; 

        while(i < n && j < m){
            if(v1[i] <= v2[j]) v[k++] = v1[i++];
            else v[k++] = v2[j++];
        }

        while(i < n) v[k++] = v1[i++]; 
        while(j < m) v[k++] = v2[j++]; 
    }

    void mergeSortHelper(vector<int> &v, int start, int end){

        if(start >= end) return; 

        int mid = start + (end - start)/2; 

        mergeSortHelper(v, start, mid); 
        mergeSortHelper(v, mid+1, end); 
    
        mergeArrays(v, start, end); 
    }

    void mergeSort(vector<int> &v){

        int n = v.size(); 
        int start = 0;
        int end = n - 1; 

        mergeSortHelper(v, start, end); 
    }

    vector<int> sortArray(vector<int>& nums) {

        mergeSort(nums); 
        return nums; 
    }
};


/* 

# T.C. = O(n * (log(n)) 
     Best Case     |    Average Case    |    Worst Case     | 
   O(n * log(n))   |    O(n * log(n))   |   O(n * log(n))   | 

# S.C. = O(log(n)) + O(n) = (this s.c. caused due to the function call stack) + (this s.c. is caused by the extra arrays which are used for merging) = O(n) 
     Best Case     |    Average Case    |    Worst Case     | 
       O(n)        |       O(n)         |       O(n)        | 

Here, n = the total number of elements which are present inside the input vector named "nums" 

*/ 