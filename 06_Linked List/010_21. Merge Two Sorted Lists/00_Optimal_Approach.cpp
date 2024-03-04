// LeetCode (21. Merge Two Sorted Lists): 
// https://leetcode.com/problems/merge-two-sorted-lists/ 


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

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        if(list1 == nullptr) return list2;
        if(list2 == nullptr) return list1; 

        ListNode* head = (list1->val <= list2->val) ? list1 : list2;
        ListNode* tail;

        if(head == list1){
            tail = list1;
            list1 = list1->next;
        }
        else{
            tail = list2; 
            list2 = list2->next; 
        }

        while(list1 != nullptr && list2 != nullptr){

            if(list1->val <= list2->val){
                tail->next = list1; 
                tail = list1; 
                list1 = list1->next; 
            }
            else{
                tail->next = list2; 
                tail = list2; 
                list2 = list2->next; 
            }

        }

        if(list1 != nullptr){
            tail->next = list1;
        }
        else{
            tail->next = list2;
        }

        return head;

    }
};


// T.C. = O(min(n,m)) 
// S.C. = O(1) 

// Here, n = total number of nodes which are present inside the input list named "list1", and m = total number of nodes which are present inside the input list named "list2" 