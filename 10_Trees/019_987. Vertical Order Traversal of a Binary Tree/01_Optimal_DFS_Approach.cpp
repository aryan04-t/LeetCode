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

    void findVerticalTraversal(TreeNode* root, int level, int horizontalDist, map<int, multiset<pair<int, int>>> &container){

        if(root == nullptr) return; 

        container[horizontalDist].insert({level, root->val}); 

        findVerticalTraversal(root->left, level + 1, horizontalDist - 1, container);
        findVerticalTraversal(root->right, level + 1, horizontalDist + 1, container);

    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {

        int level = 0; 
        int horizontalDist = 0; 
        
        map<int, multiset<pair<int, int>>> container; 
        findVerticalTraversal(root, level, horizontalDist, container); 

        vector<vector<int>> ans; 
        
        for(const pair<int, multiset<pair<int,int>>> &p1 : container){
            
            vector<int> temp;

            for(const pair<int, int> &p2: p1.second){
                temp.push_back(p2.second); 
            }

            ans.push_back(temp); 
        }

        return ans; 
    }
};


// T.C. = O(n) + O(n * (log(hd) to the base 2) * (log(k) to the base 2)) = O(n * log(hd) * log(k)) 
// S.C. = O(h) + O(n) + O(n) = O(n) 

// Here, n = the total number of nodes which are present inside the given binary tree, and h = the height of the given binary tree 
// hd = the total number of unique horizontal distance values which are present in the given binary tree, and k = the maximum number of nodes which are present at any given horizontal distance in the given binary tree 