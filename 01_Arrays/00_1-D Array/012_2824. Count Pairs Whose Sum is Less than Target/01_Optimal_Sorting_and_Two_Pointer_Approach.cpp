// LeetCode (2824. Count Pairs Whose Sum is Less than Target): 
// https://leetcode.com/problems/count-pairs-whose-sum-is-less-than-target/ 


#include<vector> 
#include<algorithm>
using namespace std; 


class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int count = 0;
        int start = 0; 
        int end = n-1;

        while(start < end){
            if((nums[start] + nums[end]) < target){
                count = count + (end - start);
                start++;
            }
            else{
                end--;
            }
        }

        return count;
    }
};


// T.C. = O((n * log(n)) + O(n) = O((n * log(n)) 
// S.C. = O(1) 

// Here, n = number of elements which are present inside the input vector named "nums" 