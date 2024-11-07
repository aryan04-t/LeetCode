// LeetCode (2130. Maximum Twin Sum of a Linked List): 
// https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/ 


#include<algorithm> 
using namespace std; 


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

    int pairSum(ListNode* head) {

        int n = getLengthOfLL(head); 

        ListNode* temp;
        int i = 0;
        int maxSum = 0; 
        int currSum = 0; 

        while( i < (n/2) ){
            
            temp = head; 
            int j = i; 
            
            while(j < n-1-i){
                temp = temp->next; 
                j++;
            }

            currSum = head->val + temp->val; 
            maxSum = max(maxSum, currSum); 

            head = head->next; 
            i++;
        }

        return maxSum;
    }
};


// T.C. = O(n) + O((n/2)^2) = O(n^2) 
// S.C = O(1) 

// Here, n = the total number of nodes which are present inside the given "singly linked list" 