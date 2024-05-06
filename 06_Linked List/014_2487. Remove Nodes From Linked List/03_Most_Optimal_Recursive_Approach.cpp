// LeetCode (2487. Remove Nodes From Linked List): 
// https://leetcode.com/problems/remove-nodes-from-linked-list/ 


#include<algorithm> 
#include<limits.h> 
using namespace std; 


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

    void recursiveReverseTraverse(ListNode* head, ListNode* &newHead, ListNode* &newTail, int &maxi){

        if(head == nullptr) return; 

        recursiveReverseTraverse(head->next, newHead, newTail, maxi); 

        maxi = max(maxi, head->val); 
        if(head->val >= maxi){
            if(newHead == nullptr){
                newHead = head; 
                newTail = head; 
            }
            else{
                newTail->next = head;
                newTail = newTail->next; 
            }
        }
    }
    
    ListNode* removeNodes(ListNode* head) {

        int maxi = INT_MIN; 
        ListNode* newHead = nullptr; 
        ListNode* newTail = nullptr; 
        
        recursiveReverseTraverse(head, newHead, newTail, maxi); 
        newTail->next = nullptr; 

        newHead = reverseLL(newHead); 

        return newHead; 
    }
};


// T.C. = O(n) + O(n) = O(2n) = O(n) 
// S.C. = O(n) -> (this time complexity is caused due to the function call stack) 

// Here, n = the total number of nodes which are present inside the given "singly linked list" 