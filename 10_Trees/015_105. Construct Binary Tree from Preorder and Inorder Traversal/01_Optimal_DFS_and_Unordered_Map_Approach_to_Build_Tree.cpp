// LeetCode (105. Construct Binary Tree from Preorder and Inorder Traversal): 
// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/


#include<vector> 
#include<unordered_map> 
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

    void createMapping(unordered_map<int, int> &mp, const vector<int> &inorder){

        int n = inorder.size(); 

        for(int i=0; i < n; i++){
            mp[inorder[i]] = i; 
        }

    }

    TreeNode* buildTreeUsingPreAndInOrder(vector<int> &preorder, int &i, vector<int> &inorder, int start, int end, unordered_map<int, int> &mp){

        if(start > end) return nullptr; 

        int data = preorder[i++];   
        TreeNode* root = new TreeNode(data); 

        int index = mp[data]; 

        root->left = buildTreeUsingPreAndInOrder(preorder, i, inorder, start, index - 1, mp); 
        root->right = buildTreeUsingPreAndInOrder(preorder, i, inorder, index + 1, end, mp); 

        return root; 
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        int n = preorder.size(); 
        int i = 0; 

        int start = 0; 
        int end = n-1; 

        unordered_map<int, int> mp; 
        createMapping(mp, inorder); 

        TreeNode* root = buildTreeUsingPreAndInOrder(preorder, i, inorder, start, end, mp); 

        return root; 
    }
}; 


// T.C. = O(n) 
// S.C. = O(n) + O(h) + O(n) = O(n) 

// Here, n = the total number of node values which are present inside the given input vector named "inorder / preorder", and h = the height of the given binary tree 