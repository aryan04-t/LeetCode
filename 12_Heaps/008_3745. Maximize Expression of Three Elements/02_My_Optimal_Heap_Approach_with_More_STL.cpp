// LeetCode (3745. Maximize Expression of Three Elements): 
// https://leetcode.com/problems/maximize-expression-of-three-elements 


#include<vector>
#include<queue>
#include<algorithm>
using namespace std;


using MinHeap = priority_queue<int, vector<int>, greater<int>>;


class Solution {
public:
    int maximizeExpressionOfThree(vector<int>& nums) {
        
        int n = nums.size();

        MinHeap minHeap;
        int heapMaxSize = 2;
        
        vector<int>::iterator it = min_element(nums.begin(), nums.end());
        int mini = *it;

        for (int i=0; i < n; i++) {
            
            int num = nums[i];

            if (minHeap.size() != heapMaxSize) {
                minHeap.push(num);
            }
            else if (num > minHeap.top()) {
                minHeap.pop();
                minHeap.push(num);
            }
        }

        int maxiTwo = minHeap.top();
        minHeap.pop();

        int maxiOne = minHeap.top();
        minHeap.pop();

        return (maxiOne + maxiTwo - mini); 
    }
};


// T.C. = O(n) + O(n * (log(2) to the base 2)) = O(n) 
// S.C. = O(1)  

// Here, n = the length of input vector named "nums" 