// LeetCode (237. Delete Node in a Linked List): 
// https://leetcode.com/problems/delete-node-in-a-linked-list/ 


#include<cstddef> 
using namespace std; 


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


// - - - - - - - - - - 


/*
    Definition for singly-linked list.
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };
*/


class Solution {
public:

    void deleteNode(ListNode* node) {

        node->val = node->next->val; 
        node->next = node->next->next; 
    }
};


// T.C. = O(1) 
// S.C. = O(1) 