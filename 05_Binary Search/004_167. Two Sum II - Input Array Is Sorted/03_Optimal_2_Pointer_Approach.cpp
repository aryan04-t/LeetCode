// LeetCode (167. Two Sum II - Input Array Is Sorted): 
// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/ 


#include<vector> 
using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        int n = numbers.size();

        int start = 0;
        int end = n - 1;

        while (start < end) {
            
            int sum = numbers[start] + numbers[end];

            if (sum < target) start++;
            else if (sum > target) end--;
            else if (sum == target) break;
        }

        return { start + 1, end + 1 };
    }
};


/*
    # Intuition:
      - The sum equation and sorted order of array is the trigger thought to this approach. 
      - Start pointer begins at index 0 and end pointer at the last index — their numbers form the current sum; if it’s not the target, moving left pointer increases the sum and moving right pointer decreases it, navigate inward until you hit the target pair. 
*/


// T.C. = O(n) 
// S.C. = O(1) 

// Here, n = the length of input vector named "numbers" 