// LeetCode (61. Rotate List): 
// https://leetcode.com/problems/rotate-list/ 


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

    int getLength(ListNode* temp){
        
        int len = 0;
        
        while(temp){
            len++;
            temp = temp->next;
        }

        return len;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        
        int len = getLength(head);

        if(k == 0 || len == 0){
            return head;
        }

        k = k % len;
        
        if(k == 0){
            return head;
        }

        ListNode* windowStart = head;
        ListNode* windowEnd = head;

        while(k--){
            windowEnd = windowEnd->next;
        }

        while(windowEnd->next != nullptr){
            windowStart = windowStart->next;
            windowEnd = windowEnd->next;
        }

        windowEnd->next = head;
        head = windowStart->next;
        windowStart->next = nullptr;

        return head;

    }
};


// T.C. = O(n) + O(n) = O(n) 
// S.C. = O(1) 

// Here, n = total number of nodes which are present inside the singly linked list 