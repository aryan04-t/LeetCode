// LeetCode (611. Valid Triangle Number): 
// https://leetcode.com/problems/valid-triangle-number 


#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
    // Finding the 1st value which is greater than the target 
    int upperBoundBinarySearch(
        const vector<int> &nums,
        int start,
        int end,
        int target
    ) {
        while (start <= end) {
            int mid = start + (end - start)/2;

            if (target == nums[mid]) start = mid + 1;
            else if (target > nums[mid]) start = mid + 1;
            else if (target < nums[mid]) end = mid - 1;
        }

        return start;
    }

    int triangleNumber(vector<int>& nums) {
        
        int n = nums.size();
        int totalValidTriangles = 0;

        sort(nums.begin(), nums.end());

        for (int i=0; i < n-2; i++) {
            
            if (nums[i] == 0) continue;
            
            for (int j=i+1; j < n-1; j++) {
                
                if (nums[j] == 0) continue;
                
                int upperBound = nums[i] + nums[j] - 1;
                int upperBoundIdx = upperBoundBinarySearch(nums, 0, n-1, upperBound);

                int validTriangles = upperBoundIdx - j - 1;

                totalValidTriangles += validTriangles;
            }
        }

        return totalValidTriangles;
    }
};


/*
  # This Approach Relies on The Property: 
    - if a, b and c are 3 lines 
    - And if ((a + b > c) && (a < b < c)) then a, b and c can form a valid triangle 

  # Implementation: 
    - By sorting the element we're achieving the order (a < b < c) 
    - And now as the elements are sorted and we have a and b elements by running n^2 loop, we're using binary search to find the max value of c element to satisfy (a + b > c) condition 
    - And by using this sorting and binary search approach we are improving time complexity of naive approach for finding all valid triangle forming triplets 
*/


// T.C. = O(n*(log(n))) + O(n^2 * log(n)) = O(n^2 * log(n)) 
// S.C. = O(log(n)) 

// Here, n = the length of input vector named "nums" 