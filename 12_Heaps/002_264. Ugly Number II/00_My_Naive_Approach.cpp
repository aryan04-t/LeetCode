// LeetCode (264. Ugly Number II): 
// https://leetcode.com/problems/ugly-number-ii/ 


// This naive approach of mine gives TLE Error 


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

        vector<int> uglyNumbers(n, -1); 

        int i = 0; 
        int num = 1; 

        while(i < n){
            if(numIsUgly(num)){
                uglyNumbers[i] = num; 
                i++; 
            }
            num++; 
        }

        return uglyNumbers[n-1]; 
    }
};


/*

# Determining Time Complexity of My Above Code which I have written using my Naive Approach: 

1. The while loop in nthUglyNumber() function runs until it finds the nth Ugly Number, when n = 387, the 387th ugly number is 262440 
2. So, the while loop runs 262440 times, and each value from 1 to 262440 is passed to the function numIsUgly() to check whether the current number is ugly or not 
3. The numIsUgly() function in takes log(num) time to determine whether current num is ugly or not 
4. Basically, log(1) + log(2) + ... + log(nth Ugly Number) is  the time complexity of our code, lets say the nth Ugly Number is denoted by k 
5. Therefore, log(1) + log(2) + ... + log(k) = log(1 * 2 * ... * k) = log(k!) 
6. Using ChatGPT I got to know that using advanced maths concept like "Stirling's approximation" we can calculate that log(k!) = k * log(k) 
7. And are log(k!) and k * log(k) equal?? To understand this even nicely you can use a graph plotter website like https://www.transum.org/Maths/Activity/Graph/Desmos.asp 
8. And here in this graph you can plot both the graphs and you can check by seeing the visualization that yess, log(k!) = k * log(k) 

*/


// T.C. = O(k * log(k)) 
// S.C. = O(n) 

// Here, n = the value of input variable named "n", and k = the value of nth Ugly Number 