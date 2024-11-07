// LeetCode (988. Smallest String Starting From Leaf): 
// https://leetcode.com/problems/smallest-string-starting-from-leaf/ 


#include<string> 
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

    void dfs(TreeNode* root, string curr, string &smallest){

        if(root == nullptr) return; 

        curr.push_back(char(root->val + 'a')); 

        if(root->left == nullptr && root->right == nullptr){
            reverse(curr.begin(), curr.end()); 
            if(smallest == "") smallest = curr; 
            else{
                if(curr < smallest) smallest = curr; 
                return; 
            }
        }

        dfs(root->left, curr, smallest); 
        dfs(root->right, curr, smallest); 
    }

    string smallestFromLeaf(TreeNode* root) {

        string curr; 
        string smallest = "";

        dfs(root, curr, smallest); 

        return smallest; 
    }
};


// T.C. = O((n+1)/2 * ( (h-1) + (h/2) + (h) )) + O( ((n+1)/4 * (h-2)) + ... + (2 * 1) + (1 * 0) ) = O(n*h) 
// S.C. = O((h * (h+1)) / 2) + O(h) = O(h^2) 

// Here, n = the total number of nodes which are present inside the given binary tree, 
// and h = the height of the given binary tree 