// LeetCode (189. Rotate Array): 
// https://leetcode.com/problems/rotate-array/ 


#include<vector> 
using namespace std; 


class Solution {
public:

    void reverseInPlace(vector<int> &v, int startIndex, int endIndex){

        while(startIndex < endIndex){
            int temp = v[startIndex];
            v[startIndex++] = v[endIndex];
            v[endIndex--] = temp;
        }

    }

    void rotate(vector<int>& nums, int k) {
        
        int n = nums.size();

        k = k % n; 

        reverseInPlace(nums, 0, n-k-1);
        reverseInPlace(nums, n-k, n-1);

        reverseInPlace(nums, 0, n-1);

    }

};


// T.C. = O(n/2) + O(n/2) = O(n) 
// S.C. = O(1) 

// Here, n = total number of elements which are present inside the input vector named "nums", and k = the value of input variable named "k" 