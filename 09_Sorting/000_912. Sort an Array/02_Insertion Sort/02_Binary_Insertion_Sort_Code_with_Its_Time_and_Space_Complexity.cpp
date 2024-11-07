// LeetCode (912. Sort an Array): 
// https://leetcode.com/problems/sort-an-array/ 


// This code gives TLE (Time Limit Exceeded) Error 


#include<vector> 
using namespace std; 


// Binary Insertion Sort 

class Solution {
public:

    int binarySearchFindGreaterElement(vector<int> &v, int start, int end, int val){

        while(start <= end){
            
            int mid = start + (end - start)/2; 

            if(v[mid] > val){
                if(mid-1 == -1){
                    return 0; 
                }
                else{
                    if(v[mid-1] <= val){
                        return mid; 
                    }
                    else{
                        end = mid - 1;
                    }
                }
            }
            else if(v[mid] <= val) start = mid + 1; 
        }

        return -1; 
    }

    vector<int> sortArray(vector<int>& nums) {

        int n = nums.size();

        for(int i=1; i < n; i++){
        
            int val = nums[i];
            int pos = binarySearchFindGreaterElement(nums, 0, i-1, val); 
            
            if(pos == -1) continue; 
            
            int j = i-1;
            while(j >= pos){
                if(val < nums[j]){
                    nums[j+1] = nums[j]; 
                }
                else{
                    break;
                }
                j--;
            }
            nums[pos] = val; 
        }

        return nums; 
    }
};


/* 

# T.C. = O( (n * (log(n) + (n-1))) / 2 ) = O(n^2) 
     Best Case     |    Average Case   |    Worst Case   | 
   O(n * log(n))   |       O(n^2)      |      O(n^2)     | 

# S.C. = O(1) 
     Best Case    |    Average Case   |    Worst Case   | 
       O(1)       |       O(1)        |      O(1)       | 

Here, n = the total number of elements which are present inside the input vector named "nums" 

*/ 