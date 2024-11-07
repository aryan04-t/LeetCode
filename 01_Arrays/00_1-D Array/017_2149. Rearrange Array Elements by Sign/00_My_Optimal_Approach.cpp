// LeetCode (2149. Rearrange Array Elements by Sign): 
// https://leetcode.com/problems/rearrange-array-elements-by-sign/ 


#include<vector> 
using namespace std; 


class Solution {
public:

    vector<int> rearrangeArray(vector<int>& nums) {
        
        int n = nums.size(); 

        vector<int> positiveInts; 
        vector<int> negativeInts; 

        for(int i=0; i < n; i++){
            if(nums[i] > 0){
                positiveInts.push_back(nums[i]);
            }
            else{
                negativeInts.push_back(nums[i]);
            }
        }

        vector<int> ans;

        for(int i=0, j=0; i < n; i++){
            if(i & 1){
                ans.push_back(negativeInts[j]); 
                j++;
            }
            else{
                ans.push_back(positiveInts[j]); 
            }
        }

        return ans;

    }
};


// T.C. = O(n) + O(n) = O(2n) = O(n) 
// S.C. = O(n/2) + O(n/2) + O(n) = O(2n) = O(n) 

// Here, n = total number of elements which are present inside the input vector named "nums" 