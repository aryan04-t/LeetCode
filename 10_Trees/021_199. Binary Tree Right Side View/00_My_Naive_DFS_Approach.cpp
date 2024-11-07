// LeetCode (199. Binary Tree Right Side View): 
// leetcode.com/problems/binary-tree-right-side-view/ 


#include<vector> 
#include<map> 
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

    void getRightView(TreeNode* root, int level, map<int, int> &mp){

        if(root == nullptr) return; 

        if(mp.find(level) == mp.end()){
            mp[level] = root->val; 
        }

        getRightView(root->right, level + 1, mp); 
        getRightView(root->left, level + 1, mp); 
    }

    vector<int> rightSideView(TreeNode* root) {

        map<int, int> mp; 
        int level = 0;
        
        getRightView(root, level, mp);
        
        vector<int> ans; 
        for(const pair<int, int> &p : mp){
            ans.push_back(p.second); 
        }
        
        return ans;
    }
};


// T.C. = O(n * (log(h) + log(h))) = O(n * log(h)) 
// S.C. = O(h) + O(n) + O(n) = O(n) 

// Here, n = the total number of nodes which are present inside the given binary tree, and h = the height of the given binary tree 
// In worst case h == n, when the binary tree is a skewed binary tree 