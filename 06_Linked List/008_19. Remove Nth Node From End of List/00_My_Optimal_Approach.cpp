// LeetCode (19. Remove Nth Node From End of List): 
// https://leetcode.com/problems/remove-nth-node-from-end-of-list/ 


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

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        int len = getLengthOfLL(head);

        if(len == n){
            ListNode* toBeDeletedNode = head;
            head = head->next;
            delete toBeDeletedNode; 
            return head;
        }

        int distance = len - n;

        ListNode* prevNode = head;

        int i = 1;
        while(i < distance){
            prevNode = prevNode->next; 
            i++; 
        }

        ListNode* toBeDeletedNode = prevNode->next;
        prevNode->next = prevNode->next->next; 
        delete toBeDeletedNode; 

        return head;
    }
};


// T.C. = O(n) 
// S.C. = O(1) 

// Here, n = total number of nodes which are present inside the singly linked list. 