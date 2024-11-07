// LeetCode (104. Maximum Depth of Binary Tree): 
// https://leetcode.com/problems/maximum-depth-of-binary-tree/ 


#include<algorithm> 
using namespace std; 


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

    int getHeight(TreeNode* root){
        
        if(root == nullptr){
            return 0; 
        }

        int leftHeight = getHeight(root->left); 
        int rightHeight = getHeight(root->right); 

        return max(leftHeight, rightHeight) + 1; 

    }

    int maxDepth(TreeNode* root) {
        
        int depth = getHeight(root); 
        return depth; 

    }

};


// T.C. = O(n) 
// S.C. = O(h) 

// Here, n = the total number of nodes which are present inside the given binary tree, and h = the height of the given binary tree 