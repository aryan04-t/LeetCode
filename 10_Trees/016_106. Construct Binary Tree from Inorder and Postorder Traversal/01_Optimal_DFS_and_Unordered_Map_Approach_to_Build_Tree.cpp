// LeetCode (106. Construct Binary Tree from Inorder and Postorder Traversal): 
// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/ 


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

    TreeNode* buildTreeUsingPostAndInOrder(vector<int> &postorder, int &i, vector<int> &inorder, int start, int end, unordered_map<int, int> &mp){

        if(start > end) return nullptr; 

        int data = postorder[i--]; 
        TreeNode* root = new TreeNode(data); 

        int index = mp[data]; 

        root->right = buildTreeUsingPostAndInOrder(postorder, i, inorder, index + 1, end, mp); 
        root->left = buildTreeUsingPostAndInOrder(postorder, i, inorder, start, index - 1, mp); 

        return root; 

    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        int n = postorder.size(); 
        int i = n-1; 

        int start = 0; 
        int end = n-1; 

        unordered_map<int, int> mp; 
        createMapping(mp, inorder); 

        TreeNode* root = buildTreeUsingPostAndInOrder(postorder, i, inorder, start, end, mp); 

        return root; 

    }
};


// T.C. = O(n) 
// S.C. = O(n) + O(h) + O(n) = O(n) 

// Here, n = the total number of node values which are present inside the input vector named "inorder / postorder", and h = the height of the binary tree which is getting constructed 