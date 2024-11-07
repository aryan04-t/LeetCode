// LeetCode (2331. Evaluate Boolean Binary Tree): 
// https://leetcode.com/problems/evaluate-boolean-binary-tree/ 


#include<stack> 
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

    bool evaluateTree(TreeNode* root) {
        
        stack<TreeNode*> st; 
        st.push(root); 

        while(!st.empty()){

            TreeNode* currNode = st.top(); 
            st.pop(); 

            if(currNode->val >= 2){
                if(currNode->left->val <= 1 && currNode->right->val <= 1){
                    if(currNode->val == 2) currNode->val = currNode->left->val || currNode->right->val; 
                    else if(currNode->val == 3) currNode->val = currNode->left->val && currNode->right->val; 
                }
                else{
                    st.push(currNode); 
                    if(currNode->right->val >= 2) st.push(currNode->right); 
                    if(currNode->left->val >= 2) st.push(currNode->left); 
                }
            } 
        }

        return root->val; 
    }
};


// T.C. = O(n) 
// S.C. = O(h) 

// Here, n = the total number of nodes which are present inside the given binary tree 
// and h = the height of the given binary tree, in worst case when the binary tree is skewed, h == n 