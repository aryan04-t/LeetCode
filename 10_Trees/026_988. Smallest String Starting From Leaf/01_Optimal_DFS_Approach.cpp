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

    void dfs(TreeNode* root, string &temp, string &ans){

        if(root == nullptr) return; 

        temp.push_back(char(root->val + 'a')); 

        if(root->left == nullptr && root->right == nullptr){
            
            string revTemp = temp; 
            reverse(revTemp.begin(), revTemp.end()); 

            if(ans == ""){
                ans = revTemp; 
            }
            else{
                if(revTemp < ans){
                    ans = revTemp; 
                }
            }
        }
        
        dfs(root->left, temp, ans); 
        dfs(root->right, temp, ans); 

        temp.pop_back(); 
    }

    string smallestFromLeaf(TreeNode* root) {
        
        string temp; 
        string ans = ""; 

        dfs(root, temp, ans); 

        return ans; 
    }
};


// T.C. = O(((n+1)/2) - 1) * O(1)) + O(((n+1)/2) * O(m/2)) = O(n*m) = O(n*h) 
// S.C. = O(h) + O(h) + O(h) + O(h) = (s.c. caused by the function call stack) + (s.c. caused by the "temp" string) + (s.c. caused by the "revTemp" string) + (s.c. caused by the "ans" string) = O(h) 

// Here, n = the total number of nodes which are present inside the given binary tree, h = the height of the given binary tree 
// and m = to the average length of all the root to leaf node strings, and in worst case m == h 