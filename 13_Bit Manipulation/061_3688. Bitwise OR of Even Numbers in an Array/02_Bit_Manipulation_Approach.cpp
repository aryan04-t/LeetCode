// LeetCode (3688. Bitwise OR of Even Numbers in an Array): 
// https://leetcode.com/problems/bitwise-or-of-even-numbers-in-an-array 


/*

# Acknowledgement: 

1. I don't find this approach very practical from real life implementation wise, and neither I find this approach to be any better in t.c and s.c as compared to "My Optimal Approach" but still it's a valid intuitive bit-manipulation approach 

2. But for sure this approach catches the essence of bit manipulation OR operator logic catch, that "Once a bit becomes 1 in an OR accumulation, it can never turn back to 0."

3. I will say "My Optimal Approach" is BFS, and this approach is DFS, and the gird is n numbers with each having m number of bits 

*/


#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;


class Solution {
public:
    int evenNumberBitwiseORs(vector<int>& nums) {

        // The solution relies on the fact that in OR accumulation, once a bit is 1, it stays 1 

        // Finding the max element 
        vector<int>::iterator it = max_element(nums.begin(), nums.end());
        int maxNum = *it;

        int maxBits = maxNum == 1 ? 1 : int(ceil(log2(maxNum)));
        // Finding the number of bits required to represent the maxNum in binary 

        int ans = 0;

        for (int ithBit = 0; ithBit <= maxBits; ithBit++) {
            for (int num : nums) {
                
                bool isEven = !(num & 1);
                bool ithBitIsSet = (num >> ithBit) & 1;

                if (isEven && ithBitIsSet) {
                    // if num isEven and its ithBitIsSet 
                    // then we also set the ith bit of ans variable also to 1 
                    ans |= (1 << ithBit);
                    break;
                }
            }
        }

        return ans;
    }
};


// T.C. = O(n) + O(m*n) = O(m*n) 
// S.C. = O(1) 

// Here, n = the length of input vector named "nums", and m = the maximum number of bits required to represent the maximum value number of nums array 