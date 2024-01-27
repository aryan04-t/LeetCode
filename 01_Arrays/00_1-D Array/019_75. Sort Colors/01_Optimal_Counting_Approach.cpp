// LeetCode (75. Sort Colors): 
// https://leetcode.com/problems/sort-colors/ 


#include<vector>
using namespace std;


class Solution {
public:

    void sortColors(vector<int>& nums) {
        
        int red = 0;
        int white = 0;
        int blue = 0;

        for(auto color : nums){
            if(color == 0) red++; 
            if(color == 1) white++; 
            if(color == 2) blue++;
        }

        int i = 0;
        while(red--) nums[i++] = 0;
        while(white--) nums[i++] = 1;
        while(blue--) nums[i++] = 2;

    }
    
};


// T.C. = O(2n) = O(n) 
// S.C. = O(1) 

// Here, n = total number of elements which are present inside the input vector named "nums" 


// This is a good optimized algorithm, but it is still not doing the operations in-place that's why we will see the new approach: "3 pointer approach" 