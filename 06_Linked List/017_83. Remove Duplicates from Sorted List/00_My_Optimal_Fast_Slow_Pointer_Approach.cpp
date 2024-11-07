// LeetCode (83. Remove Duplicates from Sorted List): 
// https://leetcode.com/problems/remove-duplicates-from-sorted-list/ 


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
    ListNode* deleteDuplicates(ListNode* head) {

        if(head == nullptr) return nullptr; 
        if(head->next == nullptr) return head; 

        ListNode* slow = head;
        ListNode* fast = head->next; 

        while(fast != nullptr){
            if(slow->val == fast->val){
                ListNode* temp = fast; 
                fast = fast->next; 
                delete temp; 
            } 
            else{
                slow->next = fast; 
                slow = slow->next; 
                fast = fast->next; 
            }
        }

        slow->next = fast; 
        return head; 
    }
};


// T.C. = O(n) 
// S.C. = O(1) 

// Here, n = the total number of nodes which are present inside the given singly-linked list