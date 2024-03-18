// LeetCode (236. Lowest Common Ancestor of a Binary Tree): 
// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/ 


#include<vector> 
using namespace std; 


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


// - - - - - - - - - - 


/*
    Definition for a binary tree node.
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };
*/


class Solution {
public:

    void findPath(TreeNode* root, TreeNode* target, vector<TreeNode*> &path, bool &isFound){

        if(root == nullptr) return; 
        if(isFound) return; 

        if(!isFound) path.push_back(root); 
        
        if(root == target) isFound = true; 

        findPath(root->left, target, path, isFound); 
        findPath(root->right, target, path, isFound); 

        if(!isFound) path.pop_back(); 

    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        vector<TreeNode*> pPath; 
        bool isFound = false; 
        
        findPath(root, p, pPath, isFound); 
        
        vector<TreeNode*> qPath; 
        isFound = false; 
        
        findPath(root, q, qPath, isFound); 

        int n = pPath.size(); 
        int m = qPath.size(); 

        int i=0;
        while(i < n && i < m){
            if(pPath[i] != qPath[i]) break;
            i++;
        }

        if(i == n) return pPath[n-1]; 
        if(i == m) return qPath[m-1]; 

        return pPath[i-1]; 

    }
};


// T.C. = O(n) + O(n) + O(h) = O(n) 
// S.C. = O(3h) = O(h) 

// Here, n = the total number of nodes which are present in the given binary tree, and h = the height of the given binary tree 