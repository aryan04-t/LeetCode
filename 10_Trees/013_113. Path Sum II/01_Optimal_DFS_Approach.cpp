// LeetCode (113. Path Sum II): 
// https://leetcode.com/problems/path-sum-ii/ 


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

    void findAllPaths(TreeNode* root, int targetSum, vector<int> &currPath, vector<vector<int>> &ans){

        if(root == nullptr) return; 
        
        currPath.push_back(root->val);

        if(root->left == nullptr && root->right == nullptr){
            
            if(targetSum == root->val) ans.push_back(currPath);
            
            currPath.pop_back(); 

            return; 
        }

        findAllPaths(root->left, targetSum - root->val, currPath, ans); 
        findAllPaths(root->right, targetSum - root->val, currPath, ans); 

        currPath.pop_back(); 

    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {

        vector<int> currPath; 
        vector<vector<int>> ans; 

        findAllPaths(root, targetSum, currPath, ans); 

        return ans; 

    }
};


// T.C. = O(n) 
// S.C. = O(n) + O(h) + O(h) = O(n) 

// Here, n = total number of nodes which are present in the given binary tree, and h = the height of the given binary tree 