// LeetCode (987. Vertical Order Traversal of a Binary Tree): 
// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/ 


#include<map> 
#include<set> 
#include<utility>
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

    void traverse(TreeNode* root, int level, int horizontalDist, map<int, multiset<pair<int, int>>> &container){

        if(root == nullptr) return; 

        container[horizontalDist].insert({level, root->val});

        traverse(root->left, level + 1, horizontalDist - 1, container);  
        traverse(root->right, level + 1, horizontalDist + 1, container);  

    }


    vector<vector<int>> verticalTraversal(TreeNode* root) {

        int level = 0; 
        int horizontalDist = 0; 

        map<int, multiset<pair<int, int>>> container; 

        traverse(root, level, horizontalDist, container); 

        vector<vector<int>> ans; 
        
        for(const pair<int, multiset<pair<int, int>>> &p : container){ 
            
            vector<int> temp; 

            for(const pair<int, int> &setsPair : p.second){
                temp.push_back(setsPair.second); 
            }

            ans.push_back(temp);
        }

        return ans; 

    }
};