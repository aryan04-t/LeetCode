// 29. Divide Two Integers (29. Divide Two Integers): 
// https://leetcode.com/problems/divide-two-integers/ 

 
#include<limits.h> 
using namespace std; 


class Solution {
public: 

    int divide(int dividend, int divisor) {

        long long Dividend = dividend; 
        long long Divisor = divisor; 

        long long ans = Dividend/Divisor; 

        if(ans > INT_MAX) ans = INT_MAX;
        else if(ans < INT_MIN) ans = INT_MIN; 

        int finalAns = int(ans); 

        return finalAns; 
    }
};


// Illegal Approach for this Question 