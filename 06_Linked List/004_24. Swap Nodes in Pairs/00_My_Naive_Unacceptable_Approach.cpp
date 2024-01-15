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



/*

# The question explicitly mentions that:
--> "You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)" 

@ But the 1st thing that I can think of after reading this question, is the "Naive Approach" where I can solve this question by swapping the data, then why not 1st code this approach, just to check whether I am capable of coding this approach or not 

$ After this I will code the valid optimal approach. 

*/



// So, here I tried Solving the Question by Swapping the Data First, to see whether I can do it or not 


class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        
        ListNode* temp = head;
        
        while(temp != nullptr && temp->next != nullptr){
            int backUp = temp->val;
            temp->val = temp->next->val; 
            temp->next->val = backUp;

            temp = temp->next->next;
        }
    
        return head;
    
    }
};


// T.C. = O(n/2) = O(n) 
// S.C. = O(1) 

// Here, n = the total number of nodes which are present inside the singly linked list 