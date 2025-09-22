// LeetCode (3688. Bitwise OR of Even Numbers in an Array): 
// https://leetcode.com/problems/bitwise-or-of-even-numbers-in-an-array 


#include<vector>
using namespace std;


class Solution {
public:
    int evenNumberBitwiseORs(vector<int>& nums) {
        int allOred = 0;
        for (int num : nums) {
            bool isEven = !(num & 1);
            if (isEven) allOred |= num;
        }
        return allOred;
    }
};


// T.C. = O(n) 
// S.C. = O(1) 

// Here, n = the length of input vector "nums" 