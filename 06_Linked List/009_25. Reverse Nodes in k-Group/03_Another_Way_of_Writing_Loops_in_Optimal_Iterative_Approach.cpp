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

   
        int n = getLengthOfLL(head);
        bool condition = true;
        
        while(n >= k){
            
            prevNode = nullptr;

            for(int i=0; i < k; i++){
                nextNode = currNode->next; 
                currNode->next = prevNode; 
                prevNode = currNode; 
                currNode = nextNode; 
            }

            if(condition){
                mainHead = prevNode;
                condition = false;
            }

            dummyNode->next = prevNode;
            dummyNode = head;
            head = currNode;

            n = n-k;

        }

        dummyNode->next = head;
            
        return mainHead;

    }
};


// T.C. = O(n) + O(n/k * k) = O(2n) = O(n) 
// S.C. = O(1) 

// Here, n = total number of nodes which are present inside the singly linked list,  
// and k = the value of input variable k 