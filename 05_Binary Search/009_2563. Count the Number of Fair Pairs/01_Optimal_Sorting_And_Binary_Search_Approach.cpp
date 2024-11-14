// LeetCode (2563. Count the Number of Fair Pairs): 
// https://leetcode.com/problems/count-the-number-of-fair-pairs 


class Solution {
public: 

    int binarySearch (vector<int> &nums, int start, int end, int target, bool findLowerBound) {
        
        while (start <= end) {
            int mid = start + ((end - start) / 2); 
            if (nums[mid] == target) (findLowerBound) ? end = mid - 1 : start = mid + 1; 
            else if (target < nums[mid]) end = mid - 1; 
            else if (target > nums[mid]) start = mid + 1; 
        }

        return (findLowerBound) ? start : end; 
    }

    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        
        int n = nums.size(); 
        sort(nums.begin(), nums.end()); 

        long long count = 0; 

        for (int i=0; i < n-1; i++) {
            int lowerComplement = lower - nums[i]; 
            int upperComplement = upper - nums[i]; 
            int lowerBoundIndex = binarySearch(nums, i+1, n-1, lowerComplement, true); 
            int upperBoundIndex = binarySearch(nums, i+1, n-1, upperComplement, false); 
            count += (upperBoundIndex - lowerBoundIndex + 1); 
        } 

        return count; 
    }
};


// T.C. = O(n*log(n)) + O((n-1)*(log(n) + log(n)) = O(n*log(n)) 
// S.C. = O(log(n)) 

// Here, n = total number of elements which are present inside the input vector named "nums" 