// LeetCode (169. Majority Element): 
// https://leetcode.com/problems/majority-element/ 


#include<vector> 
using namespace std; 


class Solution {
public:

    int majorityElement(vector<int>& nums) {

        int n = nums.size(); 

        int count = 0;
        int candidate;

        for(int i=0; i < n; i++){

            if(count == 0){
                candidate = nums[i];
            }

            if(nums[i] == candidate){
                count++;
            }
            else{
                count--;
            }

        }

        return candidate; 

    }

};


// T.C. = O(n) 
// S.C. = O(1) 

// Here, n = total number of elements which are present inside the input vector named "nums" 