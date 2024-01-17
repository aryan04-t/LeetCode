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


// In this code I have fixed repetitiveness of "Reversing Linked List Code" by modifying the reverseLinkedList() function a little bit 


class Solution {
public:


    int getLength(ListNode* head){

        int len = 0;
        ListNode* temp = head;
        
        while(temp != nullptr){
            len++;
            temp = temp->next;
        }

        return len;
    }


    ListNode* reverseLinkedList(ListNode* startNode, ListNode* stoppingCondition = nullptr){

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


    ListNode* solveEdgeCaseOne(ListNode* head, int right){

        int tempRight = right;
        ListNode* reverseListEnd = head;

        while(tempRight != 1){
            reverseListEnd = reverseListEnd->next;
            tempRight--;
        }

        ListNode* endConnection = reverseListEnd->next;

        ListNode* prevNode = reverseLinkedList(head, endConnection);

        head->next = endConnection;

        return prevNode;

    }


    ListNode* solveEdgeCaseTwo(ListNode* head, int left){

        int tempLeft = left;
        ListNode* startConnection = head;

        while(tempLeft != 2){
            startConnection = startConnection->next;
            tempLeft--;
        }

        ListNode* reverseListStart = startConnection->next;
    
        ListNode* prevNode = reverseLinkedList(reverseListStart); 

        startConnection->next = prevNode;

        return head;

    }
    

    void reverseLinkedListInBetween(ListNode* head, int left, int right){


        int tempLeft = left;
        ListNode* startConnection = head;

        while(tempLeft != 2){
            startConnection = startConnection->next;
            tempLeft--;
        }

        ListNode* reverseListStart = startConnection->next;
    
        
        int tempRight = right;
        ListNode* reverseListEnd = head;

        while(tempRight != 1){
            reverseListEnd = reverseListEnd->next;
            tempRight--;
        }

        ListNode* endConnection = reverseListEnd->next;

        reverseLinkedList(reverseListStart, endConnection); 
        
        reverseListStart->next = endConnection;
        startConnection->next = reverseListEnd;

        return;
    }
    

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        if(left == right){
            return head;
        }

        int lengthOfLL = getLength(head);
        
        if(right - left + 1 == lengthOfLL){
            head = reverseLinkedList(head); 
            return head;
        }

        if(left == 1 && right != lengthOfLL){
            head = solveEdgeCaseOne(head, right);
            return head;
        }

        if(left != 1 && right == lengthOfLL){
            head = solveEdgeCaseTwo(head, left);
            return head;
        }

        reverseLinkedListInBetween(head, left, right);
    
        return head;
    }

};


// T.C. = O(n) 
// S.C. = O(1) 

// Here, n = the total number of nodes which are present inside the singly linked list 