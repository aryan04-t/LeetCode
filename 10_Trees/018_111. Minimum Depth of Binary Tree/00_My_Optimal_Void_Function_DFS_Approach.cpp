// LeetCode (111. Minimum Depth of Binary Tree): 
// https://leetcode.com/problems/minimum-depth-of-binary-tree/ 


#include<algorithm> 
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

    void getMinHeight(TreeNode* root, int height, int &minHeight){

        if(root == nullptr) return; 

        if(root->left == nullptr && root->right == nullptr){
            minHeight = min(height, minHeight); 
            return; 
        }

        getMinHeight(root->left, height+1, minHeight); 
        getMinHeight(root->right, height+1, minHeight); 

    }

    int minDepth(TreeNode* root) {

        if(root == nullptr) return 0; 

        int minHeight = INT_MAX; 
        int height = 1; 

        getMinHeight(root, height, minHeight); 

        return minHeight; 

    }
};


// T.C. = O(n) 
// S.C. = O(h) 

// Here, n = the total number of nodes which are present inside the given binary tree, h = the height of the given binary tree 