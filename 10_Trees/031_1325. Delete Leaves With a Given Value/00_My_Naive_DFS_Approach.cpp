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

    void dfs(TreeNode* root, int target, bool &done){

        if(root == nullptr) return; 

        if(root->left != nullptr){
            if(root->left->left == nullptr && root->left->right == nullptr && root->left->val == target){
                done = true;
                delete root->left; 
                root->left = nullptr; 
            }
        }
        if(root->right != nullptr){
            if(root->right->left == nullptr && root->right->right == nullptr && root->right->val == target){
                done = true; 
                delete root->right; 
                root->right = nullptr; 
            }
        }

        dfs(root->left, target, done); 
        dfs(root->right, target, done); 
    }

    TreeNode* removeLeafNodes(TreeNode* root, int target) {

        bool done = false; 
        while(!done){
            dfs(root, target, done); 
            if(done) done = false;
            else done = true; 
        } 

        if(root->left == nullptr && root->right == nullptr && root->val == target) return nullptr;
        else return root; 
    }
};


// T.C. = O(n^2) 
// S.C. = O(h) 

// Here, n = the total number of nodes which are present inside the given binary tree, 
// and h = the height of the given binary tree 