// LeetCode (912. Sort an Array): 
// https://leetcode.com/problems/sort-an-array/ 


#include<vector>
using namespace std;


// Iterative Merge Sort 

class Solution {
public:

    void mergeArrays(vector<int> &v, int start, int mid, int end){

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

    void mergeSort(vector<int> &v){

        int n = v.size(); 
        
        for(int subArrSize=1; subArrSize < n; subArrSize *= 2){
            for(int i=0; i < n - subArrSize; i += 2 * subArrSize){
               
                int start = i; 
                int mid = i + subArrSize - 1; 
                int end = min(i + 2 * subArrSize - 1, n-1); 
            
                mergeArrays(v, start, mid, end); 
            }
        }
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

# S.C. = O(n) -> (this s.c. is caused by the extra arrays which are used for merging) 
     Best Case     |    Average Case    |    Worst Case     | 
       O(n)        |       O(n)         |       O(n)        | 

Here, n = the total number of elements which are present inside the input vector named "nums" 

*/ 