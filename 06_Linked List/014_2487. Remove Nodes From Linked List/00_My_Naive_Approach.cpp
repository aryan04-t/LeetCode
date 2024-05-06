// LeetCode (2487. Remove Nodes From Linked List): 
// https://leetcode.com/problems/remove-nodes-from-linked-list/ 


#include<vector> 
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

    void freeUpMemory(vector<ListNode*> &uselessNodes){
        for(ListNode* node : uselessNodes){
            node->next = nullptr;
            delete node;
        }
    }

    ListNode* removeNodes(ListNode* head) {

        ListNode* newHead = nullptr;
        ListNode* newTail = nullptr;

        ListNode* temp = head; 
        vector<ListNode*> uselessNodes; 

        while(temp != nullptr){
            ListNode* runner = temp->next; 
            while(runner != nullptr){
                if(runner->val > temp->val){
                    break;
                }
                runner = runner->next; 
            }
            if(runner == nullptr){
                if(newHead == nullptr){
                    newHead = temp; 
                    newTail = temp; 
                }
                else{
                    newTail->next = temp; 
                    newTail = newTail->next; 
                }
            }
            else{
                uselessNodes.push_back(temp); 
            }
            temp = temp->next; 
        }

        freeUpMemory(uselessNodes); 

        return newHead; 
    }
};


// T.C. = O((n * (n-1)) / 2) + O(n) = O(n^2) + O(n) = O(n^2) 
// S.C. = O(n) 

// Here, n = the total number of nodes which are present inside the given "singly linked list" 