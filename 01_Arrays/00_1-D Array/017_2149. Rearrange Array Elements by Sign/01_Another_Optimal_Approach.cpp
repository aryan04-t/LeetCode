// LeetCode (2149. Rearrange Array Elements by Sign): 
// https://leetcode.com/problems/rearrange-array-elements-by-sign/ 


#include<vector> 
using namespace std; 


class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {

        int n = nums.size();
        
        int positive = 0; 
        int negative = 1; 
        
        vector<int> ans(n);
        
        for(int i=0; i < n; i++){
            if(nums[i] > 0){
                ans[positive] = nums[i];
                positive +=2;
            }
            else{
                ans[negative] = nums[i];
                negative += 2;
            }
        }

        return ans;

    }
};


// T.C. = O(n) + O(n) = O(2n) = O(n) 
// S.C. = O(n) 

// Here, n = total number of elements which are present inside the input vector named "nums" 