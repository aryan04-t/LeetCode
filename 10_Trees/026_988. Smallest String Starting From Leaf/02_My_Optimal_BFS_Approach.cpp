// LeetCode (988. Smallest String Starting From Leaf): 
// https://leetcode.com/problems/smallest-string-starting-from-leaf/ 


#include<string> 
#include<queue> 
#include<utility> 
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

        string smallestFromLeaf(TreeNode* root) {

            queue<pair<TreeNode*, string>> q; 
            q.push({root, ""}); 

            string smallest = ""; 

            while(!q.empty()){

                pair<TreeNode*, string> p = q.front(); 
                q.pop(); 

                TreeNode* currNode = p.first; 
                string currStr = p.second; 

                currStr.push_back(char(currNode->val + 'a')); 

                if(currNode->left == nullptr && currNode->right == nullptr){
                    reverse(currStr.begin(), currStr.end()); 
                    if(smallest == "") smallest = currStr;
                    else{
                        if(currStr < smallest) smallest = currStr;
                    }
                    continue; 
                }

                if(currNode->left != nullptr) q.push({currNode->left, currStr}); 
                if(currNode->right != nullptr) q.push({currNode->right, currStr}); 
            }

            return smallest; 
        }
    };


    // T.C. = O((n+1)/2 * ( (h-1) + (h/2) + (h) )) + O( ((n+1)/4 * (h-2)) + ... + (2 * 1) + (1 * 0) ) = O(n*h) 
    // S.C. = O(m*h) + O(h) = O(m*h) 

    // Here, n = the total number of nodes which are present inside the given binary tree, 
    // h = the height of the given binary tree, 
    // and m = the maximum number of nodes which are present at any level of the given binary tree 