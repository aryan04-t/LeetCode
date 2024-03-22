// LeetCode (2130. Maximum Twin Sum of a Linked List): 
// https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/ 


#include<vector> 
#include<algorithm> 
using namespace std; 


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


// - - - - - - - - - - 


/*
    Definition for singly-linked list.
    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };
*/


class Solution {
public:

    int pairSum(ListNode* head) {

        vector<int> values;

        while(head != nullptr){
            values.push_back(head->val);
            head = head->next; 
        }

        int n = values.size(); 
        int maxSum = 0;

        for(int i=0; i < n/2; i++){ 
            int currSum = values[i] + values[n-1-i]; 
            maxSum = max(maxSum, currSum); 
        }

        return maxSum; 

    }
};


// T.C. = O(n) + O(n/2) = O(n) 
// S.C. = O(n) 

// Here, n = the total number of nodes which are present inside the given "singly linked list" 