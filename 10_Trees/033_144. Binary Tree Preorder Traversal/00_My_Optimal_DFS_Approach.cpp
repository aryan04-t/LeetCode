// LeetCode (144. Binary Tree Preorder Traversal): 
// https://leetcode.com/problems/binary-tree-preorder-traversal/ 


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
    void getPreorder(TreeNode* root, vector<int> &ans){

        if(root == nullptr) return; 

        ans.push_back(root->val); 
        getPreorder(root->left, ans); 
        getPreorder(root->right, ans); 
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans; 
        getPreorder(root, ans);
        return ans;
    }
};


// T.C. = O(n) 
// S.C. = O(h) -> (s.c. caused due to function callstack) 

// Here, n = the total number of nodes which are present inside the given binary tree, and h = the height of the given binary tree (In worst case h == n) 