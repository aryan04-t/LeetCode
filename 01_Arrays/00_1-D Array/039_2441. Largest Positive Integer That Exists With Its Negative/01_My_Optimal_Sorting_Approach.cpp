// LeetCode (2441. Largest Positive Integer That Exists With Its Negative): 
// https://leetcode.com/problems/largest-positive-integer-that-exists-with-its-negative/ 


#include<vector> 
#include<algorithm> 
using namespace std; 


class Solution {
public:

    int findMaxK(vector<int>& nums) {
        
        sort(nums.begin(), nums.end()); 

        int n = nums.size(); 
        int ans = -1;
        int i=0, j=n-1; 
        
        while(i < j){
            if(-nums[j] == nums[i]){
                ans = nums[j];
                break;
            }
            else if(-nums[j] < nums[i]){
                j--;
            }
            else if(-nums[j] > nums[i]){
                i++; 
            }
        }

        return ans;
    }
};


// T.C. = O(n * log(n)) + O(n) = O(n * log(n)) 
// S.C. = O(log(n)) 

// Here, n = the total number of elements which are present inside the input vector named "nums" 