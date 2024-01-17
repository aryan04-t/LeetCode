// LeetCode (92. Reverse Linked List II): 
// https://leetcode.com/problems/reverse-linked-list-ii/ 


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


    ListNode* reverseLinkedList(ListNode* startNode, ListNode* stoppingCondition){

        ListNode* prevNode = nullptr;
        ListNode* currNode = startNode;
        ListNode* nextNode;

        while(currNode != stoppingCondition){

            nextNode = currNode->next;
            currNode->next = prevNode;
            prevNode = currNode;
            currNode = nextNode;

        }

        return prevNode;

    }
    

    void leftPointerDestination(ListNode* &startPrev, ListNode* &startHead, int left){

        int tempLeft = 1;

        while(tempLeft < left){
        
            startPrev = startHead; 
            startHead = startHead->next;
        
            tempLeft++; 
        }

    }


    void rightPointerDestination(ListNode* &endCurr, ListNode* &endNext, int right){

        int tempRight = 1;

        while(tempRight < right){

            endCurr = endCurr->next;

            tempRight++;

        }
        endNext = endCurr->next;

    }


    ListNode* reverseBetween(ListNode* head, int left, int right) {
        

        if(head->next == nullptr){
            return head;
        }

        if(left == right){
            return head;
        }
        

        ListNode* startPrev = nullptr;
        ListNode* startHead = head;
        leftPointerDestination(startPrev, startHead, left); 


        ListNode* endCurr = head;
        ListNode* endNext;
        rightPointerDestination(endCurr, endNext, right); 
        

        ListNode* prevNode = reverseLinkedList(startHead, endNext); 


        // for case like [8,3] , left = 1 , right = 2 (if left == 1, then startPrev = NULL)
        if(left != 1){ 
            startPrev->next = prevNode; 
        }
        else{
            head = prevNode;
        }


        startHead->next = endNext;


        return head;
    }

};


// T.C. = O(n) 
// S.C. = O(1) 

// Here, n = the total number of nodes which are present inside the singly linked list 