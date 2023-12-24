// LeetCode (Number of Good Pairs): 
// https://leetcode.com/problems/number-of-good-pairs/ 


#include<vector>
using namespace std;


class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        
        int count = 0;
        int n = nums.size();

        for(int i=0; i < n-1; i++){
            for(int j=i+1; j < n; j++){
                if(nums[i] == nums[j]){
                    count++;
                }
            }
        }

        return count;
    }
};


// T.C. = O(n^2) 
// S.C. = O(1) 

// Here, n = number of elements present inside the input vector named "nums" 