// LeetCode (86. Partition List): 
// https://leetcode.com/problems/partition-list/ 


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

    int getLengthOfLL(ListNode* head){
        int len = 0; 
        while(head != nullptr){
            len++; 
            head = head->next; 
        }
        return len; 
    }

    ListNode* partition(ListNode* head, int x) {

        int n = getLengthOfLL(head); 
        if(n == 0) return nullptr; 

        vector<ListNode*> secondHalf(n, nullptr); 
        int i = 0; 

        ListNode* newHead = nullptr; 
        ListNode* newTail = nullptr; 
        ListNode* temp = head; 

        while(temp != nullptr){
            if(temp->val < x){
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
                secondHalf[i++] = temp; 
            }
            temp = temp->next;
        }

        i = 0; 
        while(i < n && secondHalf[i] != nullptr){
            if(newHead == nullptr){
                newHead = secondHalf[i]; 
                newTail = secondHalf[i]; 
            }
            else{
                newTail->next = secondHalf[i]; 
                newTail = newTail->next; 
            }
            i++;
        }
        if(newTail != nullptr) newTail->next = nullptr;
        
        return newHead;
    }
};


// T.C. = O(n) + O(n) + O(n) + O(n) = O(4n) = O(n) 
// S.C. = O(n) 

// Here, n = the total number of nodes which are present inside the given singly-linked list 