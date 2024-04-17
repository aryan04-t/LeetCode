// LeetCode (404. Sum of Left Leaves): 
// https://leetcode.com/problems/sum-of-left-leaves/ 


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

    int sumOfLeftLeaves(TreeNode* root) {

        int sum = 0; 

        queue<TreeNode*> q; 
        q.push(root); 

        while(!q.empty()){

            TreeNode* currNode = q.front(); 
            q.pop(); 

            if(currNode->left != nullptr){
                if(currNode->left->left == nullptr && currNode->left->right == nullptr){
                    sum += currNode->left->val; 
                }
            }

            if(currNode->left != nullptr) q.push(currNode->left);
            if(currNode->right != nullptr) q.push(currNode->right);

        }

        return sum; 
    }
};


// T.C. = O(n) 
// S.C. = O(m) 

// Here, n = the total number of nodes which are present inside the given binary tree, and m = the maximum number of nodes which are present at any level of the given binary tree 