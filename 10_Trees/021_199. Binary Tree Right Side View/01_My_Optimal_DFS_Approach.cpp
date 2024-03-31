// LeetCode (199. Binary Tree Right Side View): 
// leetcode.com/problems/binary-tree-right-side-view/ 


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

    int getHeight(TreeNode* root){
        
        if(root == nullptr) return 0;
        
        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right); 
        
        return max(leftHeight, rightHeight) + 1;
        
    }


    void getRightView(TreeNode* root, int height, bool &done, vector<bool> &isPrinted, vector<int> &ans){
    
        if(root == nullptr) return; 
        
        if(done) return; 
        
        if(!isPrinted[height]){
            ans.push_back(root->val); 
            isPrinted[height] = true; 
        }
        
        getRightView(root->right, height - 1, done, isPrinted, ans); 
        getRightView(root->left, height - 1, done, isPrinted, ans); 
        
        if(height == 1) done = true; 
    }

    vector<int> rightSideView(TreeNode* root) {

        int height = getHeight(root);
        
        vector<bool> isPrinted(height+1, false); 
        vector<int> ans; 
        
        bool done = false; 
        
        getRightView(root, height, done, isPrinted, ans); 
        
        return ans;
    }
};


// T.C. = O(n) + O(n) = O(n) 
// S.C. = O(h) + O(h+1) + O(h) + O(n) = O(n) 

// Here, n = the total number of nodes which are present inside the given binary tree, and h = the height of the given binary tree