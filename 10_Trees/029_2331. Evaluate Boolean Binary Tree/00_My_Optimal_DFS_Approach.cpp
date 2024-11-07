// LeetCode (2331. Evaluate Boolean Binary Tree): 
// https://leetcode.com/problems/evaluate-boolean-binary-tree/ 


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

    bool dfs(TreeNode* root){

        if(root->left == nullptr && root->right == nullptr) return root->val; 

        bool leftVal = dfs(root->left);
        bool rightVal = dfs(root->right);

        if(root->val == 2) return leftVal || rightVal; 
        // else if(root->val == 3) return leftVal && rightVal; 
        else return leftVal && rightVal; 
    }

    bool evaluateTree(TreeNode* root) {
        return dfs(root); 
    }
};


// T.C. = O(n) 
// S.C. = O(h) -> (This space complexity is caused by the function call stack) 

// Here, n = the total number of nodes which are present inside the given binary tree,  
// and h = the height of the given binary tree, in worst case when the binary tree is skewed, h == n 