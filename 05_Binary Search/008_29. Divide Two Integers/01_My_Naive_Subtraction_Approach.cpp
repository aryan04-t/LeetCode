// 29. Divide Two Integers (29. Divide Two Integers): 
// https://leetcode.com/problems/divide-two-integers/ 


// This Approach Gives "Time Limit Exceeded Error" 


#include<limits.h> 
#include<cstdlib> 
using namespace std; 


class Solution {
public:

    int divide(int dividend, int divisor) {

        if(dividend == 0) return 0; 
        
        bool isPositive = ((dividend < 0) == (divisor < 0)); 

        long long Dividend = labs((long long)dividend);
        long long Divisor = labs((long long)divisor);

        long long ans = 0;

        while(Dividend >= Divisor){
            Dividend -= Divisor; 
            ans++; 
        }

        if(!isPositive) ans = -1 * ans; 

        if(ans > INT_MAX) ans = INT_MAX;
        else if(ans < INT_MIN) ans = INT_MIN; 

        int finalAns = int(ans); 

        return finalAns; 
    }
};


// T.C. = O(n/m) 
// S.C. = O(1) 

// Here, n = the value of input variable named "dividend", and m = the value of input variable named "divisor" 