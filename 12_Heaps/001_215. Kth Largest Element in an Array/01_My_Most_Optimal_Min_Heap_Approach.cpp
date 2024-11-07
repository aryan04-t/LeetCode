// LeetCode (215. Kth Largest Element in an Array): 
// https://leetcode.com/problems/kth-largest-element-in-an-array/ 


#include<vector> 
#include<queue> 
#include<functional> 
using namespace std; 


class Solution {
public:

    int findKthLargest(vector<int>& nums, int k) {

        int n = nums.size(); 
        priority_queue<int, vector<int>, greater<int>> minHeap; 

        int i=0; 
        while(i < k){
            minHeap.push(nums[i]); 
            i++;
        }

        while(i != n){
            if(nums[i] > minHeap.top()){
                minHeap.pop(); 
                minHeap.push(nums[i]);
            }
            i++; 
        }

        return minHeap.top(); 
    }
};


// T.C. = O(k * log(k)) + O((n-k) * (log(k) + log(k))) = O(n * log(k)) 
// S.C. = O(k) 

// Here, n = the total number of elements which are present inside the given input vector named "nums" 