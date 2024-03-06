// LeetCode (50. Pow(x, n)): 
// https://leetcode.com/problems/powx-n/ 


#include<cstdlib>
using namespace std;


class Solution {
public:

    double getPositivePower(double x, int n){

        double power = 1;

        for(int i=0; i < n; i++){
            power = x * power;
        }

        return power;

    }

    double getNegativePower(double x, int n){

        double power = 1;

        for(int i=n; i < 0; i++){
            power = x * power;
        }

        return power;

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
// S.C. = O(1) 

// Here, n = the value of input variable named "n" 