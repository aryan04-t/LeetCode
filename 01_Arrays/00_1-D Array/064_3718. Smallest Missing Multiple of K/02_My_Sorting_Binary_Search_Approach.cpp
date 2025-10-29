// LeetCode (3718. Smallest Missing Multiple of K) 
// https://leetcode.com/problems/smallest-missing-multiple-of-k 


#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:

    bool binarySearchElement(const vector<int> &nums, int start, int end, int target) {
        
        while (start <= end) {
            int mid = start + (end - start)/2;
            if (nums[mid] == target) return true;
            else if (target < nums[mid]) end = mid - 1;
            else if (target > nums[mid]) start = mid + 1;
        }

        return false;
    }

    int missingMultiple(vector<int>& nums, int k) {
        
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int missingMultiple = k;

        while (true) {
            /*
            // My implemented binary search approach 
            if (!binarySearchElement(nums, 0, n-1, missingMultiple)) {
                return missingMultiple;
            }
            */

            // Stl implemented binary search approach 
            vector<int>::iterator it = lower_bound(nums.begin(), nums.end(), missingMultiple);

            if ((it == nums.end()) || (it != nums.end() && *it != missingMultiple)) {
                return missingMultiple;
            }

            missingMultiple += k;
        }
    }
};


// T.C. = O(n*log(n)) + O(n*log(n)) = O(2*n*log(n)) = O(n*log(n)) 
// S.C. = O(log(n)) 

// Here, n = the length of input vector named "nums" 