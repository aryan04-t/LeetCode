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


// Last code was really optimized but still a little bit of DRY principle was getting violated by the code snippets where pointers have to reach at their desired location with respect to the "left" and "right" input values so that we can reverse the desired part of the linked list 

// So, to deal with this repetetiveness of code I made 2 extra functions named as leftPointerDestination() and rightPointerDestination(), and these functions are being called respectively whenever we want the left or right pointer to reach their desired location 

// This is the last version of my this code, as far as I now, I don't think this code can be optimized anymore in any sense, at least at this level of mine I can't optimize this code anymore, because I cannot think of any other optimizations. 


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


    void leftPointerDestination(int tempLeft, ListNode* &startConnection){

        while(tempLeft != 2){
            startConnection = startConnection->next;
            tempLeft--;
        }

    }


    void rightPointerDestination(int tempRight, ListNode* &reverseListEnd){

        while(tempRight != 1){
            reverseListEnd = reverseListEnd->next;
            tempRight--;
        }

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

        ListNode* reverseListEnd = head;
        rightPointerDestination(right, reverseListEnd); 

        ListNode* endConnection = reverseListEnd->next;
        ListNode* prevNode = reverseLinkedList(head, endConnection);
        head->next = endConnection;

        return prevNode;

    }


    ListNode* solveEdgeCaseTwo(ListNode* head, int left){

        ListNode* startConnection = head;
        leftPointerDestination(left, startConnection);

        ListNode* reverseListStart = startConnection->next;
        ListNode* prevNode = reverseLinkedList(reverseListStart); 
        startConnection->next = prevNode;

        return head;

    }
    

    void reverseLinkedListInBetween(ListNode* head, int left, int right){


        ListNode* startConnection = head;
        leftPointerDestination(left, startConnection);

        ListNode* reverseListStart = startConnection->next;
    
    
        ListNode* reverseListEnd = head;
        rightPointerDestination(right, reverseListEnd);

        ListNode* endConnection = reverseListEnd->next;


        reverseLinkedList(reverseListStart, endConnection); 
        
        reverseListStart->next = endConnection;
        startConnection->next = reverseListEnd;

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