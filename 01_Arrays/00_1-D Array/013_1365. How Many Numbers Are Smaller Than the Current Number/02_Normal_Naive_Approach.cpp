// LeetCode (1365. How Many Numbers Are Smaller Than the Current Number): 
// https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/ 


#include<vector>
using namespace std;


class Solution {
public:

    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> ans;
        int count;

        for(int i=0; i < n; i++){ 
            
            count = 0;
            
            for(int j=0; j < n; j++){
                if(nums[j] < nums[i]){
                    count++;
                }
            }

            ans.push_back(count);

        } 

        return ans;
    }
};


// T.C. = O(n^2) 
// S.C. = O(n) 

// Here, n = number of elements which are present inside the input vector named "nums" 
