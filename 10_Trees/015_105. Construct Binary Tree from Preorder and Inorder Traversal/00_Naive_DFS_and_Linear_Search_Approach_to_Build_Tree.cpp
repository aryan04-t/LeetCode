// LeetCode (105. Construct Binary Tree from Preorder and Inorder Traversal): 
// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/


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

    int findIndex(int target, const vector<int> &inorder){

        int n = inorder.size(); 

        for(int i=0; i < n; i++){
            if(inorder[i] == target) return i; 
        }

        return -1;
    }

    TreeNode* buildTreeUsingPreAndInOrder(vector<int> &preorder, int &i, vector<int> &inorder, int start, int end){

        if(start > end) return nullptr; 

        int data = preorder[i++]; 
        TreeNode* root = new TreeNode(data); 

        int index = findIndex(data, inorder); 

        root->left = buildTreeUsingPreAndInOrder(preorder, i, inorder, start, index - 1); 
        root->right = buildTreeUsingPreAndInOrder(preorder, i, inorder, index + 1, end); 

        return root; 
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        int n = preorder.size(); 
        int i = 0; 

        int start = 0; 
        int end = n-1; 

        TreeNode* root = buildTreeUsingPreAndInOrder(preorder, i, inorder, start, end); 

        return root; 
    }
}; 


// T.C. = O( (n * (n+1)) / 2 ) = O(n^2) 
// S.C. = O(h) + O(n) = (the s.c. caused by the function call stack) + (the s.c. caused by the creation of all the nodes of the given binary tree) = O(n) 

// Here, n = the total number of node values which are present inside the given input vector named "inorder / preorder", and h = the height of the binary tree which is getting constructed 