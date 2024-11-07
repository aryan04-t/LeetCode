// LeetCode (169. Majority Element): 
// https://leetcode.com/problems/majority-element/ 


#include<vector> 
#include<algorithm> 
using namespace std; 


class Solution {
public:

    int majorityElement(vector<int>& nums) {
        
        int n = nums.size(); 
        sort(nums.begin(), nums.end()); 
        
        return nums[n/2]; 

    }

};


// T.C. = O( n * log(n) ) 
// S.C. = O(log(n) to the base 2) 

// Here, n = total number of elements which are present inside the input vector named "nums" 