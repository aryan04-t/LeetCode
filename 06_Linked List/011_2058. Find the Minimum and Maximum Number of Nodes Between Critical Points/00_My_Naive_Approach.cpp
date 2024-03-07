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

        vector<int> criticalPoints;

        while(end != nullptr){

            if( mid->val > start->val && mid->val > end->val ){
                criticalPoints.push_back(nodeNum);
            }

            if( mid->val < start->val && mid->val < end->val ){
                criticalPoints.push_back(nodeNum);
            }

            nodeNum++; 
            start = start->next; 
            mid = mid->next; 
            end = end->next; 

        }

        int n = criticalPoints.size();

        if(n >= 2){

            int mini = INT_MAX;

            for(int i=1; i < n; i++){
                int currDiff = criticalPoints[i] - criticalPoints[i-1];
                if(currDiff < mini){
                    mini = min(mini, currDiff);
                }
            }

            ans[0] = mini;
            ans[1] = criticalPoints[n-1] - criticalPoints[0];

        }

        return ans;

    }

};


// T.C. = O(n) 
// S.C. = O(n) 

// Here, n = total number of nodes which are present inside the input list whose head is provided to us 