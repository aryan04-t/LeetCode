// LeetCode (724. Find Pivot Index): 
// https://leetcode.com/problems/find-pivot-index/ 


#include<vector> 
using namespace std; 


class Solution {
public: 

    int pivotIndex(vector<int>& nums) {
        
        int n = nums.size(); 
        vector<int> sum(n, 0); 
        sum[0] = nums[0]; 

        for(int i=1; i < n; i++){
            sum[i] = sum[i-1] + nums[i]; 
        }
        
        for(int i=0; i < n; i++){
            if(i == 0){
                if(sum[n-1] - nums[i] == 0) return i; 
            } 
            else if(sum[i-1] == sum[n-1] - sum[i]){
                return i; 
            }
        }

        return -1; 
    }
};


// T.C. = O(n) + O(n) = O(2n) = O(n) 
// S.C. = O(n) 

// Here, n = the total number of elements which are present inside the input vector named "nums" 