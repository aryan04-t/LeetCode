// LeetCode (1302. Deepest Leaves Sum): 
// https://leetcode.com/problems/deepest-leaves-sum/ 


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

    int getDepth(TreeNode* root){

        if(root == nullptr) return 0; 

        int leftDepth = getDepth(root->left); 
        int rightDepth = getDepth(root->right); 

        return max(leftDepth, rightDepth) + 1; 

    }

    void findSum(TreeNode* root, int &depth, int &sum){

        if(root == nullptr){
            depth++;
            return;
        }

        if(depth == 1){
            sum += root->val;
        }

        depth--; 
        findSum(root->left, depth, sum); 

        depth--; 
        findSum(root->right, depth, sum); 

        depth++; 

    }

    int deepestLeavesSum(TreeNode* root) {

        int depth = getDepth(root);
        int sum = 0;

        findSum(root, depth, sum); 

        return sum; 

    }

};


// T.C. = O(n) + O(n) = O(n) 
// S.C. = O(h) 

// Here, n = the total number of nodes which are present inside the given binary tree, and h = the height of the given binary tree 