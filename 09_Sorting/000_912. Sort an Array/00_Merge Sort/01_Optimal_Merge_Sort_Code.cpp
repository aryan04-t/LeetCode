// LeetCode (912. Sort an Array): 
// https://leetcode.com/problems/sort-an-array/ 


#include<vector>
using namespace std;


class Solution {
public:

    void mergeArrays(vector<int> &v, int start, int end){

        int mid  = start + (end - start)/2; 

        int arr1_Len = mid - start + 1;
        int arr2_Len = end - mid;

        vector<int> arr1; 
        vector<int> arr2; 


        for(int i = start; i <= mid; i++){
            arr1.push_back(v[i]);
        }
        
        for(int i = mid+1; i <= end; i++){
            arr2.push_back(v[i]);
        }


        int mainIndex = start; 
        int i = 0;
        int j = 0; 
        
        while(i < arr1_Len && j < arr2_Len){
            if(arr1[i] < arr2[j]){
                v[mainIndex++] = arr1[i++];
            }
            else{
                v[mainIndex++] = arr2[j++];
            }
        }

        if(i == arr1_Len){
            while(j < arr2_Len){
                v[mainIndex++] = arr2[j++];
            }
        }
        
        if(j == arr2_Len){
            while(i < arr1_Len){
                v[mainIndex++] = arr1[i++];
            }
        }

    }


    void mergeSortMain(vector<int> &u, int start, int end){

        if(start == end){
            return;
        }

        int mid = start + (end - start)/2; 

        mergeSortMain(u, start, mid); 

        mergeSortMain(u, mid+1, end); 

        mergeArrays(u, start, end);

    }


    void mergeSort(vector<int> &v){

        int n = v.size();
        int start  = 0;
        int end = n-1;

        mergeSortMain(v, start, end);

    }


    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums);   
        return nums;
    }

};


// T.C. = O(n * (log(n) to the base 2)) 
// S.C. = O(n) + O(log(n) to the base 2) = O(n) 

// Here, n = total number of elements which are present inside the input vector named "nums" 