// LeetCode (404. Sum of Left Leaves): 
// https://leetcode.com/problems/sum-of-left-leaves/ 


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

    void dfs(TreeNode* root, int &sum){

        if(root == nullptr) return; 

        if(root->left != nullptr){
            if(root->left->left == nullptr && root->left->right == nullptr){
                sum += root->left->val; 
            }
        }

        dfs(root->left, sum);
        dfs(root->right, sum);

    }

    int sumOfLeftLeaves(TreeNode* root) {

        int sum = 0; 
        dfs(root, sum); 

        return sum; 
    }
};


// T.C. = O(n) 
// S.C. = O(h) 

// Here, n = the total number of nodes which are present inside the given binary tree, and h = the height of the given bianry tree 