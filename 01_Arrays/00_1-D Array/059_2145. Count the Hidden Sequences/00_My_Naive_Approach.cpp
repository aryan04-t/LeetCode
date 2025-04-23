// LeetCode (2145. Count the Hidden Sequences): 
// https://leetcode.com/problems/count-the-hidden-sequences 


// Gives TLE 


#include<vector> 
#include<algorithm>
using namespace std;  


class Solution {
public:

    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        
        int n = differences.size(); 
        int countHiddenSeq = 0; 
        int i = lower; 

        while (i <= upper) {
            int j = i; 
            int hiddenNumsCount = 1; 
            for (int val : differences) {
                int newHiddenNum = j + val;
                if (newHiddenNum < lower || newHiddenNum > upper) {
                    break;
                }
                hiddenNumsCount++; 
                if (hiddenNumsCount == n+1) countHiddenSeq++;
                j += val; 
            }
            i++;
        }

        return countHiddenSeq; 
    }
};


// T.C. = O(m*n) 
// S.C. = O(1) 

// Here, n = the length of array "differences", and m = (upper - lower + 1) 