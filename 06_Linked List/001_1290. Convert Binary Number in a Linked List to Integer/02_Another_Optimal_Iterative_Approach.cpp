// LeetCode (1290. Convert Binary Number in a Linked List to Integer): 
// https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/ 


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

    int getDecimalValue(ListNode* head) {

        int twos = 1; 
        ListNode* temp = head->next; 
        while(temp != nullptr){
            twos *= 2; 
            temp = temp->next; 
        } 

        int num = 0; 
        temp = head; 
        while(temp != nullptr){
            num += twos * temp->val; 
            twos /= 2; 
            temp = temp->next; 
        } 

        return num; 
    }
};


// T.C. = O(n) + O(n) = O(2n) = O(n) 
// S.C. = O(1) 

// Here, n = the total number of nodes which are present inside the input "singly linked list" 