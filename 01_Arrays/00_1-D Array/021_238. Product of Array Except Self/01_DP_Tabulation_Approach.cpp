// LeetCode (238. Product of Array Except Self): 
// https://leetcode.com/problems/product-of-array-except-self/ 


#include<vector>
using namespace std; 


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<int> ans(n);
        vector<int> left_product(n);
        vector<int> right_product(n);

        left_product[0] = 1;

        for(int i=1; i < n; i++){
            left_product[i] = left_product[i-1] * nums[i-1];
        }

        right_product[n-1] = 1;
        
        for(int i=n-2; i >= 0; i--){
            right_product[i] = right_product[i+1] * nums[i+1];
        }

        for(int i=0; i < n; i++){
            ans[i] = left_product[i] * right_product[i];
        }

        return ans;

    }
};


// T.C. = O(6n) = O(n)
// S.C. = O(3n) = O(n)

// Here, n = total number of elements which are present inside the input vector named nums 