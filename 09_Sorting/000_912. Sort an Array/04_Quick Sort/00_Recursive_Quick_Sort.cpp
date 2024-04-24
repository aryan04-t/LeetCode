// LeetCode (912. Sort an Array): 
// https://leetcode.com/problems/sort-an-array/ 


// This code gives TLE (Time Limit Exceeded) Error 
// LeetCode is smart, they have added one specific test case for hitting the worst case of quick sort, nicee. 


#include<vector>
using namespace std;


// Recursive Quick Sort 

class Solution {
public:

    int positionPivotAndDoPartition(vector<int> &v, int start, int end){

        int pivot = v[start]; 

        int count = 0;
        for(int i=start+1; i < end+1; i++){
            if(v[i] <= pivot) count++; 
        }

        int pivotIndex = start + count; 
        swap(v[start], v[pivotIndex]); 

        int i = start; 
        int j = end; 

        while(i < pivotIndex && j > pivotIndex){
            while(i < pivotIndex && v[i] <= v[pivotIndex]) i++; 
            while(j > pivotIndex && v[j] > v[pivotIndex]) j--; 
            swap(v[i], v[j]); 
        }

        return pivotIndex; 
    }

    void quickSortHelper(vector<int> &v, int start, int end){

        if(start >= end) return; 

        int pivotIndex = positionPivotAndDoPartition(v, start, end); 

        quickSortHelper(v, start, pivotIndex - 1);
        quickSortHelper(v, pivotIndex + 1, end);
    }

    void quickSort(vector<int> &v){

        int n = v.size(); 
        int start = 0; 
        int end = n - 1;

        quickSortHelper(v, start, end);         
    }

    vector<int> sortArray(vector<int>& nums) {

        quickSort(nums); 
        return nums; 
    }
};


/* 

# T.C. = O(n * (log(n)) 
     Best Case     |    Average Case    |    Worst Case     | 
   O(n * log(n))   |    O(n * log(n))   |      O(n^2)       | 

# S.C. = O(n) -> (this s.c. is caused by the extra arrays which are used for merging) 
     Best Case     |    Average Case    |    Worst Case     | 
     O(log(n))     |     O(log(n))      |       O(n)        | 

Here, n = the total number of elements which are present inside the input vector named "nums" 

*/ 