// LeetCode (2816. Double a Number Represented as a Linked List): 
// https://leetcode.com/problems/double-a-number-represented-as-a-linked-list/ 


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

    ListNode* reverseLL(ListNode* head){

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

    ListNode* doubleIt(ListNode* head) {
        
        ListNode* reversedHead = reverseLL(head); 
    
        ListNode* temp = reversedHead; 
        int carry = 0;

        while(temp != nullptr){
            int value = 2 * temp->val + carry; 
            int digit = value % 10; 
            carry = value / 10; 
            temp->val = digit; 
            temp = temp->next; 
        }

        if(carry){
            ListNode* carryNode = new ListNode(1); 
            head->next = carryNode; 
            head = head->next; 
        }

        reverseLL(reversedHead); 
        return head; 
    }
};


// T.C. = O(n) + O(n) + O(n) = O(3n) = O(n) 
// S.C. = O(1) 

// Here, n = the total number of nodes which are present inside the given "singly-linked-list" 