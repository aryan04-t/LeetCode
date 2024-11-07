// LeetCode (94. Binary Tree Inorder Traversal): 
// https://leetcode.com/problems/binary-tree-inorder-traversal/ 


#include<vector> 
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


// This is a better runtime solution, as per the constraints that are mentioned in this question 
// This solution is better because we're not using vector's push_back() function here, and because of that there this no extra time consumption by the reallocation of vector whenever its capacity gets full 

// The first optimal solution that I have written is a perfectly fine solution, but I just wanted to optimize my code even more, because the constraints are allowing me to do that, nothing else 


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

    void inorder(TreeNode* root, int &i, vector<int> &ans){

        if(root == nullptr) return; 

        inorder(root->left, i, ans); 
        ans[i++] = root->val; 
        inorder(root->right, i, ans); 
    }

    vector<int> inorderTraversal(TreeNode* root) {

        vector<int> ans(100, -101); 
        int i = 0;

        inorder(root, i, ans); 

        for(int i=99; i >= 0; i--){
            if(ans[i] == -101) ans.pop_back(); 
            else break; 
        }

        return ans; 
    }
};


// T.C. = O(100) + O(n) + O(100) = O(n) 
// S.C. = O(h) + O(n) = (This space complexity is caused by the function call stack) + (This space complexity is caused by the vector which is storing the inorder traversal) = O(n) 

// Here, n = the total number of nodes which are present inside the given binary tree, and h = the height of the given binary tree 
// In worst case when the binary tree is skewed, h == n 