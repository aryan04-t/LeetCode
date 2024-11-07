// LeetCode (94. Binary Tree Inorder Traversal): 
// https://leetcode.com/problems/binary-tree-inorder-traversal/ 


#include<vector> 
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

    void inorder(TreeNode* root, vector<int> &ans){

        if(root == nullptr) return; 

        inorder(root->left, ans); 
        ans.push_back(root->val); 
        inorder(root->right, ans); 
    }

    vector<int> inorderTraversal(TreeNode* root) {

        vector<int> ans; 
        inorder(root, ans); 

        return ans; 
    }
}; 


// T.C. = O(n) 
// S.C. = O(h) + O(n) = (This space complexity is caused by the function call stack) + (This space complexity is caused by the vector which is storing the inorder traversal) = O(n) 

// Here, n = the total number of nodes which are present inside the given binary tree, and h = the height of the given binary tree 
// In worst case when the binary tree is skewed, h == n 