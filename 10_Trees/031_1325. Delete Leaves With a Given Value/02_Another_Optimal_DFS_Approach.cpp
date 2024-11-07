// LeetCode (1325. Delete Leaves With a Given Value): 
// https://leetcode.com/problems/delete-leaves-with-a-given-value/ 


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

    TreeNode* remove(TreeNode* root, int target, TreeNode* parent){

        if(root == nullptr) return nullptr;

        root->left = removeLeafNodes(root->left, target); 
        root->right = removeLeafNodes(root->right, target); 

        if(root->left == nullptr && root->right == nullptr && root->val == target){
            if(parent) delete root; 
            return nullptr; 
        }

        return root; 
    }

    TreeNode* removeLeafNodes(TreeNode* root, int target) {

        return remove(root, target, nullptr); 
    }
};


// T.C. = O(n) 
// S.C. = O(h) 

// Here, n = the total number of nodes which are present inside the given binary tree, 
// and h = the height of the given binary tree 