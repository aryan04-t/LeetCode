// LeetCode (2487. Remove Nodes From Linked List): 
// https://leetcode.com/problems/remove-nodes-from-linked-list/ 


#include<vector> 
#include<algorithm> 
#include<limits.h> 
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

    int getLengthOfLL(ListNode* head){
        int len = 0;
        while(head != nullptr){
            len++;
            head = head->next;
        }
        return len;
    }

    void buildVector(ListNode* head, vector<int> &maxFromRight, int &i, int &maxi){

        if(head == nullptr) return; 

        buildVector(head->next, maxFromRight, i, maxi); 

        maxi = max(maxi, head->val); 
        maxFromRight[i] = maxi;
        i--;
    }

    void freeUpMemory(vector<ListNode*> &uselessNodes){
        for(ListNode* node : uselessNodes){
            node->next = nullptr; 
            delete node; 
        }
    }
    
    ListNode* removeNodes(ListNode* head) {

        int n = getLengthOfLL(head); 

        vector<int> maxFromRight(n, INT_MIN);
        int maxi = INT_MIN; 
        int i = n - 1; 
        buildVector(head, maxFromRight, i, maxi); 

        vector<ListNode*> uselessNodes; 

        ListNode* newHead = nullptr; 
        ListNode* newTail = nullptr; 

        i = 0; 
        ListNode* temp = head; 
        while(temp != nullptr){
            if(temp->val >= maxFromRight[i]){
                if(newHead == nullptr){
                    newHead = temp; 
                    newTail = temp; 
                }
                else{
                    newTail->next = temp;
                    newTail = newTail->next; 
                }
            }
            else{
                uselessNodes.push_back(temp); 
            }
            i++;
            temp = temp->next; 
        }

        freeUpMemory(uselessNodes); 

        return newHead; 
    }
};


// T.C. = O(n) + O(n) + O(n) + O(n) = O(4n) = O(n) 
// S.C. = O(n) + O(n) = O(2n) = O(n) 

// Here, n = the total number of nodes which are present inside the given "singly linked list" 