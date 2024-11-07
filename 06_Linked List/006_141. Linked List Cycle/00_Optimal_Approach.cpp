// LeetCode (141. Linked List Cycle): 
// https://leetcode.com/problems/linked-list-cycle/ 


#include<iostream> 
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


// - - - - - - - - - - 


/*
    Definition for singly-linked list.
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };
*/


class Solution {
public:
    bool hasCycle(ListNode *head) {

        if(head == NULL){
            return false;
        }

        if(head->next == NULL){
            return false;
        }
        else if(head->next == head){
            return true;
        }
        else{
            
            ListNode* slow = head;
            ListNode* fast = head;
            
            while(fast != NULL && fast->next != NULL){
                
                fast = fast->next->next;
                slow = slow->next;

                if(fast == slow){
                    return true;
                }
            }
        }

        return false;
    }
};


// T.C. = O(n) 
// S.C. = O(1) 

// Here, n = total number of nodes which are present inside the singly linked list. 