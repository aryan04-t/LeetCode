// LeetCode (3745. Maximize Expression of Three Elements): 
// https://leetcode.com/problems/maximize-expression-of-three-elements 


#include<vector>
#include<climits>
#include<algorithm>
using namespace std;


// I call this approach naive because there was no need of using 2 variables and a swap condition for mimicing the minHeap behaviour and writing this code, the earlier minHeap code was the best already 


class Solution {
public:
    int maximizeExpressionOfThree(vector<int>& nums) {

        int mini = INT_MAX;
        int maxiOne = INT_MIN;
        int maxiTwo = INT_MIN;

        int n = nums.size();

        for (int i=0; i < n; i++) {
            int num = nums[i];
            
            // Finding top two maximum elements
            if (maxiOne == INT_MIN) maxiOne = num;
            else if (maxiTwo == INT_MIN) maxiTwo = num;
            else if (num > maxiTwo) maxiTwo = num;
            
            if (maxiTwo > maxiOne) swap(maxiTwo, maxiOne);

            // Finding the most minimum element 
            if (num < mini) mini = num;
        }

        return (maxiOne + maxiTwo - mini);
    }
};


/*
    # Intuition: 
      - I just felt I can mimic the minHeap behaviour using 2 variables instead of creating a heap of size 2, the time complexity stays same as the last approach, but I wanted to write this logic once, nothing else 
      - Here maxiOne and maxiTwo are representing the minHeap of size 2, and just like minHeap in last code - these 2 variables in same manner will hold max 2 elements which have been seen until the range is processed 
      - The swap() condition will make sure that maxiTwo should behave like top() of minHeap, and maxiOne should behave like bottom of minHeap (We're able to mimic the minHeap of size 2 using 2 variables and a swap condition because the size of minHeap is too small, as the size increases this type of approaches become mess and you should always stick to using a minHeap directly as that keeps the code more readable, understandable and scalable) 
*/


// T.C. = O(n) 
// S.C. = O(1) 

// Here, n = the length of input vector named "nums" 