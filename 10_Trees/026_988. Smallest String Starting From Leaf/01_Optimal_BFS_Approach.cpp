// LeetCode (988. Smallest String Starting From Leaf): 
// https://leetcode.com/problems/smallest-string-starting-from-leaf/ 


#include<string> 
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

    string smallestFromLeaf(TreeNode* root) {
        
        queue<pair<TreeNode*, string>> q; 
        
        string temp; 
        temp.push_back(char(root->val + 'a')); 

        q.push({root, temp}); 
        string ans = ""; 

        while(!q.empty()){

            pair<TreeNode*, string> currPair = q.front(); 
            q.pop(); 

            TreeNode* currNode = currPair.first; 
            string temp = currPair.second; 

            if(currNode->left == nullptr && currNode->right == nullptr){
                reverse(temp.begin(), temp.end()); 
                if(ans == ""){
                    ans = temp; 
                }
                else{
                    if(temp < ans){
                        ans = temp; 
                    }
                }
            }

            bool left = false; 

            if(currNode->left != nullptr){
                if(!left) left = true;
                temp.push_back(char(currNode->left->val + 'a')); 
                q.push({currNode->left, temp}); 
            }
            if(currNode->right != nullptr){
                if(left) temp.pop_back();
                temp.push_back(char(currNode->right->val + 'a')); 
                q.push({currNode->right, temp}); 
            }
        }

        return ans; 
    }
};


// T.C. = O( ((n+1)/2 * h) + ((n+1)/4 * (h-1)) + ... + (1 * 1) ) = O(n*h) 
// S.C. = O(m*h) 

// Here, n = the total number of nodes which are present inside the given binary tree, h = the height of the given binary tree 
// and m = the maximum number of nodes which are present at any level of the given binary tree 