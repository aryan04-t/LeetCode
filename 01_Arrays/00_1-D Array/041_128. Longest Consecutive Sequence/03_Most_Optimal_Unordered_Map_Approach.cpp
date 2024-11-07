// LeetCode (128. Longest Consecutive Sequence): 
// https://leetcode.com/problems/longest-consecutive-sequence/ 


#include<vector> 
#include<unordered_map> 
using namespace std; 


class Solution {
public:

    int longestConsecutive(vector<int>& nums) {

        int n = nums.size(); 
        unordered_map<int, bool> mp; 

        for(int val : nums) mp[val] = true; 

        for(int val : nums){
            if(mp.find(val-1) != mp.end()){
                mp[val] = false; 
            }
        }

        int finalAns = 0; 

        for(int i=0; i < n; i++){
            if(mp[nums[i]] == true){
                int j = 1; 
                int sequenceLen = 1;
                while(mp.find(nums[i] + j) != mp.end()){
                    j++;
                    sequenceLen++; 
                }
                if(sequenceLen > finalAns) finalAns = sequenceLen; 
            }
        }

        return finalAns; 
    }
};


// T.C. = O(n) + O(n) + O(n) = O(3n) = O(n) 
// S.C. = O(n) 

// Here, n = the total number of elements which are present inside the input vector named "nums" 