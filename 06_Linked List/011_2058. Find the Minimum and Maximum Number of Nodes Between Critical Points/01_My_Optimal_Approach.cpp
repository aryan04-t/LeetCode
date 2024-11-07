// LeetCode (2058. Find the Minimum and Maximum Number of Nodes Between Critical Points): 
// https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/ 


#include<vector> 
#include<limits.h> 
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

    vector<int> nodesBetweenCriticalPoints(ListNode* head) {

        vector<int> ans{-1, -1};

        if(head->next->next == nullptr){
            return ans;
        }

        int nodeNum = 2;
        
        ListNode* start = head; 
        ListNode* mid = head->next; 
        ListNode* end = head->next->next; 

        int firstPos = -1; 
        int prevPos = -1; 
        int currPos = -1; 

        int mini = INT_MAX; 
        int maxi = INT_MIN; 

        while(end != nullptr){

            if( (mid->val > start->val && mid->val > end->val) || (mid->val < start->val && mid->val < end->val) ){

                if(firstPos == -1){
                    firstPos = nodeNum; 
                } 

                prevPos = currPos; 
                currPos = nodeNum; 

                if(prevPos != -1){
                    int currDiff = currPos - prevPos;
                    if(currDiff < mini){
                        mini = min(mini, currDiff); 
                    }
                } 
            
            }

            nodeNum++; 
            start = start->next; 
            mid = mid->next; 
            end = end->next; 

        }

        if(mini != INT_MAX){

            maxi = currPos - firstPos;

            ans[0] = mini; 
            ans[1] = maxi; 

            return ans;

        }

        return ans;

    }

};


// T.C. = O(n) 
// S.C. = O(1) 

// Here, n = total number of nodes whcih are present inside the input list whose head is provided to us 