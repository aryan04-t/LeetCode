// 29. Divide Two Integers (29. Divide Two Integers): 
// https://leetcode.com/problems/divide-two-integers/ 

 
#include<limits.h> 
using namespace std; 


class Solution {
public:

    int divide(int dividend, int divisor) {

        if(dividend == 0) return 0; 

        bool isDividendNegative = false; 
        bool isDivisorNegative = false; 

        long long Dividend = dividend;
        long long Divisor = divisor;

        if(Dividend < 0){
            if(Divisor < 0){
                Dividend = -1 * Dividend; 
                Divisor = -1 * Divisor; 
            }
            else{
                Dividend = -1 * Dividend; 
                isDividendNegative = true; 
            }
        }
        else{
            if(Divisor < 0){
                Divisor = -1 * Divisor; 
                isDivisorNegative = true; 
            }
        }

        long long ans = 0;

        while(Dividend >= Divisor){
            Dividend -= Divisor; 
            ans++; 
        }

        if(isDividendNegative || isDivisorNegative){
            ans = -1 * ans; 
        }

        if(ans > INT_MAX) ans = INT_MAX;
        else if(ans < INT_MIN) ans = INT_MIN; 

        int finalAns = int(ans); 

        return finalAns; 
    }
};


// T.C. = O(n/m) 
// S.C. = O(1) 

// Here, n = the value of input variable named "dividend", and m = the value of input variable named "divisor" 