// LeetCode (110. Balanced Binary Tree): 
// leetcode.com/problems/balanced-binary-tree/ 


#include<cstdlib> 
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

    int helper(TreeNode* root, bool &ans){

        if(root == nullptr){
            return 0; 
        }

        int leftHeight = helper(root->left, ans); 
        int rightHeight = helper(root->right, ans); 

        int diff = abs(leftHeight - rightHeight); 

        if(diff != 1 && diff != 0){
            ans = false; 
        }

        return max(leftHeight, rightHeight) + 1; 

    }

    bool isBalanced(TreeNode* root) {

        bool ans = true; 
        helper(root, ans); 

        return ans; 

    }

};


// T.C. = O(n) 
// S.C. = O(h) 

// Here, n = total number of nodes which are present inside the tree, and h = the height of tree 