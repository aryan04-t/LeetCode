// LeetCode (3684. Maximize Sum of At Most K Distinct Elements): 
// https://leetcode.com/problems/maximize-sum-of-at-most-k-distinct-elements 


#include<vector>
#include<queue>
#include<unordered_set>
using namespace std;


using MinHeap = priority_queue<int, vector<int>, greater<int>>;


class Solution {
public:

    vector<int> buildAnsArrFromHeap(MinHeap &minHeap) {

        int minHeapSize = minHeap.size();
        vector<int> ans(minHeapSize);

        int i = minHeapSize - 1;

        while (!minHeap.empty()) {
            ans[i--] = minHeap.top();
            minHeap.pop();
        }

        return ans;
    }

    vector<int> maxKDistinct(vector<int>& nums, int k) {
        
        unordered_set<int> st; 
        // Hash set will help maintain disctinct elements in heap 

        MinHeap minHeap; 
        // Heap will contain distinct k largest elements in the range 

        int i = 0;
        int n = nums.size();
        int tempK = k;

        while (tempK != 0 && i < n) {
            int num = nums[i];
            if (st.count(num) == 0) {
                st.insert(num);
                minHeap.push(num);
                tempK--;
            }
            i++;
        }

        if (i == n) return buildAnsArrFromHeap(minHeap);

        while (i < n) {
            int num = nums[i];
            int kthLargestElement = minHeap.top();
            if (st.count(num) == 0 && num > kthLargestElement) {
                // Remove smallest number from the k largest elements of range 
                st.erase(kthLargestElement);
                minHeap.pop();

                // Insert the new member of k largest elements of range 
                st.insert(num);
                minHeap.push(num);
            }
            i++;
        }

        return buildAnsArrFromHeap(minHeap);
    }
};


// T.C. = O(n*log(k)) = O(n*log(n)) 
// S.C. = O(k) = O(n) 

// Here, n = the length of input vector named "nums", k = the input interger named "k", and in worst case k == n 