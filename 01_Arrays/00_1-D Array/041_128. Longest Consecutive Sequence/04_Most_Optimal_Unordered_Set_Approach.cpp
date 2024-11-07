// LeetCode (128. Longest Consecutive Sequence): 
// https://leetcode.com/problems/longest-consecutive-sequence/ 


#include<vector> 
#include<unordered_set> 
using namespace std; 


class Solution {
public:

    int longestConsecutive(vector<int>& nums) {

        int n = nums.size(); 
        unordered_set<int> s; 

        for(int val : nums) s.insert(val); 
        
        int finalAns = 0; 

        for(int i=0; i < n; i++){
            if(s.find(nums[i]-1) == s.end()){
                int val = nums[i];
                int sequenceLen = 1;
                while(s.find(val+1) != s.end()){
                    val++; 
                    sequenceLen++;
                }
                if(sequenceLen > finalAns) finalAns = sequenceLen; 
            }
        }

        return finalAns; 
    }
};


// T.C. = O(n) + O(n) = O(2n) = O(n) 
// S.C. = O(n) 

// Here, n = the total number of elements which are present inside the input vector named "nums" 