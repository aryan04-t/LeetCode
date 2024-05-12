// LeetCode (86. Partition List): 
// https://leetcode.com/problems/partition-list/ 


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

    ListNode* partition(ListNode* head, int x) {

        ListNode* temp = head;
        ListNode *firstHalfHead = nullptr, *firstHalfTail = nullptr;        
        ListNode *secondHalfHead = nullptr, *secondHalfTail = nullptr;        
    
        while(temp != nullptr){
            if(temp->val < x){
                if(firstHalfHead == nullptr){
                    firstHalfHead = temp; 
                    firstHalfTail = temp; 
                }
                else{
                    firstHalfTail->next = temp;
                    firstHalfTail = firstHalfTail->next;
                }
            }
            else{
                if(secondHalfHead == nullptr){
                    secondHalfHead = temp; 
                    secondHalfTail = temp; 
                }
                else{
                    secondHalfTail->next = temp;
                    secondHalfTail = secondHalfTail->next;
                }
            }
            temp = temp->next; 
        }

        if(firstHalfTail != nullptr) firstHalfTail->next = secondHalfHead; 
        if(secondHalfTail != nullptr) secondHalfTail->next = nullptr; 

        if(firstHalfHead != nullptr) return firstHalfHead; 
        else return secondHalfHead; 
    }
};


// T.C. = O(n) 
// S.C. = O(1) 

// Here, n = the total number of nodes which are present inside the given singly-linked list 