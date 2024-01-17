// LeetCode (25. Reverse Nodes in k-Group): 
// https://leetcode.com/problems/reverse-nodes-in-k-group/ 


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

    int getLengthOfLL(ListNode* temp){
        
        int len = 0;

        while(temp != nullptr){
            len++;
            temp = temp->next;
        }
        
        return len; 

    }

    ListNode* reverseKGroup(ListNode* head, int k) {

        int len = getLengthOfLL(head);

        if(k > len){
            return head;
        }

        int temp = k; 

        ListNode* prevNode = nullptr; 
        ListNode* currNode = head; 
        ListNode* nextNode; 

        while(temp--){
            nextNode = currNode->next; 
            currNode->next = prevNode; 
            prevNode = currNode; 
            currNode = nextNode; 
        }

        head->next = reverseKGroup(currNode, k);

        return prevNode;

    }
};


// T.C. = O(n/k) * (O(n) + O(k)) = O(n^2/k) + O(n) = O(n^2/k) 
// S.C. = O(n/k) * O(1) = O(n/k) 

// Here, n = total number of nodes which are present inside the singly linked list,  
// and k = the value of input variable k 