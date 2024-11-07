// LeetCode (617. Merge Two Binary Trees): 
// https://leetcode.com/problems/merge-two-binary-trees/ 


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

    TreeNode* merge(TreeNode* root1, TreeNode* root2){

        if(root1 == nullptr && root2 == nullptr) return nullptr; 
        else if(root1 != nullptr && root2 == nullptr) return root1; 
        else if(root1 == nullptr && root2 != nullptr) return root2; 
        
        TreeNode* newNode = new TreeNode(root1->val + root2->val); 

        newNode->left = merge(root1->left, root2->left); 
        newNode->right = merge(root1->right, root2->right); 

        delete root1; 
        delete root2; 

        return newNode; 
    }

    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {

        return merge(root1, root2); 
    }
};


// T.C. = O(n) 
// S.C. = O(h) 

// Here, n = the total number of overlapping nodes between both the given binary trees, 
// and h = the maximum overlapping height between both the given binary trees 