// LeetCode (100. Same Tree): 
// https://leetcode.com/problems/same-tree/ 


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


// - - - - - - - - - - 


/*
    Definition for a binary tree node.
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };
*/


class Solution {
public:

    bool isSameTree(TreeNode* p, TreeNode* q) {

        if(p == nullptr && q == nullptr) return true; 
        else if(p != nullptr && q == nullptr) return false;
        else if(p == nullptr && q != nullptr) return false;

        if(p->val != q->val) return false; 

        bool leftCheck = isSameTree(p->left, q->left); 
        bool rightCheck = isSameTree(p->right, q->right); 

        return (leftCheck && rightCheck);
    
    }

};


// T.C. = O(min(n, m)) 
// S.C. = O( min( min(n, m), h) ) -> This space complexity is caused due to function call stack 

// Here, n = the total number of nodes which are present inside the input tree-1, and m = the total number of node which are present inside the input tree-2 
// and h = the height of the smaller tree 