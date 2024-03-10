// LeetCode (543. Diameter of Binary Tree): 
// https://leetcode.com/problems/diameter-of-binary-tree/ 


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

    int findDiameter(TreeNode* root, int &diameter){
        
        if(root == nullptr){
            return 0; 
        }

        int leftHeight = findDiameter(root->left, diameter); 
        int rightHeight = findDiameter(root->right, diameter); 

        diameter = max(leftHeight + rightHeight, diameter);

        return max(leftHeight, rightHeight) + 1; 

    }

    int diameterOfBinaryTree(TreeNode* root) {
        
        int diameter = 0; 
        findDiameter(root, diameter); 
        
        return diameter; 

    }

};


// T.C. = O(n) 
// S.C. = O(h) 

// Here, n = the total number of nodes which are present inside the given binary tree, and h = the height of the given binary tree 