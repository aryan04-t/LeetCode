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

    void backtracking(ListNode* head, int &pow, int &num){

        if(head == nullptr) return; 
        
        backtracking(head->next, pow, num); 

        num += pow * head->val; 
        pow *= 2; 
    }

    int getDecimalValue(ListNode* head) {

        int pow = 1; 
        int num = 0; 
        backtracking(head, pow, num); 

        return num; 
    }
};


// T.C. = O(n) 
// S.C. = O(n) -> (This space complexity is caused due to the function call stack) 

// Here, n = the total number of nodes which are present inside the input "singly linked list" 