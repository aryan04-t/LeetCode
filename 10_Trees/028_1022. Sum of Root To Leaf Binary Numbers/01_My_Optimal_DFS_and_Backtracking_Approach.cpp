// LeetCode (1022. Sum of Root To Leaf Binary Numbers): 
// https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/ 


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

    void dfs(TreeNode* root, int &num, int &ans){

        if(root == nullptr) return; 
        
        num = num * 2 + root->val; 
        
        if(root->left == nullptr && root->right == nullptr){
            ans += num;
        } 

        dfs(root->left, num, ans); 
        dfs(root->right, num, ans); 

        num = (num - root->val) / 2; 
    }

    int sumRootToLeaf(TreeNode* root) {

        int num = 0; 
        int ans = 0; 
        dfs(root, num, ans);         
    
        return ans; 
    }
};


// T.C. = O(n) 
// S.C. = O(h) -> (This space complexity is caused by the function call stack) 

// Here, n = the total number of nodes which are present inside the given binary tree, 
// and h = the height of given binary tree, and in worst case when the binary tree is skewed (h == n)