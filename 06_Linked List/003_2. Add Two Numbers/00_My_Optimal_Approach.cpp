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
        
        int carry = 0;
        int sum = 0;
        int digit = 0;

        ListNode* ans_head = nullptr;
        ListNode* ans_tail = nullptr;

        while(l1 != nullptr && l2 != nullptr){
            
            sum = l1->val + l2->val + carry;
            digit = sum % 10;
            carry = sum / 10;

            ListNode* newNode = new ListNode(digit);

            if(ans_head == nullptr){
                ans_head = newNode;
                ans_tail = newNode;
            }
            else{
                ans_tail->next = newNode;
                ans_tail = newNode;
            }

            l1 = l1->next;
            l2 = l2->next;
        }

        while(l1 != nullptr){
            sum = l1->val + carry;
            digit = sum % 10;
            carry = sum / 10;

            ListNode* newNode = new ListNode(digit);
            ans_tail->next = newNode;
            ans_tail = newNode;

            l1 = l1->next;
        }

        while(l2 !=  nullptr){
            sum = l2->val + carry;
            digit = sum % 10;
            carry = sum / 10;

            ListNode* newNode = new ListNode(digit);
            ans_tail->next = newNode;
            ans_tail = newNode;

            l2 = l2->next;
        }

        if(carry == 1){
            ListNode* newNode = new ListNode(carry);
            ans_tail->next = newNode;
            ans_tail = newNode;
        }

        return ans_head;
    }
}; 


// T.C. = O(max(n,m)) 
// S.C. = O(max(n,m)) 

// Here, n = total number of nodes which are present inside singly linked list-1 (l1), 
// and m = total number of nodes which are present inside singly linked list-2 (l2) 



// This approach which I have coded above is the optimal approach, but my code violates DRY principle of coding 
// DRY = Don't Repeat Yourself 

// That's why checkout the next "Neat and Clean Optimal Approach" code 