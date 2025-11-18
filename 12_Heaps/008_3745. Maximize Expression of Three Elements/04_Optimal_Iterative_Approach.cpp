// LeetCode (3745. Maximize Expression of Three Elements): 
// https://leetcode.com/problems/maximize-expression-of-three-elements 


#include<vector>
#include<climits>
using namespace std;


class Solution {
public:
    int maximizeExpressionOfThree(vector<int>& nums) {
        
        int mini = INT_MAX;
        int maxiOne = INT_MIN;
        int maxiTwo = INT_MIN;

        int n = nums.size();

        for (int i=0; i < n; i++) {
            int num = nums[i];

            // Finding the top two maximum elements
            if (num > maxiOne) {
                maxiTwo = maxiOne;
                maxiOne = num;
            }
            else if (num > maxiTwo) {
                maxiTwo = num;
            }

            // Finding the most minimum element 
            if (num < mini) mini = num;
        }

        return (maxiOne + maxiTwo - mini);
    }
};


/*
    #Intuition: 
      - The main catch here is finding 2 most maximum numbers in 1 iteration, else everything is easy. 
      - So, to achieve the tough part - we make sure that the variable maxiTwo should always have the 2nd most maximum value till the range processed, and maxiOne should have the most maximum value till the range processed 
      - The catch here is the intuition that if we find current number to be greater than the most maximum number maxiOne, then the current value of maxiOne will for sure be the next suitable value for maxiTwo variable 
      - And by using this basic intuition to fill in positions in a optimal manner by shifting - we achieved this optimal code
*/


// T.C. = O(n) 
// S.C. = O(1) 

// Here, n = the length of input vector named "nums" 
