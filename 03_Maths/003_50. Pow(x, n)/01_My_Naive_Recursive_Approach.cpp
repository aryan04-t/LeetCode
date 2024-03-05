// LeetCode (50. Pow(x, n)): 
// https://leetcode.com/problems/powx-n/ 


#include<cstdlib>
using namespace std;


class Solution {
public:

    double getPositivePow(double x, int n){

        if(n == 0) return 1.0; 

        return x * myPow(x, n-1); 

    }

    double myPow(double x, int n) {

        if(n >= 0){
            return getPositivePow(x, n);
        }
        else{
            n = abs(n);
            double ans = 1.0;
            double power = getPositivePow(x, n);
            return ans / power;
        }
        
    }

};