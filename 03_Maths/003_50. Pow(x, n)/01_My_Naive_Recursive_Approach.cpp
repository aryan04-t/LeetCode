// LeetCode (50. Pow(x, n)): 
// https://leetcode.com/problems/powx-n/ 


#include<cstdlib>
using namespace std;


class Solution {
public:

    double getPositivePower(double x, int n){

        if(n == 0){
            return 1.0; 
        }

        return x * getPositivePower(x, n-1); 

    }

    double getNegativePower(double x, int n){

        if(n == 0){
            return 1.0; 
        }

        return x * getNegativePower(x, n+1); 

    }

    double myPow(double x, int n) {

        if(x == 1.0) return x; 
        if(n == 0) return 1.0; 

        if(n > 0){
            return getPositivePower(x, n); 
        }
        else{
            return 1.0 / getNegativePower(x, n); 
        }

    }

};


// T.C. = O(n) 
// S.C. = O(n) -> This space complexity is caused due to function call stack 

// Here, n = the value of input variable named "n" 