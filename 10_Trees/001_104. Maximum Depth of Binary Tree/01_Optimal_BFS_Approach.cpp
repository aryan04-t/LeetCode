// LeetCode (104. Maximum Depth of Binary Tree): 
// https://leetcode.com/problems/maximum-depth-of-binary-tree/ 


#include<queue> 
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

    int maxDepth(TreeNode* root) {
        
        if(root == nullptr) return 0;

        queue<TreeNode*> q;
        q.push(root);

        int depth = 0; 
        int levelSize = 1; 

        while(!q.empty()){

            depth++; 
            levelSize = q.size(); 

            for(int i=0; i < levelSize; i++){
                
                TreeNode* currNode = q.front(); 
                q.pop(); 
            
                if(currNode->left != nullptr) q.push(currNode->left); 
                if(currNode->right != nullptr) q.push(currNode->right); 

            }
        }

        return depth; 

    }
    
};


// T.C. = O(n) 
// S.C. = O(m) 

// Here, n = the total number of nodes which are present inside the given binary tree, and m = the maximum number of which are present at any level of the given binary tree 