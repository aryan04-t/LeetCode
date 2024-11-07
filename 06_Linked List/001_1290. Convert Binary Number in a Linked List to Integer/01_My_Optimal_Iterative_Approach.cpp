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

    int getDecimalValue(ListNode* head) {

        head = reverseLL(head); 
        ListNode* temp = head; 

        int num = 0; 
        int pow = 1; 
        while(temp != nullptr){
            num += pow * temp->val; 
            pow *= 2; 
            temp = temp->next; 
        }

        return num; 
    }
};


// T.C. = O(n) + O(n) = O(2n) = O(n) 
// S.C. = O(1) 

// Here, n = the total number of nodes which are present inside the input "singly linked list" 