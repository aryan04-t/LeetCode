// LeetCode (912. Sort an Array): 
// https://leetcode.com/problems/sort-an-array/ 


#include<vector>
using namespace std;


class Solution {
public:

    void mergeArrays(vector<int> &v, int start, int end){

        int mid = start + (end - start)/2; 

        int n = mid - start + 1; 
        int m = end - mid; 

        vector<int> v1; 
        vector<int> v2;
        
        int i = start; 
        while(i <  mid+1){
            v1.push_back(v[i++]);
        }

        int j = mid+1;
        while(j <= end){
            v2.push_back(v[j++]); 
        }

        i = 0; 
        j = 0; 
        int k = start; 
        while(i < n && j < m){
            if(v1[i] <= v2[j]){
                v[k++] = v1[i++];
            }
            else{
                v[k++] = v2[j++]; 
            }
        }

        while(j < m){
            v[k++] = v2[j++];
        }

        while(i < n){
            v[k++] = v1[i++];
        }
    }

    void mergeSortHelper(vector<int> &v, int start, int end){

        if(start == end) return; 

        int mid = start + (end - start)/2; 

        mergeSortHelper(v, start, mid); 
        mergeSortHelper(v, mid+1, end); 

        mergeArrays(v, start, end); 
        
    }

    void mergeSort(vector<int> &v){

        int n = v.size();
        int start  = 0;
        int end = n-1;

        mergeSortHelper(v, start, end);

    }

    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums);   
        return nums;
    }

};


// T.C. = O(n * (log(n) to the base 2)) 
// S.C. = O(n) + O(log(n) to the base 2) = O(n) 

// Here, n = total number of elements which are present inside the input vector named "nums" 