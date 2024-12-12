// LeetCode (2558. Take Gifts From the Richest Pile): 
// https://leetcode.com/problems/take-gifts-from-the-richest-pile 


#include<vector> 
#include<queue> 
#include<cmath> 
using namespace std; 


class Solution {
public:

    long long pickGifts(vector<int>& gifts, int k) {

        int n = gifts.size(); 
        priority_queue<int> maxHeap(gifts.begin(), gifts.end()); 

        while (k--) {
            int maxGiftsPile = maxHeap.top(); 
            maxHeap.pop(); 
            int afterOperationPile = static_cast<int>(floor(sqrt(maxGiftsPile))); 
            maxHeap.push(afterOperationPile); 
        }

        long long sum = 0; 

        while (!maxHeap.empty()) {
            int maxElement = maxHeap.top(); 
            maxHeap.pop(); 
            sum += maxElement; 
        }

        return sum; 
    }
}; 


// T.C. = O(n*log(n)) + O(k*log(n)) + O(n*log(n)) = O(3*n*log(n)) [k == n in worst case as per constraints] = O(n*log(n)) 
// S.C. = O(n) 

// Here, n = the length of input vector named "gifts", and k = the value of input variable named "k" 