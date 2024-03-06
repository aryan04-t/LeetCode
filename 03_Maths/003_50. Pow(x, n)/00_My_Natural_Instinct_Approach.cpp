// LeetCode (50. Pow(x, n)): 
// https://leetcode.com/problems/powx-n/ 


#include<cmath>
using namespace std;


class Solution {
public:

    double myPow(double x, int n) {

        return pow(x, n);

    }

};


// T.C. = O(log(n) to the base 2) 
// S.C. = O(1) 

// Here, n = the value of input variable named "n" 