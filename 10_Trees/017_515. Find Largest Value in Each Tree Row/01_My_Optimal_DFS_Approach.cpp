// LeetCode (515. Find Largest Value in Each Tree Row): 
// https://leetcode.com/problems/find-largest-value-in-each-tree-row/ 


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

    void getLargestValues(TreeNode* root, int height, map<int, int> &mp){

        if(root == nullptr) return; 

        map<int, int>::iterator it = mp.find(height); 

        if(it == mp.end()){
            mp[height] = root->val;
        }
        else{
            if(root->val > it->second){
                mp[height] = root->val; 
            }
        }

        getLargestValues(root->left, height+1, mp);
        getLargestValues(root->right, height+1, mp);

    }

    vector<int> largestValues(TreeNode* root) {

        int height = 0;
        map<int, int> mp;

        getLargestValues(root, height, mp); 

        vector<int> ans; 
        for(const pair<int, int> &p : mp){
            ans.push_back(p.second); 
        } 

        return ans; 
    }
};


// T.C. = O(n) 
// S.C. = O(h) + O(h) = O(h) 

// Here, n = the total number of node which are present inside the given binary tree, and h = the height of the given binary tree 