// LeetCode (2554. Maximum Number of Integers to Choose From a Range I): 
// https://leetcode.com/problems/maximum-number-of-integers-to-choose-from-a-range-i 


#include<vector> 
#include<algorithm> 
using namespace std; 


class Solution {
public:

    int maxCount(vector<int>& banned, int n, int maxSum) {

        sort(banned.begin(), banned.end()); 

        int i = 1, j = 0, m = banned.size(), sum = 0, numCount = 0; 

        while (i <= n) {
            if (sum >= maxSum) break; 
            if (j >= m || i != banned[j]) {
                sum += i; 
                numCount++; 
            }
            else while (j < m && i == banned[j]) j++; 
            i++; 
        }

        if (sum > maxSum) numCount--; 

        return numCount; 
    }
}; 


// T.C. = O(m*log(m)) + O(n + m) = O(max(m*log(m), n+m)) 
// S.C. = O(log(m)) -> s.c. used by c++'s intro-sort 

// Here, m = the length of 1-D input vector named "banned", and n = the value of input variable named "n" 