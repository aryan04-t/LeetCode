// 29. Divide Two Integers (29. Divide Two Integers): 
// https://leetcode.com/problems/divide-two-integers/ 


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

        long long ans = -1;
        
        long long start = 1;
        long long end = Dividend; 

        while(start <= end){
            
            long long mid = start + (end - start)/2; 

            if(mid * Divisor == Dividend){
                ans = mid;
                break;
            }
            else if(mid * Divisor > Dividend) end = mid - 1;
            else if(mid * Divisor < Dividend) start = mid + 1;  
        }

        if(ans == -1) ans = end;
        if(!isPositive) ans = -1 * ans; 
    
        if(ans > INT_MAX) ans = INT_MAX;
        else if(ans < INT_MIN) ans = INT_MIN; 

        int finalAns = int(ans); 

        return finalAns; 
    }
};


// T.C. = O(log(n)) 
// S.C. = O(1) 

// Here, n = the value of input variable named "dividend" 