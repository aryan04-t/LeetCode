// LeetCode (199. Binary Tree Right Side View): 
// leetcode.com/problems/binary-tree-right-side-view/ 


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

    vector<int> rightSideView(TreeNode* root) {

        if(root == nullptr) return {}; 
        
        vector<int> ans; 
        
        queue<TreeNode*> q;
        q.push(root);
        
        int levelSize = 1; 
        
        while(!q.empty()){
            
            levelSize = q.size(); 
            
            for(int i=0; i < levelSize; i++){
                
                TreeNode* currNode = q.front(); 
                q.pop(); 
                
                if(i == levelSize-1) ans.push_back(currNode->val); 
                
                if(currNode->left != nullptr) q.push(currNode->left);
                if(currNode->right != nullptr) q.push(currNode->right);
                
            }
        }
        
        return ans;
    }
};


// T.C. = O(n) 
// S.C. = O(m) + O(n) = O(n) 

// Here, n = the total number of nodes which are present inside the given binary tree, and m = the maximum number of nodes which are present at any level of the given binary tree 