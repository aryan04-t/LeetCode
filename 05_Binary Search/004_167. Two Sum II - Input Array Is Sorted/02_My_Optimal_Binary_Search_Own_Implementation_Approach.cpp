// LeetCode (167. Two Sum II - Input Array Is Sorted) 
// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted 


#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
/*
    # lowerBound Func Logic: 
        - if the target is found then its 1st occurence index is returned
        - if the target is not found then the index of 1st greater element than the target is returned 
        - if neither target is present, nor an element greater than the target, then the length of the array is returned 
*/
    int lowerBound(const vector<int> &numbers, int start, int end, int target) {

        while (start <= end) {
            int mid = start + (end - start)/2;
            if (target == numbers[mid]) end = mid - 1;
            else if (target < numbers[mid]) end = mid - 1;
            else if (target > numbers[mid]) start = mid + 1;
        }

        return start;
    }

    vector<int> twoSum(vector<int>& numbers, int target) {
        
        int n = numbers.size();

        for (int i=0; i < n-1; i++) {
            
            int val = numbers[i];
            int complement = target - val;

            int compIdx = lowerBound(
                numbers,
                i + 1,
                n-1,
                complement
            );

            if (compIdx != n && numbers[compIdx] == complement) {
                return { i + 1 , compIdx + 1 };
            }
        }

        return {};
    }
};


// T.C. = O(n*log(n)) 
// S.C. = O(1) 

// Here, n = the length of input vector named "numbers" 