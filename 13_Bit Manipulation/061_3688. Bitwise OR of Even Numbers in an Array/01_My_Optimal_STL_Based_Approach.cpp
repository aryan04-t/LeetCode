// LeetCode (3688. Bitwise OR of Even Numbers in an Array): 
// https://leetcode.com/problems/bitwise-or-of-even-numbers-in-an-array 


#include<vector>
#include<numeric>
using namespace std;


class Solution {
public:
    int evenNumberBitwiseORs(vector<int>& nums) {
        
        int allOred = accumulate(
            nums.begin(),
            nums.end(),
            0,
            [](int ans, int num) {
                bool isEven = !(num & 1);
                if (isEven) ans |= num;
                return ans;
            }
        );

        return allOred;
    }
};


// T.C. = O(n) 
// S.C. = O(1) 

// Here, n = the length of input vector named "nums" 