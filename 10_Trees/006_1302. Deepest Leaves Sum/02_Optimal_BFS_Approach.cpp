// LeetCode (1302. Deepest Leaves Sum): 
// https://leetcode.com/problems/deepest-leaves-sum/ 


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

    int deepestLeavesSum(TreeNode* root) {
              
        queue<TreeNode*> q; 
        q.push(root); 

        int levelSize = q.size();
        int sum = 0;

        while(!q.empty()){

            levelSize = q.size(); 
            sum = 0;

            for(int i=0; i < levelSize; i++){

                TreeNode* current = q.front(); 
                q.pop(); 

                sum += current->val; 

                if(current->left != nullptr){
                    q.push(current->left);
                }

                if(current->right != nullptr){
                    q.push(current->right);
                }

            }
        }

        return sum; 

    }

};


// T.C. = O(n) 
// S.C. = O(m) 

// Here, n = the total number of nodes present inside the given tree, and m = the maximum number of nodes which are present at any level of the given binary tree 