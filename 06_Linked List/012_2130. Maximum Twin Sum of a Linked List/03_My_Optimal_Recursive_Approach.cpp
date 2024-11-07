// LeetCode (2130. Maximum Twin Sum of a Linked List): 
// https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/ 


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

    int getLengthOfLL(ListNode* temp){

        int len = 0;
        while(temp != nullptr){
            len++; 
            temp = temp->next; 
        }

        return len; 
    }

    void findMaxPairSum(ListNode* &head, ListNode* temp, int &maxSum){

        if(temp == nullptr) return; 

        findMaxPairSum(head, temp->next, maxSum); 

        maxSum = max(maxSum, head->val + temp->val); 
        
        head = head->next; 

    }

    int pairSum(ListNode* head) {

        int n = getLengthOfLL(head); 

        ListNode* temp = head; 
        int i = 0; 

        while(i < n/2){
            temp = temp->next; 
            i++;
        }

        int maxSum = 0; 
        
        findMaxPairSum(head, temp, maxSum); 

        return maxSum;
    }
};


// T.C. = O(n) + O(n/2) + O(n/2) = O(n) 
// S.C. = O(n/2) = (this s.c. is caused by the function call stack) = O(n) 

// Here, n = the total number of nodes which are present inside the given "singly linked list" 