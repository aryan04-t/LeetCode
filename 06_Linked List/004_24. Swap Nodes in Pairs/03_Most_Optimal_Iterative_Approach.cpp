// LeetCode (24. Swap Nodes in Pairs): 
// https://leetcode.com/problems/swap-nodes-in-pairs/ 


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

    ListNode* swapPairs(ListNode* head) {
        
        if(head == nullptr || head->next == nullptr) return head;

        ListNode* dummyNode = new ListNode(-1);
        
        ListNode* prevNode = dummyNode;
        ListNode* currNode = head;

        while(currNode != nullptr && currNode->next != nullptr){
            
            prevNode->next = currNode->next; 
            currNode->next = prevNode->next->next; 
            prevNode->next->next = currNode; 
        
            prevNode = currNode; 
            currNode = currNode->next; 
        
        }

        head = dummyNode->next;
        delete dummyNode;
        return head;
    
    }
};


// T.C. = O(n/2) = O(n) 
// S.C. = O(1) 

// Here, n = the total number of nodes which are present inside the singly linked list 