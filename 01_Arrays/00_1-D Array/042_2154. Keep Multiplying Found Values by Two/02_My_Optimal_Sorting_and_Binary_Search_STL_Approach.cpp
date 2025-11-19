// LeetCode (2154. Keep Multiplying Found Values by Two): 
// https://leetcode.com/problems/keep-multiplying-found-values-by-two/ 


#include<vector> 
#include<algorithm> 
using namespace std;


class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        
        sort(nums.begin(), nums.end());

        while (binary_search(nums.begin(), nums.end(), original)) {
            original *= 2;
        }

        return original;
    }
};


// T.C. = O(n*log(n)) + O(n*log(n)) = O(2*n*log(n)) = O(n*log(n)) 
// S.C. = O(log(n)) -> contributed by C++ intro-sort 

// Here, n = the length of input vector named named "nums" 