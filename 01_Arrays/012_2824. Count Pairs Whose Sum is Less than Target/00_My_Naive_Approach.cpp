// LeetCode (2824. Count Pairs Whose Sum is Less than Target): 
// https://leetcode.com/problems/count-pairs-whose-sum-is-less-than-target/ 


#include<vector> 
using namespace std; 


class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        
        int n = nums.size();
        int count = 0;

        for(int i=0; i < n-1; i++){
            for(int j=i+1; j < n; j++){
                if((nums[i] + nums[j]) < target){
                    count++;
                }
            }
        }

        return count;
    }
};


// T.C. = O((n * (n-1))/2) = O(n^2) 
// S.C. = O(1) 

// Here, n = number of elements which are present inside the input vector named "nums" 