// LeetCode (69. Sqrt(x)): 
// https://leetcode.com/problems/sqrtx/ 


class Solution { 
public: 
    int mySqrt(int x) { 
        
        if(x == 0) return 0;
        if(x == 1) return 1;


        int start = 1;
        int end = x;
        
        long long mid;
        long long midSquare;
        
        
        while(start <= end){
            
            mid =  start + (end - start)/2;
            midSquare = mid * mid;

            if(midSquare == x){ 
                return mid;
            }
            else if(midSquare > x){
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }

        }

        return end;

    }
};


// T.C. = O(log(n) to the base 2) 
// S.C. = O(1) 

// Here, n = value of input number named "x" 