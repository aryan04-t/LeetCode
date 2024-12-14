// LeetCode (2535. Difference Between Element Sum and Digit Sum of an Array): 
// https://leetcode.com/problems/difference-between-element-sum-and-digit-sum-of-an-array 


#include<vector> 
using namespace std; 


class Solution {
public:

    int differenceOfSum(vector<int>& nums) {

        int elementSum = 0; 
        int digitSum = 0; 

        for (int currNum : nums) {
            elementSum += currNum; 
            while (currNum) {
                short digit = currNum % 10; 
                digitSum += digit; 
                currNum /= 10; 
            }
        }

        return abs(elementSum - digitSum); 
    } 
}; 


// T.C. = O(n * (log(m) to the base 10)) = O(n*k) 
// S.C. = O(1) 

// Here, n = the length of 1-D input vector named "nums", m = average value of all numbers which are present in "nums" vector, and k = average number of digits of all the numbers present "nums" vector 