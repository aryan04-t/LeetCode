// LeetCode (101. Symmetric Tree): 
// https://leetcode.com/problems/symmetric-tree/ 


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

    TreeNode* copyTree(TreeNode* root){

        if(root == nullptr) return nullptr;

        int data = root->val; 

        TreeNode* newRoot = new TreeNode(data); 

        newRoot->left = copyTree(root->left); 
        newRoot->right = copyTree(root->right); 

        return newRoot; 

    }

    bool checkSymmetry(TreeNode* root1, TreeNode* root2){

        if(root1 == nullptr && root2 == nullptr) return true; 
        else if(root1 == nullptr || root2 == nullptr) return false; 

        if(root1->val != root2->val) return false; 

        bool check1 = checkSymmetry(root1->left, root2->right); 
        bool check2 = checkSymmetry(root1->right, root2->left); 

        return (check1 && check2);

    }

    bool isSymmetric(TreeNode* root) {

        TreeNode* root1 = root; 
        TreeNode* root2 = copyTree(root1); 

        return checkSymmetry(root1, root2); 
 
    }
};


// T.C. = O(n) + O(n) = O(n) 
// S.C. = O(n) + O(h) = O(n + h) -> Here O(h) space complexity is contributed by the function call stack 

// Here, n = total number of nodes which are present inside the given binary tree, and h = the height of the given binary tree 