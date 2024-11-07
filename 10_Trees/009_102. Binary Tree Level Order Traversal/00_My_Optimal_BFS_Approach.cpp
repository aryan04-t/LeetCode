// LeetCode (102. Binary Tree Level Order Traversal): 
// https://leetcode.com/problems/binary-tree-level-order-traversal/ 


#include<vector> 
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

    vector<vector<int>> levelOrder(TreeNode* root) {

        if(root == nullptr) return {}; 

        queue<TreeNode*> q; 
        q.push(root); 

        int levelSize = 1; 
        vector<vector<int>> ans; 

        while(!q.empty()){
            
            levelSize = q.size(); 
            vector<int> currLevel; 

            for(int i=0; i < levelSize; i++){

                TreeNode* currNode = q.front(); 
                q.pop(); 

                currLevel.push_back(currNode->val); 

                if(currNode->left != nullptr) q.push(currNode->left); 
                if(currNode->right != nullptr) q.push(currNode->right); 
            }
        
            ans.push_back(currLevel); 
        }

        return ans; 

    }
};


// T.C. = O(n) 
// S.C. = O(n + m) 

// Here, n = the total number of nodes which are present inside the given binary tree, and m = the maximum number of nodes which are present at any level of the given binary tree 