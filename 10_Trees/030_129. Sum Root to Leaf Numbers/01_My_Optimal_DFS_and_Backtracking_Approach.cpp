// LeetCode (129. Sum Root to Leaf Numbers): 
// https://leetcode.com/problems/sum-root-to-leaf-numbers/ 


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

    void dfs(TreeNode* root, int &num, int &sum){ 

        if(root == nullptr) return; 

        num = num * 10 + root->val; 

        if(root->left == nullptr && root->right == nullptr) sum += num; 

        dfs(root->left, num, sum); 
        dfs(root->right, num, sum); 

        num /= 10;
    }

    int sumNumbers(TreeNode* root) {
        
        int num = 0; 
        int sum = 0; 
        dfs(root, num, sum); 

        return sum;
    }
};


// T.C. = O(n) 
// S.C. = O(h) 

// Here, n = the total number of nodes which are present inside the given binary tree, 
// and h = the height of the given binary tree, in worst case when the given binary tree is skewed, h == n 