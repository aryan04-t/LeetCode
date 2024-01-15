// LeetCode (2. Add Two Numbers): 
// https://leetcode.com/problems/add-two-numbers/ 


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

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        int sum = 0;
        int once_part = 0;
        int carry = 0;

        int digit1 = 0;
        int digit2 = 0;

        ListNode* dummy_head = new ListNode(-1);
        ListNode* ans_tail = dummy_head;

        while(l1 != nullptr || l2 != nullptr || carry == 1){
            
            digit1 = (l1 != nullptr) ? l1->val : 0;
            digit2 = (l2 != nullptr) ? l2->val : 0;

            sum = digit1 + digit2 + carry;
            once_part = sum % 10;
            carry = sum / 10;

            ListNode* newNode = new ListNode(once_part);
            ans_tail->next = newNode;
            ans_tail = newNode;

            l1 = (l1 != nullptr) ? l1->next : nullptr;
            l2 = (l2 != nullptr) ? l2->next : nullptr;
        }

        ListNode* ans_head = dummy_head->next;
        delete dummy_head;
        return ans_head;

    }
};


// T.C. = O(max(n,m)) 
// S.C. = O(max(n,m)) 

// Here, n = total number of nodes which are present inside singly linked list-1 (l1), 
// and m = total number of nodes which are present inside singly linked list-2 (l2) 