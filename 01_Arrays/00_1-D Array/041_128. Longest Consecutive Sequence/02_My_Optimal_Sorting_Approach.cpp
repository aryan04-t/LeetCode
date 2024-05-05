// LeetCode (128. Longest Consecutive Sequence): 
// https://leetcode.com/problems/longest-consecutive-sequence/ 


#include<vector> 
#include<algorithm> 
using namespace std; 


class Solution {
public:

    int longestConsecutive(vector<int>& nums) {

        sort(nums.begin(), nums.end()); 

        int n = nums.size(); 
        int i = 0; 
        int finalAns = 0; 

        while(i < n){
            int sequenceLen = 1;
            while(i < n){
                int val = nums[i++]; 
                while(i < n && nums[i] == val) i++; 
                if(i == n || val+1 != nums[i]) break; 
                sequenceLen++;
            }
            if(sequenceLen > finalAns) finalAns = sequenceLen; 
        }

        return finalAns; 
    }
}; 


// T.C. = O(n * log(n)) + O(n) 
// S.C. = O(log(n)) 

// Here, n = the total number of elements which are present inside the input vector named "nums" 