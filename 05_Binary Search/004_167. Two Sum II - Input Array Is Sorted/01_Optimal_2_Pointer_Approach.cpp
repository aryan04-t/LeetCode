// LeetCode (167. Two Sum II - Input Array Is Sorted): 
// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/ 


#include<vector> 
using namespace std; 


class Solution {
public:

    vector<int> twoSum(vector<int>& numbers, int target) {
        
        int n = numbers.size(); 
        int start = 0;
        int end = n-1;
        
        vector<int> ans{0,0}; 

        while(start < end){
            
            if(numbers[start] + numbers[end] == target){
                ans[0] = start+1;
                ans[1] = end+1;
                return ans;
            }
            else if(numbers[start] + numbers[end] > target){
                end--; 
            }
            else if(numbers[start] + numbers[end] < target){
                start++; 
            }

        }

        return ans; 

    }
};


// T.C. = O(n) 
// S.C. = O(1) 

// Here, n = total number of elements which are present inside the input vector named "numbers" 