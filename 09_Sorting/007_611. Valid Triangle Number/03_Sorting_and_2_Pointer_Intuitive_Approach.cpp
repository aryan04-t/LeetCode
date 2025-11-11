// LeetCode (611. Valid Triangle Number): 
// https://leetcode.com/problems/valid-triangle-number 


#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int totalValidTriangles = 0;

        for (int k = n-1; k >= 2; k--) {

            if (nums[k] == 0) continue;
            
            int i = 0;
            int j = k-1;

            while (i < j) {
                if (nums[i] == 0) { i++; continue; }
                if (nums[j] == 0) { j--; continue; }
                if (nums[i] + nums[j] > nums[k]) {
                    int validTriangles = j - i;
                    totalValidTriangles += validTriangles;
                    j--;
                }
                else i++;
            }
        }
    
        return totalValidTriangles;
    }
};


/*
  # This Approach Relies on These Intuitions: 

    - In our previous "Sorting and Binary Search" approach, we:
      * Sorted the array
      * Used binary search to count valid triplets
      * Applied the pattern: (a + b > c) && (a < b < c)
      * Reduced complexity from O(n³) to O(n²·log(n))

    - We used the natural left-to-right iteration and optimized the last loop 
    with binary search (similar to 3Sum logic). Good progress, but we can 
    do better.

    - KEY INSIGHT: The condition (a + b > c) hints at using 2Sum logic!
      * The L.H.S has (a + b) -> sum of two variables
      * The array is already sorted
      * We can apply 2Sum's two-pointer approach to find a and b in O(n)

    - CHALLENGE: We also need to find c while maintaining (a < b < c)
      * Since the array is sorted in non-decreasing order, larger values 
            (valid c values) are on the right side
      * Solution: Traverse from RIGHT to LEFT, fixing c at each step

    - FINAL STRATEGY:
      * Fix c by iterating from the rightmost side
      * For each fixed c, use the remaining left side as search space
      * Apply 2Sum's two-pointer approach to find all valid (a, b) pairs 
            where a + b > c
      * This achieves O(n²) complexity -> better than O(n²·log(n))
*/


// T.C. = O(n^2) 
// S.C. = O(log(n)) 

// Here, n = the length of input vector named "nums" 