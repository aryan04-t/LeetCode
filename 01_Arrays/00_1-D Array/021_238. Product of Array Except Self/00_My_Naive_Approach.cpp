// LeetCode (238. Product of Array Except Self): 
// https://leetcode.com/problems/product-of-array-except-self/ 


#include<vector>
using namespace std; 


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> ans;

        for(int i=0; i < n; i++){
            
            int ansProduct = 1;

            for(int j=0; j < n; j++){

                if(i == j) continue;
                ansProduct *= nums[j];    

            }

            ans.push_back(ansProduct);

        }

        return ans;

    }
};


// T.C. = O(n^2) 
// S.C. = O(n) 

// Here, n = total number of elements which are present inside the input vector named nums 