// LeetCode (2145. Count the Hidden Sequences): 
// https://leetcode.com/problems/count-the-hidden-sequences 


#include<vector> 
#include<algorithm>
using namespace std;  


class Solution {
public:

    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        
        int n = differences.size(); 
        long long mini = 0; 
        long long maxi = 0; 

        long long x = 0; 

        for (int i=0; i < n; i++) {
            int val = differences[i]; 
            x += static_cast<long long>(val); 
            mini = min(mini, x); 
            maxi = max(maxi, x); 
        }

        int rangeSize = upper - lower + 1; 
        int arrayVerticalHeight = static_cast<int>(maxi - mini); 
        int hiddenSeq = rangeSize - arrayVerticalHeight; 

        return rangeSize <= arrayVerticalHeight ? 0 : hiddenSeq; 
    } 
}; 


// T.C. = O(n) 
// S.C. = O(1) 


// Here, n = the length of array "differences" 