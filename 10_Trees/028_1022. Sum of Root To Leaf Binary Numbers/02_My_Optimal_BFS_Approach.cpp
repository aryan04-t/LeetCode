// LeetCode (1022. Sum of Root To Leaf Binary Numbers): 
// https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/ 


#include<queue> 
#include<utility> 
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

    int sumRootToLeaf(TreeNode* root) {
        
        int ans = 0; 

        queue<pair<TreeNode*, int>> q; 
        q.push({root, 0}); 

        while(!q.empty()){

            pair<TreeNode*, int> p = q.front(); 
            q.pop(); 

            TreeNode* currNode = p.first; 
            int num = p.second; 

            num = num * 2 + currNode->val; 

            if(currNode->left == nullptr && currNode->right == nullptr) ans += num; 

            if(currNode->left != nullptr) q.push({currNode->left, num}); 
            if(currNode->right != nullptr) q.push({currNode->right, num}); 
        }
    
        return ans; 
    } 
}; 


// T.C. = O(n) 
// S.C. = O(m) 

// Here, n = the total number of nodes which are present inside the given binary tree, 
// and m = the maximum number of nodes which are present at any level of the given binary tree 