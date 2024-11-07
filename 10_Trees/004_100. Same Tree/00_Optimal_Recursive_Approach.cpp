// LeetCode (100. Same Tree): 
// https://leetcode.com/problems/same-tree/ 


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

    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        if(p == nullptr && q == nullptr) return true; 
        else if(p != nullptr && q == nullptr) return false; 
        else if(p == nullptr && q != nullptr) return false; 

        if(p->val != q->val) return false; 

        bool checkLeft = isSameTree(p->left, q->left); 
        bool checkRight = isSameTree(p->right, q->right);  

        return (checkLeft && checkRight); 

    }
}; 


// T.C. = O(min(n, m)) 
// S.C. = O(min(h1, h2)) -> This spacce complexity is caused due to function call stack 

// Here, n = total number of nodes which are present inside the input binary tree named "p", and m = total number of nodes which are present inside the input binary tree named "q" 
// h1 = the height of the input binary tree named "p", and h2 = the height of the input binary tree named "q" 