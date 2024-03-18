// LeetCode (103. Binary Tree Zigzag Level Order Traversal): 
// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/ 


#include<vector> 
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

    void reverseVec(vector<int> &v){

        int n = v.size(); 
        int start = 0; 
        int end = n-1; 

        while(start < end){
            int temp = v[start]; 
            v[start++] = v[end]; 
            v[end--] = temp; 
        }

    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        if(root == nullptr) return {}; 

        queue<TreeNode*> q; 
        q.push(root); 

        int levelSize = q.size(); 
        vector<vector<int>> ans; 

        while(!q.empty()){

            levelSize = q.size(); 
            vector<int> currLevel; 

            for(int i=0; i < levelSize; i++){

                TreeNode* currNode = q.front(); 
                q.pop(); 

                currLevel.push_back(currNode->val); 

                if(currNode->left != nullptr) q.push(currNode->left);
                if(currNode->right != nullptr) q.push(currNode->right);

            }

            ans.push_back(currLevel); 
        }

        int noOfLevels = ans.size(); 

        for(int i=0; i < noOfLevels; i++){
            if(i&1){
                reverseVec(ans[i]);
            }
        }

        return ans; 

    }
};


// T.C. = O(n) + O(no/2) = O(n) 
// S.C. = O(n) + O(m) = O(n) 

// Here, no = the total number of nodes which are present at all odd levels of the given binary tree 
// n = the total number of nodes which are present in the given binary tree, and m = the maximum number of nodes which are present at any level of the given binary tree 