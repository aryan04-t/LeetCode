// LeetCode (912. Sort an Array): 
// https://leetcode.com/problems/sort-an-array/ 


// This code gives TLE (Time Limit Exceeded) Error 


#include<vector> 
using namespace std; 


// Insertion Sort 

class Solution {
public:

    vector<int> sortArray(vector<int>& nums) {

        int n = nums.size();

        for(int i=1; i < n; i++){
            int val = nums[i]; 
            int j = i-1;
            while(j >= 0){
                if(nums[j] > val){
                    nums[j+1] = nums[j]; 
                }
                else{
                    break; 
                }
                j--; 
            }
            nums[j+1] = val; 
        }

        return nums; 
    }
};


/* 

# T.C. = O((n * (n-1))/2) = O(n^2) 
     Best Case    |    Average Case   |    Worst Case   | 
      O(n)        |       O(n^2)      |      O(n^2)     | 

# S.C. = O(1) 
     Best Case    |    Average Case   |    Worst Case   | 
       O(1)       |       O(1)        |      O(1)       | 

Here, n = the total number of elements which are present inside the input vector named "nums" 

*/ 