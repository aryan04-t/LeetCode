// LeetCode (515. Find Largest Value in Each Tree Row): 
// https://leetcode.com/problems/find-largest-value-in-each-tree-row/ 


#include<vector> 
#include<queue> 
#include<limits.h> 
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

    vector<int> largestValues(TreeNode* root) {

        if(root == nullptr) return {};

        queue<TreeNode*> q; 
        q.push(root); 

        int levelSize = 1; 
        vector<int> ans;

        while(!q.empty()){

            levelSize = q.size(); 
            int maxi = INT_MIN; 

            for(int i=0; i < levelSize; i++){
                
                TreeNode* currNode = q.front(); 
                q.pop();
                
                maxi = max(maxi, currNode->val);

                if(currNode->left != nullptr) q.push(currNode->left); 
                if(currNode->right != nullptr) q.push(currNode->right); 
            }

            ans.push_back(maxi); 
        }

        return ans; 

    }
};


// T.C. = O(n) 
// S.C. = O(m) + O(h) 

// Here, n = the total number of node which are present inside the given binary tree, m = the maximum number of nodes which are present at any level of the given binary tree, and h = the height of the given binary tree 