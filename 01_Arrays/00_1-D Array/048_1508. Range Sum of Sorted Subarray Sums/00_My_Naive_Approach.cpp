// LeetCode (1508. Range Sum of Sorted Subarray Sums): 
// https://leetcode.com/problems/range-sum-of-sorted-subarray-sums/ 


#include<vector> 
#include<algorithm> 
using namespace std; 


class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        
        vector<int> subarraySum((n * (n+1))/2); 
        int index = 0; 

        for(int i=0; i < n; i++){
            int sum = 0;
            for(int j=i; j < n; j++){
                sum += nums[j]; 
                subarraySum[index++] = sum; 
            }
        }

        sort(subarraySum.begin(), subarraySum.end()); 

        int ans = 0; 
        int mod = 1e9 + 7;
        for(int i=left-1; i < right; i++){
            ans = (ans + subarraySum[i]) % mod; 
        }

        return ans; 
    }
};


// T.C. = O(n^2 * (log(n) to the base 2)) 
// S.C. = O(n^2) 

// Here, n = the total number of integers which are present inside the input vector named "nums" 