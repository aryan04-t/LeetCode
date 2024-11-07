// LeetCode (129. Sum Root to Leaf Numbers): 
// https://leetcode.com/problems/sum-root-to-leaf-numbers/ 


#include<queue> 
#include<utility> 
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

    int sumNumbers(TreeNode* root) {
        
        queue<pair<TreeNode*, int>> q; 
        q.push({root, 0}); 

        int sum = 0; 

        while(!q.empty()){

            pair<TreeNode*, int> p = q.front(); 
            q.pop(); 
            
            TreeNode* currNode = p.first; 
            int num = p.second; 

            num = num * 10 + currNode->val; 

            if(currNode->left == nullptr && currNode->right == nullptr){
                sum += num; 
                continue;
            }

            if(currNode->left != nullptr) q.push({currNode->left, num}); 
            if(currNode->right != nullptr) q.push({currNode->right, num}); 
        }

        return sum; 
    }
};


// T.C. = O(n) 
// S.C. = O(m) 

// Here, n = the total number of nodes which are present inside the given binary tree, 
// and m = the maximum number of nodes which are present at any level of the given binary tree 