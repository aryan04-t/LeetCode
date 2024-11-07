// LeetCode (106. Construct Binary Tree from Inorder and Postorder Traversal): 
// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/ 


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

    int findIndex(int data, const vector<int> &inorder){

        int n = inorder.size();

        for(int i=0; i < n; i++){
            if(inorder[i] == data){
                return i;
            }
        }

        return -1;

    }

    TreeNode* buildTreeUsingPostAndInOrder(vector<int> &postorder, int &i, vector<int> &inorder, int start, int end){

        if(start > end) return nullptr; 

        int data = postorder[i--]; 
        TreeNode* root = new TreeNode(data); 

        int index = findIndex(data, inorder); 

        root->right = buildTreeUsingPostAndInOrder(postorder, i, inorder, index + 1, end); 
        root->left = buildTreeUsingPostAndInOrder(postorder, i, inorder, start, index - 1); 

        return root; 

    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        int n = postorder.size(); 
        int i = n-1; 

        int start = 0; 
        int end = n-1; 

        TreeNode* root = buildTreeUsingPostAndInOrder(postorder, i, inorder, start, end); 

        return root; 

    }
};


// T.C. = O( (n * (n+1)) / 2) = O(n^2) 
// S.C. = O(h) + O(n) = O(n) 

// Here, n = the total number of node values which are present inside the input vector named "inorder / postorder", and h = the height of the binary tree which is getting constructed 