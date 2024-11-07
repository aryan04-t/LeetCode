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

    ListNode* removeNodes(ListNode* head) {

        ListNode* temp = reverseLL(head); 

        int maxi = INT_MIN; 
        ListNode* newHead = nullptr; 
        ListNode* newTail = nullptr; 
        
        while(temp != nullptr){

            maxi = max(maxi, temp->val); 

            if(temp->val >= maxi){
                if(newHead == nullptr){
                    newHead = temp; 
                    newTail = temp; 
                }
                else{
                    newTail->next = temp;
                    newTail = newTail->next; 
                }
            }
            
            temp = temp->next; 
        }
        newTail->next = nullptr; 

        newHead = reverseLL(newHead); 

        return newHead; 
    }
};


// T.C. = O(n) + O(n) + O(n) = O(3n) = O(n) 
// S.C. = O(1) 

// Here, n = the total number of nodes which are present inside the given "singly linked list" 