// LeetCode (912. Sort an Array): 
// https://leetcode.com/problems/sort-an-array/ 


// This code gives TLE (Time Limit Exceeded) Error 


#include<vector> 
using namespace std; 


// Optimized Bubble Sort 

class Solution {
public:

    vector<int> sortArray(vector<int>& nums) {

        int n = nums.size();

        for(int i=0; i < n-1; i++){
            bool done = true;
            for(int j=0; j < n-i-1; j++){
                if(nums[j] > nums[j+1]){
                    swap(nums[j], nums[j+1]); 
                    done = false;
                }
            }
            if(done) break;
        }

        return nums; 
    }
};


/* 

# T.C. = O((n * (n-1))/2) = O(n^2) 
     Best Case    |    Average Case   |    Worst Case   | 
        O(n)      |       O(n^2)      |      O(n^2)     | 

# S.C. = O(1) 
     Best Case    |    Average Case   |    Worst Case   | 
       O(1)       |       O(1)        |      O(1)       | 

Here, n = the total number of elements which are present inside the input vector named "nums" 

*/ 