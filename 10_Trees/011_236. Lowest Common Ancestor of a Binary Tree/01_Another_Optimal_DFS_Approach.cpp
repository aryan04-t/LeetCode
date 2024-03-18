// LeetCode (236. Lowest Common Ancestor of a Binary Tree): 
// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/ 


#include<vector> 
using namespace std; 


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


// - - - - - - - - - - 


/*
    Definition for a binary tree node.
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };
*/


class Solution {
public:

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        if(root == nullptr) return nullptr;

        if(root == p || root == q) return root; 

        TreeNode* leftAns = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightAns = lowestCommonAncestor(root->right, p, q);

        if(leftAns == nullptr && rightAns == nullptr) return nullptr; 
        else if(leftAns == nullptr && rightAns != nullptr) return rightAns; 
        else if(leftAns != nullptr && rightAns == nullptr) return leftAns; 
        // else if(leftAns != nullptr && rigthAns != nullptr) return root; 
        else return root; 

    }
};


// T.C. = O(n) 
// S.C. = O(h) 

// Here, n = the total number of nodes which are present in the given binary tree, and h = the height of the given binary tree 