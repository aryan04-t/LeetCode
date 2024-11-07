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

        ListNode* dummyNode = new ListNode(-1);

        ListNode* prevNode; 
        ListNode* currNode = head; 
        ListNode* nextNode; 
        
        ListNode* mainHead;

        int temp;
        int n = getLengthOfLL(head);

        for(int i=0; i < n/k; i++){
            
            prevNode = nullptr;

            temp = k;
            while(temp--){
                nextNode = currNode->next; 
                currNode->next = prevNode; 
                prevNode = currNode; 
                currNode = nextNode; 
            }

            dummyNode->next = prevNode;
            dummyNode = head;
            head = currNode;

            if(i == 0){
                mainHead = prevNode;
            }

        }
    
        dummyNode->next = head;

        return mainHead;

    }
};


// T.C. = O(n) + O(n/k * k) = O(2n) = O(n) 
// S.C. = O(1) 

// Here, n = total number of nodes which are present inside the singly linked list,  
// and k = the value of input variable k 