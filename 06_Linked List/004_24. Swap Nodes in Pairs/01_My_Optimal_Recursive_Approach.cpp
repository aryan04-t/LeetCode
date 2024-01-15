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
        
        ListNode* behind = nullptr;
        ListNode* curr = head;
        ListNode* ahead;

        int k = 2;

        while(k--){
            ahead = curr->next;
            curr->next = behind;
            behind = curr;
            curr = ahead;
        }

        head->next = swapPairs(ahead); 

        return behind;
    
    }
};


// T.C. = O(2*(n/2)) = O(n) 
// S.C. = O(n/k) = O(n/2) = O(n) -> (This Space Complexity is caused due to Function Call Stack) 

// Here, n = the total number of nodes which are present inside the singly linked list 