// LeetCode (128. Longest Consecutive Sequence): 
// https://leetcode.com/problems/longest-consecutive-sequence/ 


#include<vector> 
#include<algorithm> 
using namespace std; 


class Solution {
public:

    int longestConsecutive(vector<int>& nums) {

        int n = nums.size(); 
        if(n == 0) return 0; 

        sort(nums.begin(), nums.end()); 

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

        /*

        // You can also write above while loop's logic using for loop also, like this: 

        int sequenceLen = 1; 

        for(int i=0; i < n-1; i++){
            if(nums[i] != nums[i+1]){
                if(nums[i]+1 == nums[i+1]){
                    sequenceLen++; 
                }
                else{
                    finalAns = max(finalAns, sequenceLen); 
                    sequenceLen = 1;
                }
            }
        }

        finalAns = max(finalAns, sequenceLen); 

        */

        return finalAns; 
    }
}; 


// T.C. = O(n * log(n)) + O(n) = O(n * log(n)) 
// S.C. = O(log(n)) 

// Here, n = the total number of elements which are present inside the input vector named "nums" 