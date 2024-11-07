// LeetCode (264. Ugly Number II): 
// https://leetcode.com/problems/ugly-number-ii/ 


// This space optimized naive approach of mine also gives TLE Error, but this one passes 4 more test cases then the earlier one ;) 


#include<vector> 
using namespace std; 


class Solution {
public:

    bool numIsUgly(int num){

        vector<int> factors{2, 3, 5}; 
        
        int i = 0;
        while(num != 1){
            while(num % factors[i] == 0){
                num /= factors[i]; 
            } 
            i++; 
            if(i == 3) break; 
        }

        if(num != 1) return false; 
        else return true; 
    }

    int nthUglyNumber(int n) {

        int uglyNumber = -1; 
        int i = 0; 
        int num = 1; 

        while(i < n){
            if(numIsUgly(num)){
                uglyNumber = num; 
                i++; 
            }
            num++; 
        }

        return uglyNumber; 
    }
}; 


// T.C. = O(k * log(k)) 
// S.C. = O(1) 

// Here, n = the value of input variable named "n", and k = the value of nth Ugly Number 