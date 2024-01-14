// LeetCode (206. Reverse Linked List): 
// https://leetcode.com/problems/reverse-linked-list/ 


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
    
    ListNode* reverseList(ListNode* head) {

        ListNode* prevNode = nullptr;
        ListNode* currNode = head;
        ListNode* nextNode;

        while(currNode != nullptr){
            nextNode = currNode->next;
            currNode->next = prevNode;
            prevNode = currNode;
            currNode = nextNode;
        }

        return prevNode;
    }

};


// T.C. = O(n) 
// S.C. = O(1) 

// Here, n = total number of nodes which are present inside the singly-linked list 