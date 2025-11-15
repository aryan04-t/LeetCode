// LeetCode (167. Two Sum II - Input Array Is Sorted) 
// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted 


#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        int n = numbers.size();

        for (int i=0; i < n-1; i++) {
            
            int val = numbers[i];
            int complement = target - val;

            vector<int>::iterator it = lower_bound(
                numbers.begin() + i + 1,
                numbers.end(),
                complement
            );

            if (it != numbers.end() && *it == complement) {
                int compIdx = it - numbers.begin();
                return { i + 1 , compIdx + 1 };
            }
        }

        return {};
    }
};


// T.C. = O(n*log(n)) 
// S.C. = O(1) 

// Here, n = the length of input vector named "numbers" 